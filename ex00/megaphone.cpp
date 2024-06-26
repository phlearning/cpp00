/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:32:32 by pvong             #+#    #+#             */
/*   Updated: 2023/10/30 11:32:33 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <iostream>

#define LOUD_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << LOUD_MSG << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j]; j++) {
            std::cout << (char)toupper(av[i][j]);
        }
        if (i < ac - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return (0);
}