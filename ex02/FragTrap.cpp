/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:07:11 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 11:03:01 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ScavTrap() {
	ScavTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	ScavTrap::setAttackDamage(30);
	std::cout << COLOR_BLUE << "Back in action.(FragTrap)" << COLOR_RESET<< std::endl;
}

FragTrap::FragTrap(const std::string& name) : ScavTrap(name) {
	ScavTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	ScavTrap::setAttackDamage(30);
	std::cout << COLOR_RED << "Ready or not, here we go.(FragTrap)" << COLOR_RESET << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << COLOR_YELLOW << getName() << ":" << COLOR_RESET << std::endl;
	std::cout << "Game over, man. Game over.(FragTrap)" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ScavTrap(other) {
	std::cout << COLOR_BLUE << "Copying " << other.getName() << "...(FragTrap)" << COLOR_RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << COLOR_BLUE << getName() << " requests a high five! " << COLOR_RESET << std::endl;
	if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
	{
		std::cout << COLOR_RED << "Battery low. Like, really low." << COLOR_RESET << std::endl;
		return ;
	}
	std::cout << "Thanks for the high five!" << std::endl;
}
