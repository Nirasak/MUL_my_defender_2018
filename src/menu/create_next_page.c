/*
** EPITECH PROJECT, 2019
** create_next_page
** File description:
** .c
*/

#include "my.h"

void create_next_button(grc_t *grc)
{
    grc->info.t_next = sfTexture_createFromFile("assets/menu/book.png",
                                                NULL);
    grc->info.s_next = sfSprite_create();
    sfSprite_setTexture(grc->info.s_next, grc->info.t_next, sfTrue);
}

void create_arrow_book(grc_t *grc)
{
    grc->info.t_arrow = sfTexture_createFromFile("assets/menu/arrow_book.png",
                                                NULL);
    grc->info.s_arrow = sfSprite_create();
    grc->info.r_arrow.top = 6;
    grc->info.r_arrow.left = 7;
    grc->info.r_arrow.width = 87;
    grc->info.r_arrow.height = 79;
    grc->info.p_arrow.x = 1520;
    grc->info.p_arrow.y = 800;
    sfSprite_setTexture(grc->info.s_arrow, grc->info.t_arrow, sfTrue);
    sfSprite_setTextureRect(grc->info.s_arrow, grc->info.r_arrow);
    sfSprite_setPosition(grc->info.s_arrow, grc->info.p_arrow);
}

void events_arrow_book(grc_t *grc, sfVector2i p_mouse, sfEvent event,
                        sfRenderWindow *wdw)
{
    if (event.type == sfEvtMouseButtonReleased
        && (p_mouse.x >= grc->info.p_arrow.x)
        && (p_mouse.x <= grc->info.p_arrow.x + grc->info.r_arrow.width)
        && (p_mouse.y >= grc->info.p_arrow.y)
        && (p_mouse.y <= grc->info.p_arrow.y + grc->info.r_arrow.height)) {
        grc->info.r_arrow.left = 7;
        sfSprite_setTextureRect(grc->info.s_arrow, grc->info.r_arrow);
        my_book(grc, wdw);
    }
    else if ((p_mouse.x >= grc->info.p_arrow.x)
            && (p_mouse.x <= grc->info.p_arrow.x + grc->info.r_arrow.width)
            && (p_mouse.y >= grc->info.p_arrow.y)
            && (p_mouse.y <= grc->info.p_arrow.y + grc->info.r_arrow.height))
        grc->info.r_arrow.left = 105;
    else
        grc->info.r_arrow.left = 7;
    sfSprite_setTextureRect(grc->info.s_arrow, grc->info.r_arrow);
}

void event_next_book(grc_t *grc, sfRenderWindow *wdw, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
    event_arrow_book_two(grc, p_mouse, event, wdw);
    grc->crsr.p_csr.x = p_mouse.x;
    grc->crsr.p_csr.y = p_mouse.y;
    sfSprite_setPosition(grc->crsr.s_csr, grc->crsr.p_csr);
}

void my_book(grc_t *grc, sfRenderWindow *wdw)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(wdw) && grc->menu.util == 1) {
        sfRenderWindow_drawSprite(wdw, grc->info.s_next, NULL);
        sfRenderWindow_drawSprite(wdw, grc->info.s_arr, NULL);
        sfRenderWindow_drawSprite(wdw, grc->crsr.s_csr, NULL);
        if (sfRenderWindow_pollEvent(wdw, &event))
            event_next_book(grc, wdw, event);
        sfRenderWindow_display(wdw);
    }
}
