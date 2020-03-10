/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create options
*/

#include "my.h"

void create_my_cursor(grc_t *grc)
{
    sfVector2f pos_cursor = {66 / 2, 64 / 2};

    grc->crsr.t_csr = sfTexture_createFromFile("assets/menu/cursors.png", NULL);
    grc->crsr.s_csr = sfSprite_create();
    grc->crsr.r_csr.top = 18;
    grc->crsr.r_csr.left = 17;
    grc->crsr.r_csr.width = 66;
    grc->crsr.r_csr.height = 64;
    sfSprite_setTexture(grc->crsr.s_csr, grc->crsr.t_csr, sfTrue);
    sfSprite_setTextureRect(grc->crsr.s_csr, grc->crsr.r_csr);
    sfSprite_setOrigin(grc->crsr.s_csr, pos_cursor);
}

void create_my_options2(grc_t *grc)
{
    grc->opt.s_back = sfSprite_create();
    grc->opt.r_back.top = 140;
    grc->opt.r_back.left = 20;
    grc->opt.r_back.width = 194;
    grc->opt.r_back.height = 60;
    grc->opt.p_back.x = 60;
    grc->opt.p_back.y = 930;
    sfSprite_setTexture(grc->opt.s_back, grc->opt.t_but, sfTrue);
    sfSprite_setPosition(grc->opt.s_back, grc->opt.p_back);
    sfSprite_setTextureRect(grc->opt.s_back, grc->opt.r_back);
    create_my_cursor(grc);
}

void create_my_options(grc_t *grc)
{
    sfVector2f p_opt = {0, 0};

    grc->opt.t_opt = sfTexture_createFromFile("assets/menu/options.png", NULL);
    grc->opt.s_opt = sfSprite_create();
    sfSprite_setTexture(grc->opt.s_opt, grc->opt.t_opt, sfTrue);
    sfSprite_setPosition(grc->opt.s_opt, p_opt);
    grc->opt.t_but = sfTexture_createFromFile("assets/menu/but_opt.png", NULL);
    grc->opt.s_vol = sfSprite_create();
    grc->opt.r_vol.top = 100;
    grc->opt.r_vol.left = 20;
    grc->opt.r_vol.width = 10;
    grc->opt.r_vol.height = 21;
    grc->opt.p_vol.x = 970;
    grc->opt.p_vol.y = 252;
    sfSprite_setTexture(grc->opt.s_vol, grc->opt.t_but, sfTrue);
    sfSprite_setPosition(grc->opt.s_vol, grc->opt.p_vol);
    sfSprite_setTextureRect(grc->opt.s_vol, grc->opt.r_vol);
    create_my_options2(grc);
}
