/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display options
*/

#include "my.h"

void display_my_options(grc_t *grc, sfRenderWindow *wdw)
{
    sfRenderWindow_drawSprite(wdw, grc->opt.s_opt, NULL);
    sfRenderWindow_drawSprite(wdw, grc->opt.s_back, NULL);
    sfRenderWindow_drawSprite(wdw, grc->opt.s_vol, NULL);
    sfRenderWindow_drawSprite(wdw, grc->info.s_info, NULL);
    sfRenderWindow_drawSprite(wdw, grc->crsr.s_csr, NULL);
}

void my_volume(grc_t *grc, sfRenderWindow *wdw, sfVector2i p_mouse)
{
    int i = 1;
    sfEvent event;

    while (i != 0) {
        p_mouse = sfMouse_getPositionRenderWindow(wdw);
        grc->crsr.p_csr.x = p_mouse.x;
        grc->crsr.p_csr.y = p_mouse.y;
        sfSprite_setPosition(grc->crsr.s_csr, grc->crsr.p_csr);
        if (sfRenderWindow_pollEvent(wdw, &event))
            i = event_my_volume(event);
        if (p_mouse.x >= 835 && p_mouse.x <= 1110)
            grc->opt.p_vol.x = p_mouse.x - 5;
        display_my_options(grc, wdw);
        sfSprite_setPosition(grc->opt.s_vol, grc->opt.p_vol);
        sfRenderWindow_display(wdw);
    }
    sfMusic_setVolume(grc->game.s_music, (grc->opt.p_vol.x - 830) / 3);
    sfMusic_setVolume(grc->menu.s_music, (grc->opt.p_vol.x - 830) / 3);
}

void events_my_cursor(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed
        && (p_mouse.x >= 726 && p_mouse.x <= 754)
        && (p_mouse.y >= 432 && p_mouse.y <= 470))
        grc->crsr.r_csr.left = 17;
    if (event.type == sfEvtMouseButtonPressed
        && (p_mouse.x >= 884 && p_mouse.x <= 927)
        && (p_mouse.y >= 430 && p_mouse.y <= 470))
        grc->crsr.r_csr.left = 167;
    if (event.type == sfEvtMouseButtonPressed
        && (p_mouse.x >= 1047 && p_mouse.x <= 1089)
        && (p_mouse.y >= 430 && p_mouse.y <= 469))
        grc->crsr.r_csr.left = 367;
    sfSprite_setTextureRect(grc->crsr.s_csr, grc->crsr.r_csr);
}

void events_my_options2(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->opt.p_back.x)
        && (p_mouse.x <= grc->opt.p_back.x + grc->opt.r_back.width)
        && (p_mouse.y >= grc->opt.p_back.y)
        && (p_mouse.y <= grc->opt.p_back.y + grc->opt.r_back.height)) {
        grc->opt.r_back.left = 20;
        if (grc->menu.status == 2)
            grc->menu.status = 0;
        if (grc->menu.status == 4)
            grc->menu.status = 3;
    } else if ((p_mouse.x >= grc->opt.p_back.x)
            && (p_mouse.x <= grc->opt.p_back.x + grc->opt.r_back.width)
            && (p_mouse.y >= grc->opt.p_back.y)
            && (p_mouse.y <= grc->opt.p_back.y + grc->opt.r_back.height))
        grc->opt.r_back.left = 230;
    else
        grc->opt.r_back.left = 20;
    sfSprite_setTextureRect(grc->opt.s_back, grc->opt.r_back);
    event_info_book(grc, p_mouse, event);
}

void events_my_options(grc_t *grc, sfRenderWindow *wdw, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(wdw);

    grc->crsr.p_csr.x = p_mouse.x;
    grc->crsr.p_csr.y = p_mouse.y;
    sfSprite_setPosition(grc->crsr.s_csr, grc->crsr.p_csr);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
    if (event.type == sfEvtMouseButtonPressed
        && (p_mouse.y >= grc->opt.p_vol.y - 4)
        && (p_mouse.y <= grc->opt.p_vol.y + grc->opt.r_vol.height + 4)
        && (p_mouse.x >= 835 && p_mouse.x <= 1105))
        grc->opt.p_vol.x = p_mouse.x - 5;
    if (event.type == sfEvtMouseButtonPressed
        && (p_mouse.x >= grc->opt.p_vol.x)
        && (p_mouse.x <= grc->opt.p_vol.x + grc->opt.r_vol.width)
        && (p_mouse.y >= grc->opt.p_vol.y - 4)
        && (p_mouse.y <= grc->opt.p_vol.y + grc->opt.r_vol.height + 4))
        my_volume(grc, wdw, p_mouse);
    events_my_options2(grc, p_mouse, event);
    events_my_cursor(grc, p_mouse, event);
}
