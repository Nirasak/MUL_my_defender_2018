/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** damage to enemys
*/

#include "my.h"

void tower4(grc_t *grc, int i)
{
    int stop = 0;

    for (int j = 0; stop == 0 && j != 30; j = j + 1) {
        if (grc->game.p_enm[j].x >= grc->twr.p_twr[i].x
            + grc->twr.r_twr[i].width / 2 - 200
            && grc->game.p_enm[j].x <= grc->twr.p_twr[i].x
            + grc->twr.r_twr[i].width / 2 + 200
            && grc->game.p_enm[j].y >= grc->twr.p_twr[i].y
            + grc->twr.r_twr[i].height / 2 - 75
            && grc->game.p_enm[j].y <= grc->twr.p_twr[i].y
            + grc->twr.r_twr[i].height / 2 + 150) {
            stop = 1;
            grc->life.hp[j] = grc->life.hp[j] - (15 + 15 * grc->twr.lvl[i]);
            damage_continue(grc, j, i);
            sfClock_restart(grc->twr.clock_twr[i]);
        }
    }
}

void tower3(grc_t *grc, int i)
{
    int stop = 0;

    for (int j = 0; stop == 0 && j != 30; j = j + 1) {
        if (grc->game.p_enm[j].x >= grc->twr.p_twr[i].x
            + grc->twr.r_twr[i].width / 2 - 200
            && grc->game.p_enm[j].x <= grc->twr.p_twr[i].x
            + grc->twr.r_twr[i].width / 2 + 200
            && grc->game.p_enm[j].y >= grc->twr.p_twr[i].y
            + grc->twr.r_twr[i].height / 2 - 75
            && grc->game.p_enm[j].y <= grc->twr.p_twr[i].y
            + grc->twr.r_twr[i].height / 4 + 150) {
            stop = 1;
            grc->game.slow = 1;
            grc->game.slow_enm = j;
            grc->life.hp[j] = grc->life.hp[j] - (6 + 11 * grc->twr.lvl[i]);
            sfClock_restart(grc->twr.clock_twr[i]);
        }
    }
}

void tower2(grc_t *grc, int i)
{
    int stop = 0;

    for (int j = 0; stop == 0 && j != 30; j = j + 1) {
        if (grc->game.p_enm[j].x >= grc->twr.p_twr[i].x
            + grc->twr.r_twr[i].width / 2 - 200
            && grc->game.p_enm[j].x <= grc->twr.p_twr[i].x
            + grc->twr.r_twr[i].width / 2 + 200
            && grc->game.p_enm[j].y >= grc->twr.p_twr[i].y
            + grc->twr.r_twr[i].height / 2 - 125
            && grc->game.p_enm[j].y <= grc->twr.p_twr[i].y
            + grc->twr.r_twr[i].height / 2 + 200) {
            stop = 1;
            grc->life.hp[j] = grc->life.hp[j] - (6 + 11 * grc->twr.lvl[j]);
            sfClock_restart(grc->twr.clock_twr[i]);
        }
    }
}

void tower1(grc_t *grc, int i)
{
    int stop = 0;

    for (int j = 0; stop == 0 && j != 30; j = j + 1) {
        if (grc->game.p_enm[j].x >= grc->twr.p_twr[i].x
            + grc->twr.r_twr[i].width / 2 - 200
            && grc->game.p_enm[j].x <= grc->twr.p_twr[i].x
            + grc->twr.r_twr[i].width / 2 + 200
            && grc->game.p_enm[j].y >= grc->twr.p_twr[i].y
            + grc->twr.r_twr[i].height / 2 - 75
            && grc->game.p_enm[j].y <= grc->twr.p_twr[i].y
            + grc->twr.r_twr[i].height / 2 + 150) {
            stop = 1;
            grc->life.hp[j] = grc->life.hp[j] - (9 + 11 * grc->twr.lvl[i]);
            sfClock_restart(grc->twr.clock_twr[i]);
        }
    }
}

void damage_to_enemies(grc_t *grc)
{
    check_enemies_life(grc);
    for (int i = 0; i <= 5; i = i + 1) {
        if (grc->twr.status[i] == 2
            && grc->twr.delay_atk[i] <= grc->twr.scd_twr[i])
            tower1(grc, i);
        if (grc->twr.status[i] == 3
            && grc->twr.delay_atk[i] <= grc->twr.scd_twr[i])
            tower2(grc, i);
        if (grc->twr.status[i] == 4
            && grc->twr.delay_atk[i] <= grc->twr.scd_twr[i])
            tower3(grc, i);
        if (grc->twr.status[i] == 5
            && grc->twr.delay_atk[i] <= grc->twr.scd_twr[i])
            tower4(grc, i);
    }
}
