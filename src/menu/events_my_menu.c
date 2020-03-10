/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** events menu
*/

#include "my.h"

void events_my_menu2(grc_t *grc, sfVector2i p_mouse, sfRenderWindow *wdw)
{
    if ((p_mouse.x >= grc->menu.p_play.x)
        && (p_mouse.x <= grc->menu.p_play.x + grc->menu.r_play.width)
        && (p_mouse.y >= grc->menu.p_play.y)
        && (p_mouse.y <= grc->menu.p_play.y + grc->menu.r_play.height)) {
        grc->menu.r_play.left = 500;
        grc->menu.status = 1;
    }
    if ((p_mouse.x >= grc->menu.p_opt.x)
        && (p_mouse.x <= grc->menu.p_opt.x + grc->menu.r_opt.width)
        && (p_mouse.y >= grc->menu.p_opt.y)
        && (p_mouse.y <= grc->menu.p_opt.y + grc->menu.r_opt.height)) {
        grc->menu.r_opt.left = 500;
        grc->menu.status = 2;
    }
    if ((p_mouse.x >= grc->menu.p_exit.x)
        && (p_mouse.x <= grc->menu.p_exit.x + grc->menu.r_exit.width)
        && (p_mouse.y >= grc->menu.p_exit.y)
        && (p_mouse.y <= grc->menu.p_exit.y + grc->menu.r_exit.height))
        sfRenderWindow_close(wdw);
}

void button_play(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed
        && (p_mouse.x >= grc->menu.p_play.x)
        && (p_mouse.x <= grc->menu.p_play.x + grc->menu.r_play.width)
        && (p_mouse.y >= grc->menu.p_play.y)
        && (p_mouse.y <= grc->menu.p_play.y + grc->menu.r_play.height))
        grc->menu.r_play.left = 900;
    else if ((p_mouse.x >= grc->menu.p_play.x)
            && (p_mouse.x <= grc->menu.p_play.x + grc->menu.r_play.width)
            && (p_mouse.y >= grc->menu.p_play.y)
            && (p_mouse.y <= grc->menu.p_play.y + grc->menu.r_play.height))
        grc->menu.r_play.left = 100;
    else
        grc->menu.r_play.left = 500;
}

void button_option(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed
        && (p_mouse.x >= grc->menu.p_opt.x)
        && (p_mouse.x <= grc->menu.p_opt.x + grc->menu.r_opt.width)
        && (p_mouse.y >= grc->menu.p_opt.y)
        && (p_mouse.y <= grc->menu.p_opt.y + grc->menu.r_opt.height))
        grc->menu.r_opt.left = 900;
    else if ((p_mouse.x >= grc->menu.p_opt.x)
             && (p_mouse.x <= grc->menu.p_opt.x + grc->menu.r_opt.width)
             && (p_mouse.y >= grc->menu.p_opt.y)
             && (p_mouse.y <= grc->menu.p_opt.y + grc->menu.r_opt.height))
        grc->menu.r_opt.left = 100;
    else
        grc->menu.r_opt.left = 500;
}

void button_exit(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed
        && (p_mouse.x >= grc->menu.p_exit.x)
        && (p_mouse.x <= grc->menu.p_exit.x + grc->menu.r_exit.width)
        && (p_mouse.y >= grc->menu.p_exit.y)
        && (p_mouse.y <= grc->menu.p_exit.y + grc->menu.r_exit.height))
        grc->menu.r_exit.left = 900;
    else if ((p_mouse.x >= grc->menu.p_exit.x)
            && (p_mouse.x <= grc->menu.p_exit.x + grc->menu.r_exit.width)
            && (p_mouse.y >= grc->menu.p_exit.y)
            && (p_mouse.y <= grc->menu.p_exit.y + grc->menu.r_exit.height))
        grc->menu.r_exit.left = 100;
    else
         grc->menu.r_exit.left = 500;
}

void events_my_menu(grc_t *grc, sfRenderWindow *wdw, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
    button_play(grc, p_mouse, event);
    button_option(grc, p_mouse, event);
    button_exit(grc, p_mouse, event);
    if (event.type == sfEvtMouseButtonReleased)
        events_my_menu2(grc, p_mouse, wdw);
    grc->crsr.p_csr.x = p_mouse.x;
    grc->crsr.p_csr.y = p_mouse.y;
    sfSprite_setPosition(grc->crsr.s_csr, grc->crsr.p_csr);
    sfSprite_setTextureRect(grc->menu.s_play, grc->menu.r_play);
    sfSprite_setTextureRect(grc->menu.s_opt, grc->menu.r_opt);
    sfSprite_setTextureRect(grc->menu.s_exit, grc->menu.r_exit);
}
