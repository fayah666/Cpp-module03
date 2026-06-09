/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:25:39 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/09 19:54:32 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\n---Simulation start...---\n";
	ClapTrap alpha;
	alpha.setName("Alpha");
	ScavTrap beta;
	beta.setName("Beta");
	std::cout << "\n--- Initial Stats ---\n";
	std::cout << alpha << std::endl << beta << std::endl;
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
		std::cout << alpha << std::endl << beta << std::endl;
		if (alpha.getHitPoints() <= 0 || beta.getHitPoints() <= 0)
			break;
	}
	std::cout << "\n--- Final Stats ---\n";
	std::cout << alpha << std::endl << beta << std::endl;
	std::cout << "\n--- ScavTrap Copy/Assign Test ---\n";
	ScavTrap gamma("Gamma");
	ScavTrap delta(gamma);
	ScavTrap epsilon;
	epsilon = gamma;
	std::cout << gamma << std::endl << delta << std::endl << epsilon <<std::endl;
	std::cout << "\n--- Scope Destruction Test ---\n";
	{
		ScavTrap temp("Temp");
		std::cout << temp << std::endl;
	}
	std::cout << "\n--- Copy Constructor Test ---\n";
	ClapTrap clone(alpha);
	std::cout << alpha << std::endl << clone << std::endl;
	std::cout << "\n--- Assignment Operator Test ---\n";
	clone = beta;
	std::cout << beta << std::endl << clone << std::endl;
	std::cout << "\n--- Edge Case Test ---\n";
	beta.setHitPoints(0);
	beta.attack("Ghost");
	beta.guardGate();
	std::cout << "\n---Simulation end.---\n";
	return 0;
}
