/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:25:39 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/11 11:09:53 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <ctime>
#include <cstdlib>

int main(void)
{
	{
		int max_turn = 10;
		std::cout << "\n---Simulation start...---\n";
		ScavTrap alpha;
		alpha.setName("Alpha");
		FragTrap omega("omega");
		std::cout << "\n--- Initial Stats ---\n";
		std::cout << alpha << std::endl;
		std::cout << omega << std::endl;
		std::cout << "\n--- Fight Start ---\n";
		std::srand(std::time(0));
		for (int turn = 1; turn <= max_turn; turn++)
		{
			int random_num = std::rand() % 100 + 1;
			std::cout << "\n[TURN " << turn << " " << random_num << "]\n";
			if (random_num  % 5 == 0 && random_num  % 2 == 0)
			{
				omega.beRepaired(3);
				omega.highFivesGuys();
				omega.attack(alpha.getName());
				if (omega.getEnergyPoints() > 0 && omega.getHitPoints() > 0)
					alpha.takeDamage(omega.getAttackDamage());
			std::cout << "----------------------------------" << std::endl;
			}
			else
			{
				alpha.attack(omega.getName());
				if (alpha.getEnergyPoints() > 0 && alpha.getHitPoints() > 0)
					omega.takeDamage(alpha.getAttackDamage());
			}
			std::cout << "----------------------------------" << std::endl;
			std::cout << alpha << std::endl;
			std::cout << omega << std::endl;
			std::cout << "==================================\n" << std::endl;
		}
		std::cout << "\n--- Final Stats ---\n";
		std::cout << alpha << std::endl;
		std::cout << omega << std::endl;
	}
	std::cout << "==================================\n" << std::endl;
	std::cout << "==================================\n" << std::endl;
	{
		ClapTrap alpha("Alpha");
		FragTrap omega("omega");
		std::cout << "\n--- Scope Destruction Test ---\n";
		{
			FragTrap temp("Temp");
			std::cout << temp << std::endl;
		}
		std::cout << "\n--- Copy Constructor Test ---\n";
		ClapTrap clone(omega);
		std::cout << "clone : " << clone << std::endl;
		std::cout << "omega : " << omega << std::endl;
		std::cout << "\n--- Assignment Operator Test ---\n";
		FragTrap omegaClone("OmegaClone");
		clone = omegaClone;
		std::cout << "clone : " << clone << std::endl;
		std::cout << "omegaClone : " << omegaClone << std::endl;
		std::cout << "\n--- Edge Case Test ---\n";
		std::cout << omega << std::endl;
		omega.beRepaired(1);
		std::cout << "beRepaired : "<< omega << std::endl;
		omega.setEnergyPoints(0);
		std::cout << "setEnergyPoints : "<< omega << std::endl;
		omega.highFivesGuys();
		std::cout << omega << std::endl;
		omega.setEnergyPoints(20);
		std::cout << "setEnergyPoints : "<< omega << std::endl;
		omega.setHitPoints(0);
		std::cout << "setHitPoints : "<< omega << std::endl;
		omega.attack("Ghost");
		std::cout << omega << std::endl;
		omega.highFivesGuys();
		omega.setHitPoints(0);
		std::cout << "setHitPoints : " << omega << std::endl;
		omega.attack("Ghost");
		omega.highFivesGuys();
		omega.beRepaired(5);
		omega.takeDamage(5);
		omega.setHitPoints(10);
		std::cout << "setHitPoints : " << omega << std::endl;
		omega.setEnergyPoints(0);
		std::cout << "setEnergyPoints : " << omega << std::endl;
		omega.attack("Ghost");
		omega.highFivesGuys();
		omega.beRepaired(5);
		omega.takeDamage(5);
		std::cout << "\n---Simulation end.---\n";
	}
	return 0;
}
