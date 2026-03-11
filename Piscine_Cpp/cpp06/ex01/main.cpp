/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:20:06 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/05 15:28:41 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main ()
{
	Data a = {42, 42.897f, 42.0420, 'A'};

	uintptr_t raw = Serializer::serialize(&a);
	std::cout << "Serialized data: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized data: "
			  << "i=" << deserializedData->i << ", "
			  << "f=" << deserializedData->f << ", "
			  << "d=" << deserializedData->d << ", "
			  << "c=" << deserializedData->c << std::endl;

	return 0;
}