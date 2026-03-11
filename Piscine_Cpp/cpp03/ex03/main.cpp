/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:57:50 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/07 19:02:17 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <string>


int main() {

    std::cout << "--- Test DiamondTrap ---" << std::endl;
    DiamondTrap d1("Diamondy");

    d1.attack("Target");     // doit appeler ScavTrap::attack
    d1.highFivesGuys();      // vient de FragTrap
    d1.guardGate();          // vient de ScavTrap
    d1.whoAmI();             // test du double nom

    std::cout << "\n--- Test Copy & Assign ---" << std::endl;
    DiamondTrap d2(d1);      // test copie
    d2.whoAmI();

    DiamondTrap d3("Another");
    d3 = d1;                 // test opérateur =
    d3.whoAmI();

    std::cout << "\n--- Test dégâts/réparations ---" << std::endl;
    d1.takeDamage(30);
    d1.beRepaired(10);

    return 0;
}