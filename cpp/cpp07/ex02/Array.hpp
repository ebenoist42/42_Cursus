/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:08:54 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/08 17:02:51 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>

template <typename T>
class Array{
	public : 
		Array(): array(NULL), elem(0){}
		Array(unsigned int n) : array(new T[n]()), elem(n) {}
		Array(const Array &other) : array(NULL), elem(0){
			if(other.elem > 0){
				this->elem = other.elem;
				this->array = (new T[this->elem]);
				for (unsigned int i = 0; i < this->elem; i++)
				array[i] = other.array[i];}
		}
		Array& operator= (const Array &other){
			if (this != &other) {
				delete[] this->array;
				this->elem = other.elem;
				if(this->elem > 0){
					this->array = (new T[this->elem]);
				for (size_t i = 0; i < other.elem; i++)
					array[i] = other.array[i];}
				else
					this->array = NULL;
			}
			return *this;
		}
		~Array(){
			delete[] array;
		}
		unsigned int size() const{
			return this->elem;
		}
		const T& operator[](unsigned int index) const{
			if(index >= elem)
				throw std::out_of_range ("index out of size ");
			return this->array[index];
		}
		T& operator[](unsigned int index){
			if(index >= elem)
				throw std::out_of_range ("index out of size ");
			return this->array[index];
		}
	private :
		T *array;
		size_t elem;
};

#endif