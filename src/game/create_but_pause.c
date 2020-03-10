/*
** EPITECH PROJECT, 2019
** create_but_pause
** File description:
** .c
*/

#include "my.h"

void create_but_all(grc_t *grc)
{
    grc->pause.t_but = sfTexture_createFromFile("assets/game/but.png", NULL);
    grc->pause.s_game = sfSprite_create();
    grc->pause.s_new = sfSprite_create();
    grc->pause.s_opt = sfSprite_create();
    grc->pause.s_menu = sfSprite_create();
    grc->pause.s_exit = sfSprite_create();
}

void create_but_new(grc_t *grc)
{
    grc->pause.r_new.top = 10;
    grc->pause.r_new.left = 180;
    grc->pause.r_new.width = 284;
    grc->pause.r_new.height = 108;
    grc->pause.p_new.x = 125;
    grc->pause.p_new.y = 125;
    sfSprite_setTexture(grc->pause.s_new, grc->pause.t_but, sfTrue);
    sfSprite_setTextureRect(grc->pause.s_new, grc->pause.r_new);
    sfSprite_setPosition(grc->pause.s_new, grc->pause.p_new);
}

void create_but_game(grc_t *grc)
{
    grc->pause.r_game.top = 125;
    grc->pause.r_game.left = 180;
    grc->pause.r_game.width = 284;
    grc->pause.r_game.height = 108;
    grc->pause.p_game.x = 430;
    grc->pause.p_game.y = 290;
    sfSprite_setTexture(grc->pause.s_game, grc->pause.t_but, sfTrue);
    sfSprite_setTextureRect(grc->pause.s_game, grc->pause.r_game);
    sfSprite_setPosition(grc->pause.s_game, grc->pause.p_game);
}

void create_but_opt(grc_t *grc)
{
    grc->pause.r_opt.top = 240;
    grc->pause.r_opt.left = 180;
    grc->pause.r_opt.width = 284;
    grc->pause.r_opt.height = 108;
    grc->pause.p_opt.x = 920;
    grc->pause.p_opt.y = 658;
    sfSprite_setTexture(grc->pause.s_opt, grc->pause.t_but, sfTrue);
    sfSprite_setTextureRect(grc->pause.s_opt, grc->pause.r_opt);
    sfSprite_setPosition(grc->pause.s_opt, grc->pause.p_opt);
}

void create_but_menu(grc_t *grc)
{
    grc->pause.r_menu.top = 360;
    grc->pause.r_menu.left = 180;
    grc->pause.r_menu.width = 284;
    grc->pause.r_menu.height = 108;
    grc->pause.p_menu.x = 883;
    grc->pause.p_menu.y = 300;
    sfSprite_setTexture(grc->pause.s_menu, grc->pause.t_but, sfTrue);
    sfSprite_setTextureRect(grc->pause.s_menu, grc->pause.r_menu);
    sfSprite_setPosition(grc->pause.s_menu, grc->pause.p_menu);
}
