/*
** EPITECH PROJECT, 2019
** destroyç_all
** File description:
** .c
*/

#include "my.h"

void free_all(grc_t *grc)
{
    free(grc->life.hp);
    free(grc->game.r_enm);
    free(grc->game.p_enm);
    free(grc->game.speed);
    free(grc->game.status_enm);
    free(grc->twr.r_twr);
    free(grc->twr.p_twr);
    free(grc->twr.status);
    free(grc->twr.clock_twr);
    free(grc->twr.time_twr);
    free(grc->twr.scd_twr);
    free(grc->twr.delay_atk);
    free(grc->twr.lvl);
}

void destroy_all3(grc_t *grc)
{
    sfTexture_destroy(grc->crsr.t_csr);
    sfSprite_destroy(grc->crsr.s_csr);
    sfTexture_destroy(grc->game.t_enm);
    sfSprite_destroy(grc->game.s_enm);
    sfTexture_destroy(grc->pause.t_pause);
    sfSprite_destroy(grc->pause.s_pause);
    sfTexture_destroy(grc->pause.t_but);
    sfSprite_destroy(grc->pause.s_game);
    sfSprite_destroy(grc->pause.s_new);
    sfSprite_destroy(grc->pause.s_opt);
    sfSprite_destroy(grc->pause.s_exit);
    sfSprite_destroy(grc->pause.s_menu);
    sfTexture_destroy(grc->twr.t_twr);
    sfSprite_destroy(grc->twr.s_twr);
    sfTexture_destroy(grc->twr.t_up);
    sfSprite_destroy(grc->twr.s_up);
    sfText_destroy(grc->twr.txt_price);
    sfFont_destroy(grc->twr.f_price);
}

void destroy_all2(grc_t *grc)
{
    sfTexture_destroy(grc->gold.t_gold);
    sfSprite_destroy(grc->gold.s_gold);
    sfText_destroy(grc->gold.txt_gold);
    sfFont_destroy(grc->gold.f_gold);
    sfText_destroy(grc->life.txt_hp);
    sfFont_destroy(grc->life.f_hp);
    sfTexture_destroy(grc->info.t_info);
    sfSprite_destroy(grc->info.s_info);
    sfTexture_destroy(grc->info.t_book);
    sfSprite_destroy(grc->info.s_book);
    sfTexture_destroy(grc->info.t_arrow);
    sfSprite_destroy(grc->info.s_arrow);
    sfTexture_destroy(grc->info.t_next);
    sfSprite_destroy(grc->info.s_next);
    sfTexture_destroy(grc->info.t_arr);
    sfSprite_destroy(grc->info.s_arr);
    sfTexture_destroy(grc->info.t_ret);
    sfSprite_destroy(grc->info.s_ret);
    destroy_all3(grc);
}

void destroy_all(grc_t *grc)
{
    free_all(grc);
    sfSprite_destroy(grc->menu.s_menu);
    sfTexture_destroy(grc->menu.t_menu);
    sfTexture_destroy(grc->menu.t_but);
    sfSprite_destroy(grc->menu.s_play);
    sfSprite_destroy(grc->menu.s_opt);
    sfSprite_destroy(grc->menu.s_exit);
    sfTexture_destroy(grc->opt.t_opt);
    sfSprite_destroy(grc->opt.s_opt);
    sfTexture_destroy(grc->opt.t_but);
    sfSprite_destroy(grc->opt.s_vol);
    sfSprite_destroy(grc->opt.s_back);
    sfTexture_destroy(grc->game.t_map);
    sfSprite_destroy(grc->game.s_map);
    sfMusic_destroy(grc->menu.s_music);
    sfMusic_destroy(grc->game.s_music);
    sfText_destroy(grc->cl.text);
    sfFont_destroy(grc->cl.font);
    destroy_all2(grc);
}
