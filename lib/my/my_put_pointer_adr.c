/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** flag p
*/

#include "my.h"

void my_print_pointer(unsigned int nb)
{
    if (nb == 0)
        my_putstr("(nil)");
    else {
        my_putstr("0x");
        my_hexa_long(nb);
    }
}
