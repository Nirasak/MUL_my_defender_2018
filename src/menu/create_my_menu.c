/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create menu
*/

#include "my.h"

void create_bckgrnd_menu(grc_t *grc)
{
    create_music_menu(grc);
    grc->menu.t_menu = sfTexture_createFromFile("assets/menu/menu_dfdr.png",
                                                NULL);
    grc->menu.s_menu = sfSprite_create();
    sfSprite_setTexture(grc->menu.s_menu, grc->menu.t_menu, sfTrue);
    grc->menu.t_but = sfTexture_createFromFile("assets/menu/buttons_menu.png",
                                                NULL);
    grc->menu.s_play = sfSprite_create();
    grc->menu.s_opt = sfSprite_create();
    grc->menu.s_exit = sfSprite_create();
    grc->menu.status = 0;
}

void create_my_play(grc_t *grc)
{
    grc->menu.p_play.x = 750;
    grc->menu.p_play.y = 350;
    grc->menu.r_play.top = 100;
    grc->menu.r_play.left = 500;
    grc->menu.r_play.width = 332;
    grc->menu.r_play.height = 73;
    sfSprite_setTexture(grc->menu.s_play, grc->menu.t_but, sfTrue);
    sfSprite_setTextureRect(grc->menu.s_play, grc->menu.r_play);
    sfSprite_setPosition(grc->menu.s_play, grc->menu.p_play);
}

void create_my_opt(grc_t *grc)
{
    grc->menu.util = 0;
    grc->menu.p_opt.x = 750;
    grc->menu.p_opt.y = 468;
    grc->menu.r_opt.top = 218;
    grc->menu.r_opt.left = 500;
    grc->menu.r_opt.width = 332;
    grc->menu.r_opt.height = 74;
    sfSprite_setTexture(grc->menu.s_opt, grc->menu.t_but, sfTrue);
    sfSprite_setTextureRect(grc->menu.s_opt, grc->menu.r_opt);
    sfSprite_setPosition(grc->menu.s_opt, grc->menu.p_opt);
}

void create_my_exit(grc_t *grc)
{
    grc->menu.p_exit.x = 750;
    grc->menu.p_exit.y = 587;
    grc->menu.r_exit.top = 337;
    grc->menu.r_exit.left = 500;
    grc->menu.r_exit.width = 332;
    grc->menu.r_exit.height = 75;
    sfSprite_setTexture(grc->menu.s_exit, grc->menu.t_but, sfTrue);
    sfSprite_setTextureRect(grc->menu.s_exit, grc->menu.r_exit);
    sfSprite_setPosition(grc->menu.s_exit, grc->menu.p_exit);
}

void create_my_menu(grc_t *grc)
{
    create_bckgrnd_menu(grc);
    create_my_play(grc);
    create_my_opt(grc);
    create_my_exit(grc);
}
