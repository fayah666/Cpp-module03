/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:00:04 by hfandres          #+#    #+#             */
/*   Updated: 2026/06/10 11:22:49 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

# define COLOR_RED "\033[31m"
# define COLOR_GREEN "\033[32m"
# define COLOR_BLUE "\033[34m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_RESET "\033[0m"

class ClapTrap
{
	protected :
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		int			_hitPointsMax;
	public :
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& other);
		~ClapTrap();

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		void		setName(const std::string& name);
		void		setHitPoints(const int hitpoints);
		void		setEnergyPoints(const int energyPoints);
		void		setAttackDamage(const int energyPoints);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& os, ClapTrap& c);

#endif //CLAPTRAP_HPP

