/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:32:05 by acharras          #+#    #+#             */
/*   Updated: 2021/05/25 16:21:54 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_H
# define ClapTrap_H

#include <iostream>
#include <cctype>
#include <string>
#include <time.h>

class ClapTrap
{	
	public:

		ClapTrap();
		ClapTrap(std::string new_name);
		ClapTrap(ClapTrap const& cpy);
		~ClapTrap();

		ClapTrap& operator=(ClapTrap const& str);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer(std::string const & target);
		
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
		void	fixSeg(std::string const & target);
		void	doMakefile(std::string const & target);
		void	chessDual(std::string const & target);
		void	speedRun(std::string const & target);
		void	solveLeak(std::string const & target);

};

#endif
