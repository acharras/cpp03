/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:24:49 by acharras          #+#    #+#             */
/*   Updated: 2021/05/25 15:37:57 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    srand(time(NULL));
    FragTrap trap_one("Wall-e");
    FragTrap trap_two("R2D2");

    trap_one.meleeAttack("R2D2");
    trap_two.takeDamage(30);
    std::cout << std::endl;
    
    trap_one.rangedAttack("R2D2");
    trap_two.takeDamage(20);
    std::cout << std::endl;
    
    trap_two.beRepaired(15);
    trap_two.beRepaired(90);
    trap_two.takeDamage(150);
    trap_two.beRepaired(100);
    std::cout << std::endl;

    trap_one.vaulthunter_dot_exe("R2D2");
    trap_two.takeDamage(60);
    trap_two.beRepaired(100);
    std::cout << std::endl;
    
    trap_one.vaulthunter_dot_exe("R2D2");
    trap_two.takeDamage(60);
    trap_two.beRepaired(100);
    std::cout << std::endl;
    
    trap_one.vaulthunter_dot_exe("R2D2");
    trap_two.takeDamage(60);
    trap_two.beRepaired(100);
    std::cout << std::endl;
    
    trap_one.vaulthunter_dot_exe("R2D2");
    trap_two.takeDamage(60);
    trap_two.beRepaired(100);
    std::cout << std::endl;
    
    trap_one.vaulthunter_dot_exe("R2D2");
    std::cout << std::endl;
}