/*
** EPITECH PROJECT, 2020
** CNA_groundhog_2019
** File description:
** main
*/

#include <iostream>
#include <string>
#include "Parser.hpp"

void help(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0) {
        std::cout << "SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION\n\tperiod\t\tthe number of days defining a period" << std::endl;
        exit (0);
    }
}

void Error(int ac, char **av)
{
    try
    {
        if (ac != 2)
            exit (84);
        help(av);
        std::stoi(av[1]);

        if (av[1][0] <= '1') {
            exit (84);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " Invalid Conversion" << std::endl;
        exit (84);
    }
}


int main(int ac, char **av) 
{
    Error(ac, av);
    Parser program(std::stoi(av[1]));

    program.start();
    return 0;
}