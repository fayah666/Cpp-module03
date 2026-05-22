/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfandres <hfandres@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 09:39:09 by hfandres          #+#    #+#             */
/*   Updated: 2026/05/22 17:50:22 by hfandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
	public :
		public :
		FragTrap(void);
		FragTrap(const std::string& name);
		~FragTrap(void);
		FragTrap(const FragTrap& other);

		FragTrap& operator=(const FragTrap& other);
		void		highFivesGuys(void);
};

#endif
