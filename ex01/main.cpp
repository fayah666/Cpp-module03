/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:25:39 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/11 11:08:00 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\n---Simulation start...---\n";
	ClapTrap alpha;
	alpha.setName("Alpha");
	alpha.setAttackDamage(50);
	ScavTrap beta;
	beta.setName("Beta");
	std::cout << "\n--- Initial Stats ---\n";
	std::cout << alpha << std::endl << beta << std::endl;
	std::cout << "\n--- Fight Start ---\n";
	for (int turn = 1; turn <= 5; turn++)
	{
		std::cout << "\n[TURN " << turn << "]\n";
		alpha.attack(beta.getName());
		if (alpha.getHitPoints() > 0 && beta.getEnergyPoints() > 0)
			beta.takeDamage(alpha.getAttackDamage());
		std::cout << "----------------------------------" << std::endl;
		if (beta.getHitPoints() < 50 && beta.getEnergyPoints() > 0)
			beta.guardGate();
		if (beta.getHitPoints() < 30 && beta.getEnergyPoints() > 0)
			beta.beRepaired(3);
		else
		{
				beta.attack(alpha.getName());
				if (beta.getHitPoints() > 0 && beta.getEnergyPoints() > 0)
					alpha.takeDamage(beta.getAttackDamage());
		}
		std::cout << "----------------------------------" << std::endl;
		std::cout << alpha << std::endl << beta << std::endl;
		std::cout << "==================================" << std::endl;
	}
	std::cout << "\n--- Final Stats ---\n";
	std::cout << alpha << std::endl << beta << std::endl;
	std::cout << "\n--- ScavTrap Copy/Assign Test ---\n";
	ScavTrap gamma("Gamma");
	ScavTrap delta(gamma);
	ScavTrap epsilon;
	epsilon = gamma;
	std::cout << "gamma : " << gamma << std::endl
			<< "delta : " << delta << std::endl
			<< "epsilon : " << epsilon <<std::endl;
	std::cout << "\n--- Scope Destruction Test ---\n";
	{
		ScavTrap temp("Temp");
		std::cout << temp << std::endl;
	}
	std::cout << "\n--- Copy Constructor Test ---\n";
	ClapTrap clone(alpha);
	std::cout << "alpha : " << alpha << std::endl
				<< "clone : " << clone << std::endl;
	std::cout << "\n--- Assignment Operator Test ---\n";
	clone = beta;
	std::cout << "beta : " << beta << std::endl
				<< "clone : " << clone << std::endl;
	std::cout << "\n--- Edge Case Test ---\n";
	beta.beRepaired(34124);
	std::cout << beta << std::endl;
	beta.setHitPoints(0);
	std::cout << "setHitPoints : " << beta << std::endl;
	beta.attack("Ghost");
	beta.guardGate();
	beta.beRepaired(5);
	beta.takeDamage(5);
	beta.setHitPoints(10);
	std::cout << "setHitPoints : " << beta << std::endl;
	beta.setEnergyPoints(0);
	std::cout << "setEnergyPoints : " << beta << std::endl;
	beta.attack("Ghost");
	beta.guardGate();
	beta.beRepaired(5);
	beta.takeDamage(5);
	std::cout << "\n---Simulation end.---\n";
	return 0;
}
