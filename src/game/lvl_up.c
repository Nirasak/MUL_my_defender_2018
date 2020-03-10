/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** upgrade twrs
*/

#include "my.h"

void print_level_up4(grc_t *grc, int i)
{
    if (grc->twr.status[i] == 5 && grc->twr.lvl[i] == 3)
        grc->twr.price = 300;
    if (grc->twr.status[i] == 5 && grc->twr.lvl[i] == 2)
        grc->twr.price = 250;
    if (grc->twr.status[i] == 5 && grc->twr.lvl[i] == 1)
        grc->twr.price = 200;
    grc->twr.p_price.x = grc->twr.p_twr[i].x + 69;
    grc->twr.p_price.y = grc->twr.p_twr[i].y + 341;
    sfText_setPosition(grc->twr.txt_price, grc->twr.p_price);
    sfText_setString(grc->twr.txt_price, my_itoa(grc->twr.price));
}

void print_level_up3(grc_t *grc, int i)
{
    if (grc->twr.status[i] == 4 && grc->twr.lvl[i] == 3)
        grc->twr.price = 275;
    if (grc->twr.status[i] == 4 && grc->twr.lvl[i] == 2)
        grc->twr.price = 200;
    if (grc->twr.status[i] == 4 && grc->twr.lvl[i] == 1)
        grc->twr.price = 170;
    print_level_up4(grc, i);
}

void print_level_up2(grc_t *grc, int i)
{
    if (grc->twr.status[i] == 3 && grc->twr.lvl[i] == 3)
        grc->twr.price = 220;
    if (grc->twr.status[i] == 3 && grc->twr.lvl[i] == 2)
        grc->twr.price = 150;
    if (grc->twr.status[i] == 3 && grc->twr.lvl[i] == 1)
        grc->twr.price = 100;
    print_level_up3(grc, i);
}

void print_level_up(grc_t *grc, int i)
{
    if (grc->twr.status[i] == 2 && grc->twr.lvl[i] == 3)
        grc->twr.price = 250;
    if (grc->twr.status[i] == 2 && grc->twr.lvl[i] == 2)
        grc->twr.price = 175;
    if (grc->twr.status[i] == 2 && grc->twr.lvl[i] == 1)
        grc->twr.price = 120;
    grc->twr.status_price = 1;
    grc->twr.p_up.x = grc->twr.p_twr[i].x + 44;
    grc->twr.p_up.y = grc->twr.p_twr[i].y + 292;
    sfSprite_setPosition(grc->twr.s_up, grc->twr.p_up);
    grc->twr.twr_up = i;
    print_level_up2(grc, i);
}

void check_lvl(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    int stop = 0;

    for (int i = 0; i <= 5 && stop != 1; i = i + 1) {
        if (event.type == sfEvtMouseButtonPressed
            && (p_mouse.x >= grc->twr.p_twr[i].x)
            && (p_mouse.x <= grc->twr.p_twr[i].x + grc->twr.r_twr[i].width)
            && (p_mouse.y >= grc->twr.p_twr[i].y + 75)
            && (p_mouse.y <= grc->twr.p_twr[i].y + grc->twr.r_twr[i].height)
            && (grc->twr.lvl[i] < 4 && grc->twr.lvl[i] >= 1)
            && (grc->twr.status[i] > 1)) {
            stop = 1;
            print_level_up(grc, i);
        } else if (event.type == sfEvtMouseButtonPressed)
            grc->twr.status_price = 0;
    }
}
