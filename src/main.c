/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    grc_t grc;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (print_descr());
    else if (ac == 1)
        return (my_defender(&grc));
    else
        return (84);
}
