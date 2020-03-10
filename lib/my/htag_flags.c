/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** htag flags
*/

#include "my.h"

void htg_flag(char *str, int *i, va_list ap)
{
    if (str[(*i) + 1] == 'x') {
        my_putstr("0x");
        my_unsign_hexa_min(va_arg(ap, int));
    } else if (str[(*i) + 1] == 'X') {
        my_putstr("0X");
        my_unsign_hexa_maj(va_arg(ap, int));
    }
}
