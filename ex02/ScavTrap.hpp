/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:02:36 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/30 10:01:03 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public :
		ScavTrap(void);
		ScavTrap(const std::string& name);
		~ScavTrap(void);
		ScavTrap(const ScavTrap& other);

		ScavTrap& operator=(const ScavTrap& other);
		void		attack(const std::string& target);
		void		guardGate(void);
};

#endif //SCAVTRAP_HPP
