/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display my game
*/

#include "my.h"

void clocks_my_enemys(grc_t *grc)
{
    grc->game.time_enm = sfClock_getElapsedTime(grc->game.clock_enm);
    grc->game.scd_enm = grc->game.time_enm.microseconds / 190000.0f;
    grc->game.time_move = sfClock_getElapsedTime(grc->game.clock_move);
    grc->game.scd_move = grc->game.time_move.microseconds / 45000.0f;
}

void display_my_enm(grc_t *grc, sfRenderWindow *wdw)
{
    for (int j = 0; j != 30; j = j + 1) {
        if (grc->game.status_enm[j] == 0)
            going_down(grc, j);
        if (grc->game.status_enm[j] == 1)
            going_right(grc, j);
        if (grc->game.status_enm[j] == 2)
            going_up(grc, j);
        anim_my_enemys(grc, j);
        sfSprite_setTextureRect(grc->game.s_enm, grc->game.r_enm[j]);
        sfSprite_setPosition(grc->game.s_enm, grc->game.p_enm[j]);
        sfRenderWindow_drawSprite(wdw, grc->game.s_enm, NULL);
        grc->life.p_hp.x = grc->game.p_enm[j].x + 18;
        grc->life.p_hp.y = grc->game.p_enm[j].y - 30;
        sfText_setPosition(grc->life.txt_hp, grc->life.p_hp);
        sfText_setString(grc->life.txt_hp, my_itoa(grc->life.hp[j]));
        sfRenderWindow_drawText(wdw, grc->life.txt_hp, NULL);
        sfRenderWindow_drawSprite(wdw, grc->gold.s_gold, NULL);
        sfRenderWindow_drawText(wdw, grc->gold.txt_gold, NULL);
        anime_my_gold(grc);
    }
}

void display_my_game(grc_t *grc, sfRenderWindow *wdw)
{
    sfRenderWindow_drawSprite(wdw, grc->game.s_map, NULL);
    clocks_my_enemys(grc);
    display_my_enm(grc, wdw);
    display_my_towers(grc, wdw);
    if (grc->twr.status_price == 1) {
        sfRenderWindow_drawSprite(wdw, grc->twr.s_up, NULL);
        sfRenderWindow_drawText(wdw, grc->twr.txt_price, NULL);
    }
    if (grc->game.loose == 2)
        sfRenderWindow_close(wdw);
    sfRenderWindow_drawSprite(wdw, grc->crsr.s_csr, NULL);
}

void events_my_game(grc_t *grc, sfRenderWindow *wdw, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(wdw);

    check_lvl(grc, p_mouse, event);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
    grc->crsr.p_csr.x = p_mouse.x;
    grc->crsr.p_csr.y = p_mouse.y;
    sfSprite_setPosition(grc->crsr.s_csr, grc->crsr.p_csr);
    events_my_towers(grc, event, p_mouse);
    if (event.type == sfEvtKeyReleased &&
        event.key.code == sfKeyEscape)
        grc->menu.status = 3;
}
