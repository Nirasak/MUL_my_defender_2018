/*
** EPITECH PROJECT, 2019
** create_all_but
** File description:
** .c
*/

#include "my.h"

void create_all_but(grc_t *grc)
{
    create_but_all(grc);
    create_but_new(grc);
    create_but_game(grc);
    create_but_opt(grc);
    create_but_menu(grc);
    create_but_exit(grc);
}
