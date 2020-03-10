/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** construct towers
*/

#include "my.h"

void construct_my_towers4(grc_t *grc, sfVector2i p_mouse, sfEvent event, int i)
{
    if ((p_mouse.x >= grc->twr.p_twr[i].x + 96)
        && (p_mouse.x <= grc->twr.p_twr[i].x + 146)
        && (p_mouse.y >= grc->twr.p_twr[i].y + 239)
        && (p_mouse.y <= grc->twr.p_twr[i].y + 297)) {
        grc->twr.r_twr[i].left = 850;
        grc->twr.r_twr[i].top = 750;
        if (event.type == sfEvtMouseButtonPressed && grc->gold.gold >= 125) {
            grc->twr.status[i] = 5;
            grc->gold.gold = grc->gold.gold - 125;
        }
    }
}

void construct_my_towers3(grc_t *grc, sfVector2i p_mouse, sfEvent event, int i)
{
    if ((p_mouse.x >= grc->twr.p_twr[i].x + 5)
        && (p_mouse.x <= grc->twr.p_twr[i].x + 55)
        && (p_mouse.y >= grc->twr.p_twr[i].y + 239)
        && (p_mouse.y <= grc->twr.p_twr[i].y + 299)) {
        grc->twr.r_twr[i].left = 850;
        grc->twr.r_twr[i].top = 1100;
        if (event.type == sfEvtMouseButtonPressed && grc->gold.gold >= 100) {
            grc->twr.status[i] = 4;
            grc->gold.gold = grc->gold.gold - 100;
        }
    } else
        construct_my_towers4(grc, p_mouse, event, i);
}

void construct_my_towers2(grc_t *grc, sfVector2i p_mouse, sfEvent event, int i)
{
    if ((p_mouse.x >= grc->twr.p_twr[i].x + 95)
        && (p_mouse.x <= grc->twr.p_twr[i].x + 145)
        && (p_mouse.y >= grc->twr.p_twr[i].y + 155)
        && (p_mouse.y <= grc->twr.p_twr[i].y + 212)) {
        grc->twr.r_twr[i].left = 850;
        grc->twr.r_twr[i].top = 400;
        if (event.type == sfEvtMouseButtonPressed && grc->gold.gold >= 50) {
            grc->twr.status[i] = 3;
            grc->gold.gold = grc->gold.gold - 50;
        }
    } else
        construct_my_towers3(grc, p_mouse, event, i);
}

void construct_my_towers(grc_t *grc, sfVector2i p_mouse, sfEvent event, int i)
{
    grc->twr.r_twr[i].top = 400;
    grc->twr.r_twr[i].left = 1050;
    if ((p_mouse.x >= grc->twr.p_twr[i].x + 4)
        && (p_mouse.x <= grc->twr.p_twr[i].x + 54)
        && (p_mouse.y >= grc->twr.p_twr[i].y + 155)
        && (p_mouse.y <= grc->twr.p_twr[i].y + 212)) {
        grc->twr.r_twr[i].left = 850;
        grc->twr.r_twr[i].top = 50;
        if (event.type == sfEvtMouseButtonPressed && grc->gold.gold >= 75) {
            grc->twr.status[i] = 2;
            grc->gold.gold = grc->gold.gold - 75;
        }
    } else
        construct_my_towers2(grc, p_mouse, event, i);
}
