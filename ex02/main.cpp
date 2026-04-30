/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:25:39 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 11:05:12 by hfandres         ###   ########.fr       */
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
			<< " HP:    " << ct.getHitPoints()
			<< " EP:    " << ct.getEnergyPoints()
			<< " Attack:"<< ct.getAttackDamage() <<std::endl;
}

int main(void)
{
	int max_turn = 5;
	std::cout << "\n---Simulation start...---\n";
	ClapTrap alpha;
	alpha.setName("Alpha");
	ScavTrap beta;
	FragTrap omega("omega");
	std::cout << "\n--- Initial Stats ---\n";
	printStats(alpha);
	printStats(beta);
	printStats(omega);
	std::cout << "\n--- Fight Start ---\n";
	std::srand(std::time(0));
	for (int turn = 1; turn <= max_turn; turn++)
	{
		int random_num = std::rand() % 1000 + 1;
		std::cout << "\n[TURN " << turn << " " << random_num << "]\n";
		if (random_num % 2 == 0)
		{
			if (alpha.getEnergyPoints() > 0 && alpha.getHitPoints() > 0)
			{
				alpha.attack(beta.getName());
				beta.takeDamage(alpha.getAttackDamage());
			}
		}
		else
		{
			if (beta.getHitPoints() > 0)
			{
				if (beta.getHitPoints() < 50 && beta.getEnergyPoints() > 0)
					beta.guardGate();
				if (beta.getHitPoints() < 30 && beta.getEnergyPoints() > 0)
					beta.beRepaired(3);
				else if (beta.getEnergyPoints() > 0)
				{
					beta.attack(alpha.getName());
					alpha.takeDamage(beta.getAttackDamage());
				}
			}
		}
		printStats(alpha);
		printStats(beta);
		if (alpha.getHitPoints() <= 0 || beta.getHitPoints() <= 0)
			break;
	}
	if (omega.getHitPoints() > 0)
	{
		omega.guardGate();
		omega.beRepaired(3);
		omega.highFivesGuys();
	}
	std::cout << "\n--- Final Stats ---\n";
	printStats(alpha);
	printStats(beta);
	std::cout << "\n--- ScavTrap Copy/Assign Test ---\n";
	ScavTrap bof("bof");
	ScavTrap delta(omega);
	ScavTrap epsilon;
	epsilon = bof;
	printStats(bof);
	printStats(delta);
	printStats(epsilon);
	std::cout << "\n--- Scope Destruction Test ---\n";
	{
		FragTrap temp("Temp");
		printStats(temp);
	}
	std::cout << "\n--- Copy Constructor Test ---\n";
	ClapTrap clone(alpha);
	std::cout << "Clone of " << alpha.getName()
			<< " HP: " << clone.getHitPoints() << std::endl;
	std::cout << "\n--- Assignment Operator Test ---\n";
	clone = beta;
	std::cout << "Clone now copied from " << beta.getName()
			<< " HP: " << clone.getHitPoints() << std::endl;
	std::cout << "\n--- Edge Case Test ---\n";
	omega.setHitPoints(0);
	omega.attack("Ghost");
	omega.guardGate();
	omega.highFivesGuys();
	std::cout << "\n---Simulation end.---\n";
	return 0;
}
