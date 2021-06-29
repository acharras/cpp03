/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:32:05 by acharras          #+#    #+#             */
/*   Updated: 2021/05/25 15:37:59 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_H
# define FragTrap_H

#include <iostream>
#include <cctype>
#include <string>
#include <time.h>

class FragTrap
{	
	public:

		FragTrap();
		FragTrap(std::string new_name);
		FragTrap(FragTrap const& cpy);
		~FragTrap();

		FragTrap& operator=(FragTrap const& str);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const & target);
		
   private:

		unsigned int Hit_points;
		unsigned int Max_hit_points;
		unsigned int Energy_points;
		unsigned int Max_energy_points;
		int Level;
		std::string Name;
		int Melee_attack_damage;
		int Ranged_attack_damage;
		int Armor_damage_reduction;
		void	wheelAttack(std::string const & target);
		void	waterAttack(std::string const & target);
		void	rockAttack(std::string const & target);
		void	laserAttack(std::string const & target);
		void	grinderAttack(std::string const & target);

};

#endif
