/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:05:26 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/10 11:15:48 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	_hitPoints(10), _energyPoints(10), _attackDamage(0), _hitPointsMax(_hitPoints)
{
	std::cout << COLOR_YELLOW << _name << ": " ;
	std::cout << COLOR_BLUE << "Spawning with style.(ClapTrap)" << COLOR_RESET << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << COLOR_YELLOW << _name << ": ";
	std::cout << COLOR_RED << "So this is how it ends(ClapTrap)" << COLOR_RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _hitPointsMax(_hitPoints)
{
	std::cout << COLOR_YELLOW << _name << ": ";
	std::cout << COLOR_BLUE << "Showtime(ClapTrap)" << COLOR_RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	if (this != &other)
		*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, ClapTrap& c)
{
	os << "{" << c.getName()
		<< " : " << c.getHitPoints()
		<< ", " << c.getEnergyPoints()
		<< ", " << c.getAttackDamage()
		<< "}";
	return (os);
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

int	ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void	ClapTrap::setName(const std::string& name) {
	this->_name = name;
}

void	ClapTrap::setHitPoints(const int hitpoints) {
	this->_hitPoints = hitpoints;
}

void	ClapTrap::setEnergyPoints(const int energyPoints) {
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(const int attackDamage) {
	this->_attackDamage = attackDamage;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << COLOR_YELLOW << _name << ": ";
	std::cout << COLOR_BLUE << "Swing first, think later!" << COLOR_RESET << std::endl;
	_energyPoints -= 1;
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << COLOR_RED << "Battery low. Like, really low." << COLOR_RESET << std::endl;
		_energyPoints = 0;
		return ;
	}
	std::cout << "Claptrap " << _name << " attacks " << target << ", ";
	std::cout << "causing " << _attackDamage <<  " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << COLOR_YELLOW << _name << ": ";
	std::cout << COLOR_RED << "I’m fine. Totally fine. Probably." << COLOR_RESET << std::endl;
	std::cout << "Claptrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		_hitPoints = 0;
		std::cout << COLOR_RED << "Ouch!" << COLOR_RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << COLOR_YELLOW << _name << ": ";
	std::cout << COLOR_GREEN << "Magic fixes everything." << COLOR_RESET << std::endl;
	_energyPoints -= 1;
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << COLOR_RED << "Battery low. Like, really low." << COLOR_RESET << std::endl;
		_energyPoints = 0;
		return ;
	}
	std::cout << "Claptrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
	if (_hitPoints >= _hitPointsMax)
		_hitPoints = _hitPointsMax;
	else
		_hitPoints += amount;
}
