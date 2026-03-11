/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:57:50 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/07 17:03:10 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n--- Test ClapTrap ---" << std::endl;
    ClapTrap c1("Clappy");
    c1.attack("Target1");
    c1.takeDamage(5);
    c1.beRepaired(3);

    std::cout << "\n--- Test ScavTrap ---" << std::endl;
    ScavTrap s1("Scavy");
    s1.attack("Bandit");
    s1.guardGate();   // compétence spéciale

    std::cout << "\n--- Test FragTrap ---" << std::endl;
    FragTrap f1("Fraggy");
    f1.attack("Boss");
    f1.highFivesGuys(); // compétence spéciale

    std::cout << "\n--- Test comportement énergie ---" << std::endl;
    for (int i = 0; i < 15; i++)
        f1.attack("Training Dummy");

    std::cout << "\n--- Test mort FragTrap ---" << std::endl;
    f1.takeDamage(150);   // Doit tomber à 0 HP
    f1.beRepaired(10);    // Impossible car mort

    std::cout << "\nFin des tests.\n" << std::endl;
    return 0;
}