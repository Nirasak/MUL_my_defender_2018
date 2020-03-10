/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create upgrade
*/

#include "my.h"

void damage_continue(grc_t *grc, int j, int i)
{
    if (j == 29)
        grc->life.hp[0] = grc->life.hp[0] - (5 + 2 * grc->twr.lvl[i]);
    else
        grc->life.hp[j + 1] = grc->life.hp[j + 1] - (5 + 2 * grc->twr.lvl[i]);
}

void create_upgrade(grc_t *grc)
{
    grc->twr.t_up = sfTexture_createFromFile("assets/game/upgrade.png", NULL);
    grc->twr.s_up = sfSprite_create();
    grc->twr.r_up.left = 30;
    grc->twr.r_up.top = 30;
    grc->twr.r_up.width = 64;
    grc->twr.r_up.height = 72;
    grc->twr.p_up.x = 0;
    grc->twr.p_up.y = 0;
    sfSprite_setTexture(grc->twr.s_up, grc->twr.t_up, sfTrue);
    sfSprite_setTextureRect(grc->twr.s_up, grc->twr.r_up);
    grc->twr.f_price = sfFont_createFromFile("assets/font/Jersey_554.ttf");
    grc->twr.txt_price = sfText_create();
    sfText_setFont(grc->twr.txt_price, grc->twr.f_price);
    sfText_setColor(grc->twr.txt_price, sfWhite);
    sfText_setCharacterSize(grc->twr.txt_price, 17);
}
