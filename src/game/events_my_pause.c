/*
** EPITECH PROJECT, 2019
** events_my_pause
** File description:
** .c
*/

#include "my.h"

void event_but_game(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->pause.p_game.x)
        && (p_mouse.x <= grc->pause.p_game.x + grc->pause.r_game.width)
        && (p_mouse.y >= grc->pause.p_game.y)
        && (p_mouse.y <= grc->pause.p_game.y + grc->pause.r_game.height)) {
        grc->pause.r_game.left = 180;
        grc->menu.status = 1;
    } else if ((p_mouse.x >= grc->pause.p_game.x)
             && (p_mouse.x <= grc->pause.p_game.x + grc->pause.r_game.width)
             && (p_mouse.y >= grc->pause.p_game.y)
             && (p_mouse.y <= grc->pause.p_game.y + grc->pause.r_game.height))
        grc->pause.r_game.left = 500;
    else
        grc->pause.r_game.left = 180;
    sfSprite_setTextureRect(grc->pause.s_game, grc->pause.r_game);
}

void event_but_exit(grc_t *grc, sfVector2i p_mouse, sfEvent event,
                    sfRenderWindow *wdw)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->pause.p_exit.x)
        && (p_mouse.x <= grc->pause.p_exit.x + grc->pause.r_exit.width)
        && (p_mouse.y >= grc->pause.p_exit.y)
        && (p_mouse.y <= grc->pause.p_exit.y + grc->pause.r_exit.height)) {
        grc->pause.r_exit.left = 180;
        sfRenderWindow_close(wdw);
    } else if ((p_mouse.x >= grc->pause.p_exit.x)
             && (p_mouse.x <= grc->pause.p_exit.x + grc->pause.r_exit.width)
             && (p_mouse.y >= grc->pause.p_exit.y)
             && (p_mouse.y <= grc->pause.p_exit.y + grc->pause.r_exit.height))
        grc->pause.r_exit.left = 500;
    else
        grc->pause.r_exit.left = 184;
    sfSprite_setTextureRect(grc->pause.s_exit, grc->pause.r_exit);
}

void event_but_menu(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->pause.p_menu.x)
        && (p_mouse.x <= grc->pause.p_menu.x + grc->pause.r_menu.width)
        && (p_mouse.y >= grc->pause.p_menu.y)
        && (p_mouse.y <= grc->pause.p_menu.y + grc->pause.r_menu.height)) {
        grc->pause.r_menu.left = 180;
        grc->menu.status = 0;
        destroy_set_game(grc);
        create_my_map(grc);
    } else if ((p_mouse.x >= grc->pause.p_menu.x)
             && (p_mouse.x <= grc->pause.p_menu.x + grc->pause.r_menu.width)
             && (p_mouse.y >= grc->pause.p_menu.y)
             && (p_mouse.y <= grc->pause.p_menu.y + grc->pause.r_menu.height))
        grc->pause.r_menu.left = 500;
    else
        grc->pause.r_menu.left = 180;
    sfSprite_setTextureRect(grc->pause.s_menu, grc->pause.r_menu);
}

void event_but_opt(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->pause.p_opt.x)
        && (p_mouse.x <= grc->pause.p_opt.x + grc->pause.r_opt.width)
        && (p_mouse.y >= grc->pause.p_opt.y)
        && (p_mouse.y <= grc->pause.p_opt.y + grc->pause.r_opt.height)) {
        grc->pause.r_opt.left = 180;
        grc->menu.status = 4;
    } else if ((p_mouse.x >= grc->pause.p_opt.x)
             && (p_mouse.x <= grc->pause.p_opt.x + grc->pause.r_opt.width)
             && (p_mouse.y >= grc->pause.p_opt.y)
             && (p_mouse.y <= grc->pause.p_opt.y + grc->pause.r_opt.height))
        grc->pause.r_opt.left = 500;
    else
        grc->pause.r_opt.left = 180;
    sfSprite_setTextureRect(grc->pause.s_opt, grc->pause.r_opt);
}

void events_my_pause(grc_t *grc, sfRenderWindow *wdw, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
    event_but_game(grc, p_mouse, event);
    event_but_exit(grc, p_mouse, event, wdw);
    event_but_menu(grc, p_mouse, event);
    event_but_opt(grc, p_mouse, event);
    event_but_new(grc, p_mouse, event);
    grc->crsr.p_csr.x = p_mouse.x;
    grc->crsr.p_csr.y = p_mouse.y;
    sfSprite_setPosition(grc->crsr.s_csr, grc->crsr.p_csr);
}
