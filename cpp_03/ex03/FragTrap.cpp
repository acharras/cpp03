/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:16:55 by acharras          #+#    #+#             */
/*   Updated: 2021/05/25 15:39:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

typedef void(FragTrap::* attacks) (std::string const &target);

FragTrap::FragTrap(){
	std::cout << "FR4G-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "Hi there, I'm ready to go the battlefield !" << std::endl;
}

FragTrap::FragTrap(std::string new_name) : 
Hit_points(100),
Max_hit_points(100),
Energy_points(100),
Max_energy_points(100),
Level(1),
Name(new_name),
Melee_attack_damage(30),
Ranged_attack_damage(20),
Armor_damage_reduction(5){
	this->Name = new_name;
	std::cout << "FR4G-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "Hi there, I'm ready to go the battlefield !" << std::endl;
}

FragTrap::FragTrap(FragTrap const& cpy) :
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
	std::cout << "Damn, you .. you ... you copy me !" << std::endl;
}


FragTrap::~FragTrap(){
	std::cout << "FR4G-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "Mmh, am I dying ? No it's impossibbbb......" << std::endl;
}

FragTrap&  FragTrap::operator=(FragTrap const& str){
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

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "FR4G-TP <" << Name << "> attacks <" << target << "> at range, causing <" << Ranged_attack_damage << "> points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << "FR4G-TP <" << Name << "> attacks <" << target << "> at melee, causing <" << Melee_attack_damage << "> points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	amount -= this->Armor_damage_reduction;
	std::cout << "FR4G-TP " << Name << " | | HP " << Hit_points << std::endl;
	if (amount > this->Hit_points)
		amount = this->Hit_points;
	std::cout << "BOOM, " << Name << " take " << amount << " damage" << std::endl;
	this->Hit_points -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (amount + Hit_points > Max_hit_points)
		amount = Max_hit_points - Hit_points;
	std::cout << "FR4G-TP " << Name << " | | HP " << Hit_points << std::endl;
	std::cout << Name << " repairing himself, recovering " << amount << " Health Point" << std::endl;
	this->Hit_points += amount;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	attacks atk[5] = {
		&FragTrap::wheelAttack,
		&FragTrap::waterAttack,
		&FragTrap::rockAttack,
		&FragTrap::laserAttack,
		&FragTrap::grinderAttack};
	if (Energy_points < 25)
	{
		std::cout << "FR4G-TP " << Name << " | | HP " << Hit_points << std::endl;
		std::cout << "Your energy is too low, take a breath..." << std::endl;
		return ;
	}
	std::cout << "FR4G-TP " << Name << " | | HP " << Hit_points << std::endl;
	(this->*atk[rand() % 5])(target);
	this->Energy_points -= 25;
}

void	FragTrap::wheelAttack(std::string const & target)
{
	std::cout << Name << " attack with his wheel and just roll on " << target << " and deal 60 damage" << std::endl;
}

void	FragTrap::waterAttack(std::string const & target)
{
	std::cout << Name << " attack with a water gun picked up on another FR4G-TP before, just launch water on " << target << " and deal 60 damage" << std::endl;
}

void	FragTrap::rockAttack(std::string const & target)
{
	std::cout << Name << " fall on a rock and initiate an avalanche, " << target << " take 60 damage" << std::endl;
}

void	FragTrap::laserAttack(std::string const & target)
{
	std::cout << Name << " launch a laser beam from his single eye on " << target << " and deal 60 damage" << std::endl;
}

void	FragTrap::grinderAttack(std::string const & target)
{
	std::cout << Name << " replace his arm to an angle grinder and rush on " << target << " that deal 60 damage" << std::endl;
}