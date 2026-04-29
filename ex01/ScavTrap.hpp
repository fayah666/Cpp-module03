/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:02:36 by hfandres          #+#    #+#             */
/*   Updated: 2026/04/29 19:24:57 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
