/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:32:32 by pvong             #+#    #+#             */
/*   Updated: 2023/10/23 13:13:41 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

#define LOUD_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int ac, char **av) {

    if (ac < 2) {
        std::cout << LOUD_MSG << std::endl;
        return (0);
    }
    for (int i = 0; i < ac; i++) {
        int len = strlen(av[i]);
        for (int j = 0; j < len; j++) {
            av[i][j] = toupper(av[i][j]);
        }
        if (i == 0)
            continue ;
        std::cout << av[i];
        if (i < ac - 1)
            std::cout << " ";
        else
            std::cout << std::endl;
    }
    return (0);
}