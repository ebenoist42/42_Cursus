/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:57:50 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/06 18:54:21 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n--- Test basique ClapTrap ---\n";
    ClapTrap a("");

    a.attack("target1");
    a.takeDamage(5);
    a.beRepaired(3);

    std::cout << "\n--- Test épuisement énergie ClapTrap ---\n";
    for (int i = 0; i < 15; i++)
        a.attack("dummy");

    std::cout << "\n--- Test mort ClapTrap ---\n";
    a.takeDamage(100);
    a.beRepaired(10); // ne devrait rien faire

    std::cout << "\n----------------------------\n";
    std::cout << "--- Test ScavTrap complet ---\n";
    std::cout << "----------------------------\n";

    ScavTrap s("Scavy");

    s.attack("Brutus");        // version override
    s.takeDamage(20);
    s.beRepaired(10);

    std::cout << "\n--- Test mode Gate Keeper ---\n";
    s.guardGate();

    std::cout << "\n--- Test épuisement énergie ScavTrap ---\n";
    for (int i = 0; i < 60; i++)
        s.attack("Training Dummy");

    std::cout << "\n--- Test mort ScavTrap ---\n";
    s.takeDamage(500);
    s.beRepaired(20); // impossible, HP = 0

    std::cout << "\nFin des tests.\n";

    return 0;
}

