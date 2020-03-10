/*
** EPITECH PROJECT, 2019
** create_put_pause_two
** File description:
** .c
*/

#include "my.h"

void create_but_exit(grc_t *grc)
{
    grc->pause.r_exit.top = 480;
    grc->pause.r_exit.left = 184;
    grc->pause.r_exit.width = 284;
    grc->pause.r_exit.height = 108;
    grc->pause.p_exit.x = 1408;
    grc->pause.p_exit.y = 560;
    sfSprite_setTexture(grc->pause.s_exit, grc->pause.t_but, sfTrue);
    sfSprite_setTextureRect(grc->pause.s_exit, grc->pause.r_exit);
    sfSprite_setPosition(grc->pause.s_exit, grc->pause.p_exit);
}
