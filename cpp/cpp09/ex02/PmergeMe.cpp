/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:54:50 by ebenoist          #+#    #+#             */
/*   Updated: 2026/02/05 17:58:26 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}
PmergeMe& PmergeMe::operator= (const PmergeMe &other){
	if(this != &other){
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}
PmergeMe::~PmergeMe(){}

void	PmergeMe::ParseDisplay(int ac, char **av){
	for (int i = 1 ; i < ac ; i++){
		std::string line = av[i];
		if (line.empty())
			throw std::invalid_argument("Error : Argument is empty\n");
		for(size_t j = 0; j < line.size(); j++){
			if ((!isdigit(line[j])))
				throw std::invalid_argument("Error : Put only number, no negatif");}
		long val = std::atol(line.c_str());
		if (val > std::numeric_limits<int>::max())
			throw std::invalid_argument("Error: Number too large");
		for (size_t k = 0; k < _vec.size(); k++) {
			if (_vec[k].value == static_cast<int>(val)) {
				std::cerr << "Probleme is this number -> " << val << std::endl;
				throw std::invalid_argument("Error : Not enter the same number twice");
			}
		}
		Element el;
		el.value = static_cast<int>(val);
		_vec.push_back(el);
		_deq.push_back(el);
	}
	std::cout << "Before: " ;
	for (int i = 1; i < ac ; i++)
		std::cout << av[i] << " ";
	std::cout << " \n";
}

std::vector<int> PmergeMe::buildJacobsthalSequence(int n) {
	std::vector<int> seq;
	if (n <= 0) return seq;
	seq.push_back(1);
	if (n == 1) return seq;
	seq.push_back(3);
	while (seq.back() < n) {
		int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
		seq.push_back(next);
	}
	return seq;
}
/*
template <typename Container, typename ContainerElements>
static void insertBinary(Container& dest, const ContainerElements& value) {
	typename Container::iterator it = std::lower_bound(dest.begin(), dest.end(), value);
	dest.insert(it, value);
}*/

static double getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void PmergeMe::sortVector() {
	double start = getCurrentTime();
	fordJohnson(_vec);
	double end = getCurrentTime();
	_vecTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::sortDeqeu() {
	double start = getCurrentTime();
	fordJohnson(_deq);
	double end = getCurrentTime();
	_deqTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

template <typename ContainerElement>
void PmergeMe::fordJohnson(ContainerElement& elements) {
	if (elements.size() <= 1) return;
	std::vector<std::pair<int, int> > pairs;
	int orphan = -1;
	bool hasOrphan = (elements.size() % 2 != 0);
	if (hasOrphan) {
		orphan = elements[elements.size() - 1].value;
		elements.pop_back();
	}
	// creer les paires
	for (size_t i = 0; i < elements.size(); i += 2) {
		int val1 = elements[i].value;
		int val2 = elements[i + 1].value;
		if (val1 > val2) {
			pairs.push_back(std::make_pair(val1, val2));
		} else {
			pairs.push_back(std::make_pair(val2, val1));
		}
	}
	// extraire les gagnants pour le tri recursif
	ContainerElement winners;
	for (size_t i = 0; i < pairs.size(); ++i) {
		typename ContainerElement::value_type w;
		w.value = pairs[i].first;
		winners.push_back(w);
	}
	// trier recursivement les gagnants
	fordJohnson(winners);
	// reorganiser les paires, que chaque gagnant, trier, garde son losser d origine
	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < winners.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (pairs[j].first == winners[i].value) {
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	ContainerElement mainChain;
	// inserer le premier perdant
	if (!sortedPairs.empty()) {
		typename ContainerElement::value_type firstLoser;
		firstLoser.value = sortedPairs[0].second;
		mainChain.push_back(firstLoser);
	}
	// ajouter tous les gagnants
	for (size_t i = 0; i < winners.size(); ++i) {
		mainChain.push_back(winners[i]);
	}
	// preparer les perdants restants pour insertion
	ContainerElement pendToInsert;
	for (size_t i = 1; i < sortedPairs.size(); ++i) {
		typename ContainerElement::value_type loser;
		loser.value = sortedPairs[i].second;
		pendToInsert.push_back(loser);
	}	
	if (hasOrphan) {
		typename ContainerElement::value_type orph;
		orph.value = orphan;
		pendToInsert.push_back(orph);
	}
	// insertion avec sequence de jacob
	if (!pendToInsert.empty()) {
		std::vector<int> JacobSequence = buildJacobsthalSequence(pendToInsert.size());
		size_t lastInserted = 0;
		for (size_t k = 0; k < JacobSequence.size(); ++k) {
			size_t targetIdx = JacobSequence[k];
			if (targetIdx > pendToInsert.size()) targetIdx = pendToInsert.size();
			// insertion en marche arriere, pour ne pas perdre les index sur la main
			for (size_t i = targetIdx; i > lastInserted; --i) {
				typename ContainerElement::iterator it = std::lower_bound(
					mainChain.begin(), mainChain.end(), pendToInsert[i-1]
				);
				mainChain.insert(it, pendToInsert[i-1]);
			}
			lastInserted = targetIdx;
		}
	}
	elements = mainChain;
}

void	PmergeMe::CheckDisplay(){
	std::cout << "After : " ;
	for (size_t i = 0; i < _deq.size(); i++){
		std::cout << _deq[i].value;
		if (i < _deq.size() - 1)
			std::cout << " ";
	}
	std::cout << "\nTime to process a range of " << _deq.size() << " elements with std::deque : " << _deqTime << " us";
	std::cout << "\nTime to process a range of " << _vec.size() << " elements with std::vector : " << _vecTime << " us" << std::endl;
}
