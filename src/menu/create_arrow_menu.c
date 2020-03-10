/*
** EPITECH PROJECT, 2019
** create_arrow_menu
** File description:
** .c
*/

#include "my.h"

void create_arrow_book_two(grc_t *grc)
{
    grc->info.t_arr = sfTexture_createFromFile("assets/menu/arr.png",
                                                NULL);
    grc->info.s_arr = sfSprite_create();
    grc->info.r_arr.top = 15;
    grc->info.r_arr.left = 12;
    grc->info.r_arr.width = 95;
    grc->info.r_arr.height = 82;
    grc->info.p_arr.x = 300;
    grc->info.p_arr.y = 790;
    sfSprite_setTexture(grc->info.s_arr, grc->info.t_arr, sfTrue);
    sfSprite_setTextureRect(grc->info.s_arr, grc->info.r_arr);
    sfSprite_setPosition(grc->info.s_arr, grc->info.p_arr);
}

void event_arrow_book_two(grc_t *grc, sfVector2i p_mouse, sfEvent event,
                        sfRenderWindow *wdw)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->info.p_arr.x)
        && (p_mouse.x <= grc->info.p_arr.x + grc->info.r_arr.width)
        && (p_mouse.y >= grc->info.p_arr.y)
        && (p_mouse.y <= grc->info.p_arr.y + grc->info.r_arr.height)) {
        grc->info.r_arr.left = 12;
        my_info(grc, wdw);
    } else if ((p_mouse.x >= grc->info.p_arr.x)
                && (p_mouse.x <= grc->info.p_arr.x + grc->info.r_arr.width)
                && (p_mouse.y >= grc->info.p_arr.y)
                && (p_mouse.y <= grc->info.p_arr.y + grc->info.r_arr.height))
        grc->info.r_arr.left = 118;
    else
        grc->info.r_arr.left = 12;
    sfSprite_setTextureRect(grc->info.s_arr, grc->info.r_arr);
}
