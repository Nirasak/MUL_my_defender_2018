/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** print descr
*/

#include "my.h"

int print_descr(void)
{
    my_printf("Finite defender created with CSFML.\n\n"
            "USAGE\n ./my_defender\n\n\nOPTIONS\n"
            "-h\t\tprint the usage and quit.\n\n"
            "USER INTERACTIONS\n ESCAPE_KEY\tpause screen.\n");
    return (0);
}
