/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:25:39 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/29 13:27:56 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

static void	printStats(const ClapTrap& ct)
{
	std::cout << ct.getName() << " HP: " << ct.getHitPoints()
			<< " EP: " << ct.getEnergyPoints() << std::endl;
}

int main(void)
{
	ClapTrap alpha("Alpha");
	ClapTrap beta("Beta");
	std::cout << "\n--- Initial Stats ---\n";
	std::cout << alpha.getName() << " HP: " << alpha.getHitPoints()
			<< " EP: " << alpha.getEnergyPoints() << std::endl;
	std::cout << beta.getName() << " HP: " << beta.getHitPoints()
			<< " EP: " << beta.getEnergyPoints() << std::endl;
	alpha.setAttackDamage(4);
	beta.setAttackDamage(4);
	std::cout << "\n--- Fight Start ---\n";
	for (int turn = 1; turn <= 5; turn++)
	{
		std::cout << "\n[TURN " << turn << "]\n";
		if (alpha.getEnergyPoints() > 0 && alpha.getHitPoints() > 0)
		{
			alpha.attack(beta.getName());
			beta.takeDamage(alpha.getAttackDamage());
		}
		if (beta.getHitPoints() > 0)
		{
			if (beta.getHitPoints() < 5 && beta.getEnergyPoints() > 0)
				beta.beRepaired(3);
			else if (beta.getEnergyPoints() > 0)
			{
				beta.attack(alpha.getName());
				alpha.takeDamage(beta.getAttackDamage());
			}
		}
		printStats(alpha);
		printStats(beta);
		if (alpha.getHitPoints() <= 0 || beta.getHitPoints() <= 0)
			break;
	}
	std::cout << "\n--- Final Stats ---\n";
	printStats(alpha);
	printStats(beta);
	std::cout << "\n--- Copy Constructor Test ---\n";
	ClapTrap clone(alpha);
	std::cout << "Clone of " << alpha.getName()
			<< " HP: " << clone.getHitPoints() << std::endl;
	std::cout << "\n--- Assignment Operator Test ---\n";
	clone = beta;
	std::cout << "Clone now copied from " << beta.getName()
			<< " HP: " << clone.getHitPoints() << std::endl;
	std::cout << "\n--- Edge Case Test ---\n";
	alpha.setHitPoints(0);
	alpha.attack("Ghost");
	alpha.beRepaired(5);
	return 0;
}
