/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display menu
*/

#include "my.h"

void display_my_menu(grc_t *grc, sfRenderWindow *wdw)
{
    sfRenderWindow_drawSprite(wdw, grc->menu.s_menu, NULL);
    sfRenderWindow_drawSprite(wdw, grc->menu.s_play, NULL);
    sfRenderWindow_drawSprite(wdw, grc->menu.s_opt, NULL);
    sfRenderWindow_drawSprite(wdw, grc->menu.s_exit, NULL);
    sfRenderWindow_drawSprite(wdw, grc->crsr.s_csr, NULL);
}
