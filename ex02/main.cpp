/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:25:39 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/22 18:12:21 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <ctime>
#include <cstdlib>

static void	printStats(const ClapTrap& ct)
{
	std::cout << ct.getName()
			<< " HP:     " << ct.getHitPoints()
			<< " EP:     " << ct.getEnergyPoints()
			<< " Attack: "<< ct.getAttackDamage() <<std::endl;
}

int main(void)
{
	int max_turn = 10;
	std::cout << "\n---Simulation start...---\n";
	ClapTrap alpha;
	alpha.setName("Alpha");
	FragTrap omega("omega");
	std::cout << "\n--- Initial Stats ---\n";
	printStats(alpha);
	printStats(omega);
	std::cout << "\n--- Fight Start ---\n";
	std::srand(std::time(0));
	for (int turn = 1; turn <= max_turn; turn++)
	{
		int random_num = std::rand() % 1000 + 1;
		std::cout << "\n[TURN " << turn << " " << random_num << "]\n";
		if (random_num  % 5 == 0 && random_num  % 2 == 0)
		{
			if (omega.getHitPoints() > 0)
			{
				if (omega.getHitPoints() < 30 && omega.getEnergyPoints() > 0)
					omega.beRepaired(3);
				else if (omega.getEnergyPoints() > 0 && omega.getHitPoints() < 30)
				{
					omega.attack(alpha.getName());
					alpha.takeDamage(omega.getAttackDamage());
				}
			}
		}
		else
		{
			if (alpha.getEnergyPoints() > 0 && alpha.getHitPoints() > 0)
			{
				alpha.attack(omega.getName());
				omega.takeDamage(alpha.getAttackDamage());
			}
		}
		printStats(alpha);
		printStats(omega);
		if (alpha.getHitPoints() <= 0 || omega.getHitPoints() <= 0)
			break;
	}
	if (omega.getHitPoints() > 0)
	{
		omega.beRepaired(3);
		omega.highFivesGuys();
	}
	std::cout << "\n--- Final Stats ---\n";
	printStats(alpha);
	printStats(omega);

	std::cout << "\n--- Scope Destruction Test ---\n";
	{
		FragTrap temp("Temp");
		printStats(temp);
	}
	std::cout << "\n--- Copy Constructor Test ---\n";
	ClapTrap clone(omega);
	std::cout << "Clone of " << alpha.getName()
			<< " HP: " << clone.getHitPoints() << std::endl;
	std::cout << "\n--- Assignment Operator Test ---\n";
	FragTrap omegaClone("OmegaClone");
	clone = omegaClone;
	std::cout << "Clone now copied from " << omegaClone.getName()
			<< " HP: " << clone.getHitPoints() << std::endl;
	std::cout << "\n--- Edge Case Test ---\n";
	omega.setHitPoints(0);
	omega.attack("Ghost");
	omega.highFivesGuys();
	std::cout << "\n---Simulation end.---\n";
	return 0;
}
