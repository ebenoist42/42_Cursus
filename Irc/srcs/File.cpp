#include "../includes/File.hpp"
#include "../includes/Server.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

FileTransfer::FileTransfer() {}
FileTransfer::~FileTransfer() {}

bool	FileTransfer::sendFile(int senderFd, int receiverFd, const std::string &filepath, size_t size)
{
	if (size == 0)
		return (false);

	std::string filename = filepath;
	size_t lastSlash = filepath.find_last_of("/\\");
	if (lastSlash != std::string::npos)
		filename = filepath.substr(lastSlash + 1);

	s_FileTransfer	transfer;
	transfer.senderFd = senderFd;
	transfer.receiverFd = receiverFd;
	transfer.filename = filename;
	transfer.senderPath = filepath;
	transfer.receiverPath = "received_" + filename;
	transfer.bytes = size;
	transfer.totalBytes = size;
	transfer.status = false;
	transfer.fileFd = -1;

	_transfers[senderFd] = transfer;
	std::cout << "FILE TRANSFER: Session created for " << filepath << std::endl;
	return (true);
}

bool	FileTransfer::acceptFile(int senderFd, int receiverFd, const std::string &filename)
{
	std::map<int, s_FileTransfer>::iterator	it = _transfers.find(senderFd);
	if (it == _transfers.end())
	{
		std::cout << "FILE TRANSFER: No session found" << std::endl;
		return (false);
	}

	if (it->second.receiverFd != receiverFd || it->second.filename != filename)
	{
		std::cout << "FILE TRANSFER: Mismatch" << std::endl;
		return (false);
	}

	it->second.fileFd = open(it->second.receiverPath.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (it->second.fileFd < 0)
	{
		std::cout << "FILE TRANSFER: Cannot create file " << it->second.receiverPath << std::endl;
		return (false);
	}

	std::cout << "FILE TRANSFER: Accepted! Saving to " << it->second.receiverPath << std::endl;
	it->second.status = true;
	return (true);
}

bool	FileTransfer::handleData(Server &, int fd, std::string &readBuff)
{
	// this is for manual data transfer, not for automatic filetransfer
	std::map<int, s_FileTransfer>::iterator	it;
	for (it = _transfers.begin(); it != _transfers.end(); ++it)
	{
		if (it->second.receiverFd == fd && it->second.status == true && it->second.fileFd >= 0)
			break;
	}
	
	if (it == _transfers.end())
		return (false);

	std::cout << "FILE TRANSFER: handleData for receiver fd " << fd << " (manual mode)" << std::endl;

	size_t	sendBytes = readBuff.size();
	if (sendBytes == 0)
		return (true);
	if (sendBytes > it->second.bytes)
		sendBytes = it->second.bytes;

	std::string	chunk = readBuff.substr(0, sendBytes);
	readBuff.erase(0, sendBytes);
	it->second.bytes -= sendBytes;

	// write to file
	if (it->second.fileFd >= 0)
	{
		ssize_t written = write(it->second.fileFd, chunk.c_str(), chunk.size());
		if (written < 0)
		{
			std::cout << "FILE TRANSFER: Write error!" << std::endl;
			close(it->second.fileFd);
			_transfers.erase(it);
			return (true);
		}
		std::cout << "FILE TRANSFER: Wrote " << written << " bytes, " << it->second.bytes << " remaining" << std::endl;
	}

	if (it->second.bytes == 0)
	{
		std::cout << "FILE TRANSFER: Complete! File saved as " << it->second.receiverPath << std::endl;
		if (it->second.fileFd >= 0)
			close(it->second.fileFd);
		_transfers.erase(it);
	}
	return (true);
}

void	FileTransfer::startSending(Server &, int senderFd)
{
	std::map<int, s_FileTransfer>::iterator	it = _transfers.find(senderFd);
	if (it == _transfers.end() || !it->second.status)
		return;

	std::cout << "FILE TRANSFER: Starting automatic transfer of " << it->second.senderPath << std::endl;

	int srcFd = open(it->second.senderPath.c_str(), O_RDONLY);
	if (srcFd < 0)
	{
		std::cout << "FILE TRANSFER: Cannot open source file for reading!" << std::endl;
		return;
	}

	if (it->second.fileFd < 0)
	{
		std::cout << "FILE TRANSFER: Destination file not open!" << std::endl;
		close(srcFd);
		return;
	}

	char buffer[4096];
	ssize_t bytesRead;
	size_t totalCopied = 0;

	while ((bytesRead = read(srcFd, buffer, sizeof(buffer))) > 0 && totalCopied < it->second.totalBytes)
	{
		size_t toWrite = bytesRead;
		if (totalCopied + toWrite > it->second.totalBytes)
			toWrite = it->second.totalBytes - totalCopied;
		
		ssize_t written = write(it->second.fileFd, buffer, toWrite);
		if (written < 0)
		{
			std::cout << "FILE TRANSFER: Write error!" << std::endl;
			break;
		}
		
		totalCopied += written;
		std::cout << "FILE TRANSFER: Copied " << written << " bytes (" << totalCopied << "/" << it->second.totalBytes << ")" << std::endl;
	}

	close(srcFd);
	close(it->second.fileFd);
	it->second.fileFd = -1;
	
	std::cout << "FILE TRANSFER: Complete! File saved as " << it->second.receiverPath << std::endl;
	_transfers.erase(it);
}

void	FileTransfer::cancelTransfer(int fd)
{
	std::map<int, s_FileTransfer>::iterator	it = _transfers.begin();
	while (it != _transfers.end())
	{
		if (it->second.senderFd == fd || it->second.receiverFd == fd)
		{
			std::map<int, s_FileTransfer>::iterator	removeit = it;
			it++;
			_transfers.erase(removeit);
		}
		else
			it++;
	}
}
