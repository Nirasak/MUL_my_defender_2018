/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** check life enemies
*/

#include "my.h"

void create_new_enemy(grc_t *grc, int j)
{
    grc->game.p_enm[j].x = 450;
    grc->game.p_enm[j].y = grc->game.p_enm[grc->game.memory].y
        - (rand() % 225 + 125);
    grc->game.status_enm[j] = 0;
    grc->life.hp[j] = grc->life.hp[grc->game.memory] + (rand() % 8 + 2);
    grc->game.count = grc->game.count + 1;
    if (grc->game.count % 6 == 0) {
        grc->life.hp[j] = grc->life.hp[j] + 50;
        grc->game.p_enm[j].y = grc->game.p_enm[j].y - 750;
    }
    sfSprite_setPosition(grc->game.s_enm, grc->game.p_enm[j]);
    grc->game.memory = j;
}

void check_enemies_life(grc_t *grc)
{
    for (int j = 0; j != 30; j = j + 1)
        if (grc->life.hp[j] <= 0) {
            grc->game.status_enm[j] = 4;
            grc->gold.gold = grc->gold.gold + 20;
            create_new_enemy(grc, j);
        }
}
