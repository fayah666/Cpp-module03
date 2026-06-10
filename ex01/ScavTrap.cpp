/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:07:11 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/10 12:24:39 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_hitPointsMax = _hitPoints;
	std::cout << COLOR_BLUE << "My love! Hero entry(ScavTrap)" << COLOR_RESET<< std::endl;
}

ScavTrap::ScavTrap(const std::string& name) :
ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	_hitPointsMax = _hitPoints;
	std::cout << COLOR_RED << "I'm " << getName() << " not serena (ScavTrap)" << COLOR_RESET << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << COLOR_YELLOW << getName() << ": ";
	std::cout << "Love is never dead(ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << COLOR_BLUE << "Copying " << other.getName() << "...(ScavTrap)" << COLOR_RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << COLOR_RED << _name << "Ghost : " << COLOR_RESET << "ooouuuuuuuuuh!" << std::endl;
		return ;
	}
	std::cout << COLOR_YELLOW << getName() << ": ";
	std::cout << COLOR_BLUE << "Serena's hand!" << COLOR_RESET << std::endl;
	_energyPoints -= 1;
	if (_energyPoints <= 0)
	{
		std::cout << COLOR_RED << "Battery low. Like, really low." << COLOR_RESET << std::endl;
		_energyPoints = 0;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << std::endl;
	std::cout << "causing " << getAttackDamage() <<  " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_hitPoints <= 0)
	{
		std::cout << COLOR_RED << _name << "Ghost : " << COLOR_RESET << "ooouuuuuuuuuh!" << std::endl;
		return ;
	}
	std::cout << COLOR_YELLOW << getName() << ": ";
	std::cout << COLOR_BLUE << "Entering Gate keeper mode." << COLOR_RESET << std::endl;
	_energyPoints -= 1;
	if (getEnergyPoints() <= 0)
	{
		std::cout << COLOR_RED << "Battery low. Like, really low." << COLOR_RESET << std::endl;
		_energyPoints = 0;
		return ;
	}
}
