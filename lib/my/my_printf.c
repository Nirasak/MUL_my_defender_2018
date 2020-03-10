/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include "my.h"

void flags_4(char *str, int i, va_list ap)
{
    switch (str[i]) {
    case 'x':
        my_unsign_hexa_min(va_arg(ap, unsigned int));
        break;
    case 'X':
        my_unsign_hexa_maj(va_arg(ap, unsigned int));
        break;
    case 'p':
        my_print_pointer(va_arg(ap, unsigned int));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        my_putchar(str[i - 1]);
        my_putchar(str[i]);
        break;
    }
}

void flags_3(char *str, int *i, va_list ap)
{
    switch (str[*i]) {
    case '#':
        if (str[(*i) + 1] == 'o') {
            my_putchar('0');
            my_octal(va_arg(ap, int));
            (*i) += 1;
            return;
        }
        else if (str[(*i) + 1] == 'x' || str[(*i) + 1] == 'X') {
            htg_flag(str, i, ap);
            (*i) =+ 2;
            return;
        } else
            break;
    }
    flags_4(str, *i, ap);
}

void flags_2(char *str, int *i, va_list ap)
{
    switch (str[*i]) {
    case 'S':
        my_print_inv_str(va_arg(ap, char *));
        return;
    case 'l':
        if (str[(*i) + 1] == 'd') {
            my_put_long(va_arg(ap, long));
            (*i) += 1;
            return;
        } else if (str[(*i) + 1] == 'l') {
            my_put_ll(va_arg(ap, long long));
            (*i) += 1;
            return;
        } else
            break;
    case 'm':
        my_putstr("Success");
        return;
    }
    flags_3(str, i, ap);
}

void flags(char *str, int *i, va_list ap)
{
    switch (str[*i]) {
    case 'd':
    case 'i':
        my_put_nbr(va_arg(ap, int));
        return;
    case 'c':
        my_putchar(va_arg(ap, int));
        return;
    case 's':
        my_putstr(va_arg(ap, char *));
        return;
    case 'o':
        my_octal(va_arg(ap, int));
        return;
    case 'u':
        my_put_unsigned_int(va_arg(ap, unsigned int));
        return;
    }
    flags_2(str, i, ap);
}

void my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] != '%')
            my_putchar(str[i]);
        else {
            i = i + 1;
            flags(str, &i, ap);
        }
    }
}
