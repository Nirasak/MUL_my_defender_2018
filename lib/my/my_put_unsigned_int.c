/*
** EPITECH PROJECT, 2018
** my_put_unsigned_int
** File description:
** printf
*/

#include <unistd.h>
#include "my.h"

unsigned int my_put_unsigned_int(unsigned int nb)
{
    if (nb >= 10) {
        my_put_unsigned_int(nb / 10);
        my_put_unsigned_int(nb % 10);
    } else
        my_putchar(nb + '0');
    return (nb);
}
