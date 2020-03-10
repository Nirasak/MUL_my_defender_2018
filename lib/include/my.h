/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my.h
*/

#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

int my_putstr(char const *);
void my_putchar(char);
int my_put_nbr(int);
void my_printf(char *, ...);
int my_octal(int);
unsigned int my_put_unsigned_int(unsigned int);
unsigned int my_unsign_hexa_min(unsigned int);
unsigned int my_unsign_hexa_maj(unsigned int);
void my_print_inv_str(char *);
char *my_strcpy(char *, char const *);
long my_put_long(long);
long long my_put_ll(long long);
void my_print_pointer(unsigned int);
void htg_flag(char *, int *, va_list);
long my_hexa_long(long);

#endif
