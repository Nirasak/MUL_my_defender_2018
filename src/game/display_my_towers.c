/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display towers
*/

#include "my.h"

void check_lvl_towers(grc_t *grc, sfRenderWindow *wdw)
{
    int lvl = 0;

    for (int i = 0; i <= 5; i = i + 1) {
        if (grc->twr.lvl[i] == 4)
            lvl = lvl + 1;
    }
    if (lvl == 6) {
        sfRenderWindow_close(wdw);
        my_printf("Congrats, you won\n");
    }
}

void up_speed_enemies(grc_t *grc)
{
    if (grc->twr.scd_twr[6] >= 10) {
        grc->game.speed[0] = grc->game.speed[0] - 0.005;
        grc->game.speed[1] = grc->game.speed[1] - 0.005;
        grc->game.speed[2] = grc->game.speed[2] - 0.005;
        sfClock_restart(grc->twr.clock_twr[6]);
    }
}

void set_delay_damage_towers(grc_t *grc)
{
    for (int i = 0; i <= 6; i = i + 1) {
        grc->twr.time_twr[i] = sfClock_getElapsedTime(grc->twr.clock_twr[i]);
        grc->twr.scd_twr[i] = grc->twr.time_twr[i].microseconds / 100000.0f;
    }
}

void display_my_towers(grc_t *grc, sfRenderWindow *wdw)
{
    set_delay_damage_towers(grc);
    for (int i = 0; i <= 5; i = i + 1) {
        sfSprite_setPosition(grc->twr.s_twr, grc->twr.p_twr[i]);
        sfSprite_setTextureRect(grc->twr.s_twr, grc->twr.r_twr[i]);
        sfRenderWindow_drawSprite(wdw, grc->twr.s_twr, NULL);
    }
    check_lvl_towers(grc, wdw);
}
