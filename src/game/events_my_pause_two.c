/*
** EPITECH PROJECT, 2019
** events_my_pause_two
** File description:
** .c
*/

#include "my.h"

void destroy_set_game(grc_t *grc)
{
    free(grc->game.p_enm);
    free(grc->game.r_enm);
    free(grc->game.status_enm);
    sfTexture_destroy(grc->game.t_map);
    sfSprite_destroy(grc->game.s_map);
    sfTexture_destroy(grc->game.t_enm);
    sfSprite_destroy(grc->game.s_enm);
    sfMusic_destroy(grc->game.s_music);
    sfSprite_destroy(grc->gold.s_gold);
    sfTexture_destroy(grc->gold.t_gold);
    sfText_destroy(grc->cl.text);
    sfFont_destroy(grc->cl.font);
}

void event_but_new(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->pause.p_new.x)
        && (p_mouse.x <= grc->pause.p_new.x + grc->pause.r_new.width)
        && (p_mouse.y >= grc->pause.p_new.y)
        && (p_mouse.y <= grc->pause.p_new.y + grc->pause.r_new.height)) {
        grc->menu.status = 1;
        grc->pause.r_new.left = 180;
        destroy_set_game(grc);
        create_my_map(grc);
        create_my_gold(grc);
        create_my_score(grc);
    } else if ((p_mouse.x >= grc->pause.p_new.x)
            && (p_mouse.x <= grc->pause.p_new.x + grc->pause.r_new.width)
            && (p_mouse.y >= grc->pause.p_new.y)
            && (p_mouse.y <= grc->pause.p_new.y + grc->pause.r_new.height))
        grc->pause.r_new.left = 500;
    else
        grc->pause.r_new.left = 180;
    sfSprite_setTextureRect(grc->pause.s_new, grc->pause.r_new);
}
