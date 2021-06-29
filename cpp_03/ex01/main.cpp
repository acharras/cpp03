/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:24:49 by acharras          #+#    #+#             */
/*   Updated: 2021/05/25 16:18:09 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    
    srand (time(NULL));
    FragTrap max("max");
    ScavTrap koro("koro");
    max.vaulthunter_dot_exe("unpokemon");
    max.vaulthunter_dot_exe("unpokemon");
    max.vaulthunter_dot_exe("unpokemon");
    max.vaulthunter_dot_exe("unpokemon");
    max.vaulthunter_dot_exe("unpokemon");
    std::cout << std::endl;
    max.meleeAttack("drake");
    max.rangedAttack("drake");
    max.takeDamage(50);
    max.beRepaired(10);

    std::cout << std::endl;
    std::cout << std::endl;
    
    koro.meleeAttack("missaw");
    koro.rangedAttack("max");
    koro.takeDamage(12500);
    koro.beRepaired(50);
    std::cout << std::endl;
    koro.challengeNewcomer("unknown");
    koro.challengeNewcomer("unknown");
    koro.challengeNewcomer("unknown");
    koro.challengeNewcomer("unknown");
}