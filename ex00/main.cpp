/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:25:39 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/11 10:50:47 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap alpha;
	alpha.setName("Alpha");
	ClapTrap beta("Beta");
	std::cout << "\n--- Initial Stats ---\n";
	std::cout << alpha << std::endl;
	std::cout << beta << std::endl;
	std::cout << "\n--- setAttackDamage ---\n";
	alpha.setAttackDamage(4);
	beta.setAttackDamage(4);
	std::cout << alpha << std::endl;
	std::cout << beta << std::endl;
	std::cout << "\n--- Fight Start ---\n";
	for (int turn = 1; turn <= 5; turn++)
	{
		std::cout << "\n[TURN " << turn << "]\n";
		alpha.attack(beta.getName());
		if (alpha.getHitPoints() > 0 && alpha.getEnergyPoints() > 0)
			beta.takeDamage(alpha.getAttackDamage());
		std::cout << "--------------------------------" << std::endl;
		if (beta.getHitPoints() < 5 && beta.getEnergyPoints() > 0)
			beta.beRepaired(3);
		else
		{
			beta.attack(alpha.getName());
			if (beta.getHitPoints() > 0 && beta.getEnergyPoints() > 0)
				alpha.takeDamage(beta.getAttackDamage());
		}
		std::cout << "--------------------------------" << std::endl;
		std::cout << alpha << std::endl << beta << std::endl;
		if (alpha.getHitPoints() <= 0 || beta.getHitPoints() <= 0)
			break;
		std::cout << "==================================" << std::endl;
	}
	std::cout << "\n--- Final Stats ---\n";
	std::cout << alpha << std::endl << beta << std::endl;
	std::cout << "\n--- Copy Constructor Test ---\n";
	ClapTrap clone(alpha);
	std::cout << alpha << std::endl << clone << std::endl;
	std::cout << "\n--- Assignment Operator Test ---\n";
	clone = beta;
	std::cout << clone << std::endl << beta << std::endl;
	std::cout << "\n--- Edge Case Test ---\n";
	beta.setHitPoints(10);
	beta.beRepaired(200);
	std::cout << beta << std::endl;
	beta.takeDamage(10);
	std::cout << beta << std::endl;
	beta.setHitPoints(0);
	beta.attack("Ghost");
	beta.beRepaired(5);
	beta.takeDamage(5);
	beta.setHitPoints(10);
	beta.setEnergyPoints(0);
	beta.attack("Ghost");
	beta.beRepaired(5);
	beta.takeDamage(5);
	return 0;
}
