/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create game
*/

#include "my.h"

void set_pos_tower(grc_t *grc)
{
    grc->twr.p_twr[0].x = 257;
    grc->twr.p_twr[0].y = 1;
    grc->twr.p_twr[1].x = 257;
    grc->twr.p_twr[1].y = 265;
    grc->twr.p_twr[2].x = 562;
    grc->twr.p_twr[2].y = 255;
    grc->twr.p_twr[3].x = 880;
    grc->twr.p_twr[3].y = 235;
    grc->twr.p_twr[4].x = 1130;
    grc->twr.p_twr[4].y = 235;
    grc->twr.p_twr[5].x = 1440;
    grc->twr.p_twr[5].y = 220;
}

void create_my_towers2(grc_t *grc)
{
    for (int i = 0; i <= 5; i = i + 1) {
        grc->twr.r_twr[i].top = 50;
        grc->twr.r_twr[i].left = 1050;
        grc->twr.r_twr[i].width = 150;
        grc->twr.r_twr[i].height = 300;
        grc->twr.status[i] = 0;
        grc->twr.clock_twr[i] = sfClock_create();
        grc->twr.scd_twr[i] = 0;
        grc->twr.lvl[i] = 1;
    }
    grc->twr.clock_twr[6] = sfClock_create();
    grc->twr.scd_twr[6] = 0;
    sfSprite_setTexture(grc->twr.s_twr, grc->twr.t_twr, sfTrue);
    sfSprite_setPosition(grc->twr.s_twr, grc->twr.p_twr[0]);
    sfSprite_setTextureRect(grc->twr.s_twr, grc->twr.r_twr[0]);
}

void create_my_towers(grc_t *grc)
{
    grc->twr.t_twr = sfTexture_createFromFile("assets/game/towers.png", NULL);
    grc->twr.s_twr = sfSprite_create();
    grc->twr.r_twr = malloc(sizeof(sfIntRect) * 7);
    grc->twr.p_twr = malloc(sizeof(sfVector2f) * 7);
    grc->twr.status = malloc(sizeof(int) * 7);
    grc->twr.clock_twr = malloc(sizeof(sfClock *) * 8);
    grc->twr.time_twr = malloc(sizeof(sfTime) * 8);
    grc->twr.scd_twr = malloc(sizeof(float) * 8);
    grc->twr.delay_atk = malloc(sizeof(float) * 7);
    grc->twr.lvl = malloc(sizeof(int) * 7);
    grc->game.speed = malloc(sizeof(float) * 4);
    grc->game.speed[0] = 0.37;
    grc->game.speed[1] = 0.368;
    grc->game.speed[2] = 0.37;
    grc->twr.status_price = 0;
    set_pos_tower(grc);
    create_my_towers2(grc);
}

void create_my_map(grc_t *grc)
{
    sfVector2f p_map = {0, 0};

    create_my_score(grc);
    create_my_enemy(grc);
    create_my_towers(grc);
    create_music_game(grc);
    grc->game.t_map = sfTexture_createFromFile("assets/map.png", NULL);
    grc->game.s_map = sfSprite_create();
    sfSprite_setTexture(grc->game.s_map, grc->game.t_map, sfTrue);
    sfSprite_setPosition(grc->game.s_map, p_map);
    grc->game.loose = 0;
    grc->game.slow = 0;
    grc->game.slow_enm = 0;
}
