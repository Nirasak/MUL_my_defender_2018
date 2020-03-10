/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create enemys
*/

#include "my.h"

void create_my_life(grc_t *grc)
{
    int set_hp = 100;

    grc->life.hp = malloc(sizeof(int) * 31);
    for (int i = 0; i != 30; i = i + 1) {
        grc->life.hp[i] = set_hp;
        set_hp = set_hp + (rand() % 8 + 2);
        if (i % 6 == 0 && i != 0)
            set_hp = set_hp + 50;
    }
    grc->life.f_hp = sfFont_createFromFile("assets/font/Jersey_554.ttf");
    grc->life.txt_hp = sfText_create();
    sfText_setFont(grc->life.txt_hp, grc->life.f_hp);
    sfText_setColor(grc->life.txt_hp, sfBlack);
    sfText_setCharacterSize(grc->life.txt_hp, 30);
    sfText_setPosition(grc->life.txt_hp, grc->game.p_enm[0]);
    sfText_setString(grc->life.txt_hp, my_itoa(grc->life.hp[0]));
}

void create_my_enemys2(grc_t *grc)
{
    for (int j = 0; j != 30; j = j + 1) {
        grc->game.p_enm[j].x = 450;
        grc->game.p_enm[j].y = grc->game.c;
        grc->game.r_enm[j].top = 25;
        grc->game.r_enm[j].left = 25;
        grc->game.r_enm[j].width = 70;
        grc->game.r_enm[j].height = 85;
        grc->game.status_enm[j] = 0;
        if (j % 6 == 0 && j != 0)
            grc->game.c = grc->game.c - 750;
        grc->game.c = grc->game.c - (rand() % 225 + 125);
    }
    grc->game.memory = 29;
    grc->game.count = 0;
}

void create_my_enemy(grc_t *grc)
{
    grc->game.c = -100;
    grc->game.t_enm = sfTexture_createFromFile("assets/game/enemys.png", NULL);
    grc->game.s_enm = sfSprite_create();
    grc->game.p_enm = malloc(sizeof(sfVector2f) * 31);
    grc->game.r_enm = malloc(sizeof(sfIntRect) * 31);
    grc->game.status_enm = malloc(sizeof(int) * 31);
    create_my_enemys2(grc);
    sfSprite_setTexture(grc->game.s_enm, grc->game.t_enm, sfTrue);
    sfSprite_setTextureRect(grc->game.s_enm, grc->game.r_enm[0]);
    sfSprite_setPosition(grc->game.s_enm, grc->game.p_enm[0]);
    grc->game.clock_enm = sfClock_create();
    grc->game.scd_enm = 0;
    grc->game.clock_move = sfClock_create();
    grc->game.scd_move = 0;
    create_my_life(grc);
}
