/*
** EPITECH PROJECT, 2019
** create_info_book
** File description:
** .c
*/

#include "my.h"

void create_book(grc_t *grc)
{
    grc->info.t_book = sfTexture_createFromFile("assets/menu/list_tower.png",
                                                NULL);
    grc->info.s_book = sfSprite_create();
    grc->info.p_book.x = 0;
    grc->info.p_book.y = 0;
    sfSprite_setTexture(grc->info.s_book, grc->info.t_book, sfTrue);
    sfSprite_setPosition(grc->info.s_book, grc->info.p_book);
}

void create_info_book(grc_t *grc)
{
    sfVector2f scale;

    grc->info.t_info = sfTexture_createFromFile("assets/game/towers.png",
                                                NULL);
    grc->info.s_info = sfSprite_create();
    grc->info.r_info.top = 140;
    grc->info.r_info.left = 62;
    grc->info.r_info.width = 130;
    grc->info.r_info.height = 200;
    grc->info.p_info.x = 1120;
    grc->info.p_info.y = 720;
    scale.x = 0.8;
    scale.y = 0.8;
    sfSprite_setScale(grc->info.s_info, scale);
    sfSprite_setTexture(grc->info.s_info, grc->info.t_info, sfTrue);
    sfSprite_setTextureRect(grc->info.s_info, grc->info.r_info);
    sfSprite_setPosition(grc->info.s_info, grc->info.p_info);
}

void event_info_book(grc_t *grc, sfVector2i p_mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->info.p_info.x)
        && (p_mouse.x <= grc->info.p_info.x + grc->info.r_info.width)
        && (p_mouse.y >= grc->info.p_info.y)
        && (p_mouse.y <= grc->info.p_info.y + grc->info.r_info.height)) {
        grc->info.r_info.left = 62;
        sfSprite_setTextureRect(grc->info.s_info, grc->info.r_info);
        grc->menu.util = 1;
    }
    else if ((p_mouse.x >= grc->info.p_info.x)
            && (p_mouse.x <= grc->info.p_info.x + grc->info.r_info.width)
            && (p_mouse.y >= grc->info.p_info.y)
            && (p_mouse.y <= grc->info.p_info.y + grc->info.r_info.height))
        grc->info.r_info.left = 255;
    else
        grc->info.r_info.left = 62;
    sfSprite_setTextureRect(grc->info.s_info, grc->info.r_info);
}

void event_my_info(grc_t *grc, sfRenderWindow *wdw, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
    events_arrow_book(grc, p_mouse, event, wdw);
    events_return_but(grc, p_mouse, event);
    grc->crsr.p_csr.x = p_mouse.x;
    grc->crsr.p_csr.y = p_mouse.y;
    sfSprite_setPosition(grc->crsr.s_csr, grc->crsr.p_csr);
}

void my_info(grc_t *grc, sfRenderWindow *wdw)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(wdw) && grc->menu.util == 1) {
        sfRenderWindow_drawSprite(wdw, grc->info.s_arr, NULL);
        sfRenderWindow_drawSprite(wdw, grc->info.s_book, NULL);
        sfRenderWindow_drawSprite(wdw, grc->info.s_arrow, NULL);
        sfRenderWindow_drawSprite(wdw, grc->info.s_ret, NULL);
        sfRenderWindow_drawSprite(wdw, grc->crsr.s_csr, NULL);
        if (sfRenderWindow_pollEvent(wdw, &event))
            event_my_info(grc, wdw, event);
        sfRenderWindow_display(wdw);
    }
}
