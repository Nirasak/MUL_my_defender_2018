/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i = i + 1;
    if ((s1[i] == '\0' || s1[i] == '\n') && (s2[i] == '\0' || s2[i] == '\n'))
        return (0);
    else
        return (1);
}
