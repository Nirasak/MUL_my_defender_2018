/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display my enemys
*/

#include "my.h"

void slowmotion(grc_t *grc, int j)
{
    if (grc->game.slow >= 1 && grc->game.slow <= 10 && j == grc->game.slow_enm
        && grc->game.status_enm[grc->game.slow_enm] == 0) {
        grc->game.p_enm[grc->game.slow_enm].y
            = grc->game.p_enm[grc->game.slow_enm].y - 3;
        grc->game.slow = grc->game.slow + 1;
    }
    if (grc->game.slow >= 1 && grc->game.slow <= 10 && j == grc->game.slow_enm
        && grc->game.status_enm[grc->game.slow_enm] == 1) {
        grc->game.p_enm[grc->game.slow_enm].x
            = grc->game.p_enm[grc->game.slow_enm].x - 3;
        grc->game.slow = grc->game.slow + 1;
    }
    if (grc->game.slow >= 1 && grc->game.slow <= 10 && j == grc->game.slow_enm
        && grc->game.status_enm[grc->game.slow_enm] == 2) {
        grc->game.p_enm[grc->game.slow_enm].y
            = grc->game.p_enm[grc->game.slow_enm].y + 3;
        grc->game.slow = grc->game.slow + 1;
    }
}

void anim_my_enemys(grc_t *grc, int j)
{
    if (grc->game.scd_enm > 1) {
        if (grc->game.r_enm[j].left < 375 && grc->game.slow == 0)
            grc->game.r_enm[j].left = grc->game.r_enm[j].left + 96;
        else if (grc->game.r_enm[j].left >= 375)
            grc->game.r_enm[j].left = 25;
        sfClock_restart(grc->game.clock_enm);
    }
}

void going_down(grc_t *grc, int j)
{
    grc->game.r_enm[j].top = 25;
    if (grc->game.scd_move > grc->game.speed[0]) {
        if (grc->game.p_enm[j].y > 585 && grc->game.p_enm[j].x == 450)
            grc->game.status_enm[j] = 1;
        else if (grc->game.p_enm[j].y > 1080) {
            grc->game.loose =  grc->game.loose + 1;
        } else {
            grc->game.p_enm[j].y = grc->game.p_enm[j].y + 3;
            slowmotion(grc, j);
        }
        sfClock_restart(grc->game.clock_move);
    }
    if (grc->game.slow == 10)
        grc->game.slow = 0;
}

void going_right(grc_t *grc, int j)
{
    grc->game.r_enm[j].top = 218;
    if (grc->game.scd_move > grc->game.speed[1]) {
        if (grc->game.p_enm[j].x > 760 && grc->game.p_enm[j].y > 585)
            grc->game.status_enm[j] = 2;
        else if (grc->game.p_enm[j].y < 320 && grc->game.p_enm[j].x > 1325)
            grc->game.status_enm[j] = 0;
        else {
            grc->game.p_enm[j].x = grc->game.p_enm[j].x + 3;
            slowmotion(grc, j);
        }
        sfClock_restart(grc->game.clock_move);
    }
    if (grc->game.slow == 10)
        grc->game.slow = 0;
}

void going_up(grc_t *grc, int j)
{
    grc->game.r_enm[j].top = 317;
    if (grc->game.scd_move > grc->game.speed[2]) {
        if (grc->game.p_enm[j].y < 320)
            grc->game.status_enm[j] = 1;
        else {
            grc->game.p_enm[j].y = grc->game.p_enm[j].y - 3;
            slowmotion(grc, j);
        }
        sfClock_restart(grc->game.clock_move);
    }
    if (grc->game.slow == 10)
        grc->game.slow = 0;
}
