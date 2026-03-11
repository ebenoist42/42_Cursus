#ifndef FILE_HPP
#define FILE_HPP

#include <map>
#include <string>

class Server;

struct	s_FileTransfer {
	int			senderFd;
	int			receiverFd;
	std::string	filename;
	std::string	senderPath;
	std::string	receiverPath;
	size_t		bytes;
	size_t		totalBytes;
	bool		status;
	int			fileFd;

	s_FileTransfer() : senderFd(-1), receiverFd(-1), filename(), senderPath(), receiverPath(), 
		bytes(0), totalBytes(0), status(false), fileFd(-1) {}
};

class	FileTransfer {
	public:
		FileTransfer();
		~FileTransfer();

		bool	sendFile(int senderFd, int receiverFd, const std::string &filename, size_t size);
		bool	acceptFile(int senderFd, int receiverFd, const std::string &filename);
		bool	handleData(Server &server, int fd, std::string &readBuff);
		void	startSending(Server &server, int senderFd);
		void	cancelTransfer(int fd);


	private:
		std::map<int, s_FileTransfer> _transfers;
};

#endif