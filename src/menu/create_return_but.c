/*
** EPITECH PROJECT, 2019
** create_return_button
** File description:
** .c
*/

#include "my.h"

void create_return_but(grc_t *grc)
{
    sfVector2f scale;

    grc->info.t_ret = sfTexture_createFromFile("assets/menu/return_but.png",
                                                NULL);
    grc->info.s_ret = sfSprite_create();
    grc->info.r_ret.top = 13;
    grc->info.r_ret.left = 12;
    grc->info.r_ret.width = 42;
    grc->info.r_ret.height = 43;
    grc->info.p_ret.x = 705;
    grc->info.p_ret.y = 905;
    scale.x = 1.7;
    scale.y = 1.7;
    sfSprite_setScale(grc->info.s_ret, scale);
    sfSprite_setTexture(grc->info.s_ret, grc->info.t_ret, sfTrue);
    sfSprite_setTextureRect(grc->info.s_ret, grc->info.r_ret);
    sfSprite_setPosition(grc->info.s_ret, grc->info.p_ret);
}

void events_return_but(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->info.p_ret.x)
        && (p_mouse.x <= grc->info.p_ret.x + grc->info.r_ret.width)
        && (p_mouse.y >= grc->info.p_ret.y)
        && (p_mouse.y <= grc->info.p_ret.y + grc->info.r_ret.height)) {
        grc->info.r_ret.left = 12;
        grc->menu.util = 0;
    }
    else if ((p_mouse.x >= grc->info.p_ret.x)
            && (p_mouse.x <= grc->info.p_ret.x + grc->info.r_ret.width)
            && (p_mouse.y >= grc->info.p_ret.y)
            && (p_mouse.y <= grc->info.p_ret.y + grc->info.r_ret.height))
        grc->info.r_ret.left = 58;
    else
        grc->info.r_ret.left = 12;
    sfSprite_setTextureRect(grc->info.s_ret, grc->info.r_ret);
}
