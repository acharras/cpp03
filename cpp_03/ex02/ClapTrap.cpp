/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:16:55 by acharras          #+#    #+#             */
/*   Updated: 2021/05/25 16:22:23 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

typedef void(ClapTrap::* Challenge) (std::string const &target);

ClapTrap::ClapTrap(){
	std::cout << "CL4P-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "Hi there, I'm ready to go the battlefield ! I'm a CL4P-TP let's goooo !" << std::endl;
}

ClapTrap::ClapTrap(std::string new_name) : 
Hit_points(100),
Max_hit_points(100),
Energy_points(50),
Max_energy_points(50),
Level(1),
Name(new_name),
Melee_attack_damage(20),
Ranged_attack_damage(15),
Armor_damage_reduction(3){
	this->Name = new_name;
	std::cout << "CL4P-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "Hi there, I'm ready to go the battlefield ! I'm a CL4P-TP let's goooo !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& cpy) :
Hit_points(cpy.Hit_points),
Max_hit_points(cpy.Max_hit_points),
Energy_points(cpy.Energy_points),
Max_energy_points(cpy.Max_energy_points),
Level(cpy.Level),
Name(cpy.Name),
Melee_attack_damage(cpy.Melee_attack_damage),
Ranged_attack_damage(cpy.Ranged_attack_damage),
Armor_damage_reduction(cpy.Armor_damage_reduction){
	*this = cpy;
	std::cout << "Damn, you .. you ... you copy me ! I was the only one CL4P-TP..." << std::endl;
}


ClapTrap::~ClapTrap(){
	std::cout << "CL4P-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "Mmh, am I dying ? I'm a CL4P-TP I can't... No it's impossibbbb......" << std::endl;
}

ClapTrap&  ClapTrap::operator=(ClapTrap const& str){
	this->Hit_points = str.Hit_points;
	this->Max_hit_points = str.Max_hit_points;
	this->Energy_points = str.Energy_points;
	this->Max_energy_points = str.Max_energy_points;
	this->Level = str.Level;
	this->Name = str.Name;
	this->Melee_attack_damage = str.Melee_attack_damage;
	this->Ranged_attack_damage = str.Ranged_attack_damage;
	this->Armor_damage_reduction = str.Armor_damage_reduction;
	std::cout << "Assignation operator called" << std::endl;
	return (*this);
}

void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "CL4P-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "CL4P-TP <" << Name << "> attacks <" << target << "> at range, causing <" << Ranged_attack_damage << "> points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "CL4P-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "CL4P-TP <" << Name << "> attacks <" << target << "> at melee, causing <" << Melee_attack_damage << "> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	amount -= this->Armor_damage_reduction;
	std::cout << "CL4P-TP " << Name << " | | HP " << Hit_points << std::endl;
	if (amount > this->Hit_points)
		amount = this->Hit_points;
	std::cout << "BOOM, " << Name << " take " << amount << " damage" << std::endl;
	this->Hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount + Hit_points > Max_hit_points)
		amount = Max_hit_points - Hit_points;
	std::cout << "CL4P-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << Name << " repairing himself, recovering " << amount << " Health Point" << std::endl;
	this->Hit_points += amount;
}

void ClapTrap::challengeNewcomer(std::string const & target)
{
	Challenge chl[5] = {
		&ClapTrap::fixSeg,
		&ClapTrap::doMakefile,
		&ClapTrap::chessDual,
		&ClapTrap::speedRun,
		&ClapTrap::solveLeak};
	if (Energy_points < 25)
	{
		std::cout << "CL4P-TP " << Name << " | | HP " << Hit_points << std::endl;
		std::cout << "Your energy is too low, take a breath..." << std::endl;
		return ;
	}
	std::cout << "CL4P-TP " << Name << " | | HP " << Hit_points << std::endl;
	(this->*chl[rand() % 5])(target);
	this->Energy_points -= 25;
}

void	ClapTrap::fixSeg(std::string const & target)
{
	std::cout << "CL4P-TP challenge " << target << " to fix a segfault" << std::endl;
}

void	ClapTrap::doMakefile(std::string const & target)
{
	std::cout << "CL4P-TP challenge " << target << " to do an excellent Makefile" << std::endl;
}

void	ClapTrap::chessDual(std::string const & target)
{
	std::cout << "CL4P-TP challenge " << target << " to won a chess dual" << std::endl;
}

void	ClapTrap::speedRun(std::string const & target)
{
	std::cout << "CL4P-TP challenge " << target << " to speed run Super Meet Boy" << std::endl;
}

void	ClapTrap::solveLeak(std::string const & target)
{
	std::cout << "CL4P-TP challenge " << target << " to solve all the leaks in his code" << std::endl;
}