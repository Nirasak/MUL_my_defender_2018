/*
** EPITECH PROJECT, 2019
** create_my_pause
** File description:
** .c
*/

#include "my.h"

void create_my_pause(grc_t *grc)
{
    grc->pause.t_pause = sfTexture_createFromFile("assets/menu/menu_option.png",
                                                NULL);
    grc->pause.s_pause = sfSprite_create();
    sfSprite_setTexture(grc->pause.s_pause, grc->pause.t_pause, sfTrue);
}

void display_my_pause(grc_t *grc, sfRenderWindow *wdw)
{
    sfRenderWindow_drawSprite(wdw, grc->pause.s_pause, NULL);
    sfRenderWindow_drawSprite(wdw, grc->pause.s_new, NULL);
    sfRenderWindow_drawSprite(wdw, grc->pause.s_game, NULL);
    sfRenderWindow_drawSprite(wdw, grc->pause.s_opt, NULL);
    sfRenderWindow_drawSprite(wdw, grc->pause.s_exit, NULL);
    sfRenderWindow_drawSprite(wdw, grc->pause.s_menu, NULL);
    sfRenderWindow_drawSprite(wdw, grc->crsr.s_csr, NULL);
}

void my_pause(grc_t *grc, sfRenderWindow *wdw)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(wdw) && grc->menu.status == 3) {
        if (sfRenderWindow_pollEvent(wdw, &event))
            event_my_pause(grc, wdw, event);
        display_my_pause(grc, wdw);
        sfRenderWindow_display(wdw);
    }
}

void event_my_pause(grc_t *grc, sfRenderWindow *wdw, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
    grc->crsr.p_csr.x = p_mouse.x;
    grc->crsr.p_csr.y = p_mouse.y;
    sfSprite_setPosition(grc->crsr.s_csr, grc->crsr.p_csr);
    events_my_pause(grc, wdw, event);
}
