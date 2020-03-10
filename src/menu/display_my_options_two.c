/*
** EPITECH PROJECT, 2019
** display_my_options_two.c
** File description:
** .c
*/

#include "my.h"

int event_my_volume(sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased)
        return (0);
    return (1);
}
