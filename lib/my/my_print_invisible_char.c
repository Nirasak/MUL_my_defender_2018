/*
** EPITECH PROJECT, 2018
** printf
** File description:
** print invisible char
*/

#include "my.h"

void print_inv_char(int i, char *str)
{
    my_putchar('\\');
    if (str[i] <= 7)
        my_putstr("00");
    else if (str[i] <= 32)
        my_putstr("0");
    my_octal(str[i]);
}

void my_print_inv_str(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i = i + 1) {
    if (str[i] < 32 || str[i] == 127)
        print_inv_char(i, str);
    else
        my_putchar(str[i]);
    }
}
