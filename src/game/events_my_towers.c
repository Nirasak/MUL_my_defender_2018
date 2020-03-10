/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display towers
*/

#include "my.h"

void level_up(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (grc->twr.status_price == 1 && grc->gold.gold >= grc->twr.price)
        grc->twr.r_up.left = 30;
    if (grc->twr.status_price == 1 && grc->gold.gold < grc->twr.price)
        grc->twr.r_up.left = 120;
    sfSprite_setTextureRect(grc->twr.s_up, grc->twr.r_up);
    if (event.type == sfEvtMouseButtonPressed
        && (p_mouse.x >= grc->twr.p_up.x && p_mouse.y >= grc->twr.p_up.y)
        && (p_mouse.x <= grc->twr.p_up.x + 64)
        && (p_mouse.y <= grc->twr.p_up.y + 72)) {
        if (grc->gold.gold >= grc->twr.price) {
            grc->twr.r_twr[grc->twr.twr_up].top += 350;
            grc->twr.lvl[grc->twr.twr_up] += 1;
            grc->gold.gold = grc->gold.gold - grc->twr.price;
        }
    }
}

void events_my_towers3(grc_t *grc, int i)
{
    if (grc->twr.status[i] == 4 && grc->twr.lvl[i] == 1) {
        grc->twr.r_twr[i].top = 50;
        grc->twr.r_twr[i].left = 450;
        grc->twr.delay_atk[i] = 6;
    }
    if (grc->twr.status[i] == 5 && grc->twr.lvl[i] == 1) {
        grc->twr.r_twr[i].top = 50;
        grc->twr.r_twr[i].left = 250;
        grc->twr.delay_atk[i] = 5;
    }
}

void events_my_towers2(grc_t *grc, int i)
{
    if (grc->twr.status[i] == 0) {
        grc->twr.r_twr[i].top = 50;
        grc->twr.r_twr[i].left = 1050;
    }
    if (grc->twr.status[i] == 2 && grc->twr.lvl[i] == 1) {
        grc->twr.r_twr[i].top = 50;
        grc->twr.r_twr[i].left = 50;
        grc->twr.delay_atk[i] = 3.6;
    }
    if (grc->twr.status[i] == 3 && grc->twr.lvl[i] == 1) {
        grc->twr.r_twr[i].top = 50;
        grc->twr.r_twr[i].left = 650;
        grc->twr.delay_atk[i] = 3.3;
    }
    events_my_towers3(grc, i);
}

void events_my_towers(grc_t *grc, sfEvent event, sfVector2i p_mouse)
{
    level_up(grc, p_mouse, event);
    for (int i = 0; i <= 5; i = i + 1) {
        if (event.type == sfEvtMouseButtonReleased
            && (grc->twr.status[i] == 0)
            && (p_mouse.x >= grc->twr.p_twr[i].x + 18)
            && (p_mouse.x <= grc->twr.p_twr[i].x + 132)
            && (p_mouse.y >= grc->twr.p_twr[i].y + 210)
            && (p_mouse.y <= grc->twr.p_twr[i].y + 282))
            grc->twr.status[i] = 1;
        if (grc->twr.status[i] == 1)
            construct_my_towers(grc, p_mouse, event, i);
        if (event.type == sfEvtMouseButtonPressed
            && (grc->twr.status[i] == 1)
            && ((p_mouse.x <= grc->twr.p_twr[i].x + 18)
                || (p_mouse.x >= grc->twr.p_twr[i].x + 132)
                || (p_mouse.y <= grc->twr.p_twr[i].y + 210)
                || (p_mouse.y >= grc->twr.p_twr[i].y + 282)))
            grc->twr.status[i] = 0;
        events_my_towers2(grc, i);
    }
}
