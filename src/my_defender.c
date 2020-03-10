/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** principal functions
*/

#include "my.h"

void my_game(grc_t *grc, sfRenderWindow *wdw)
{
    sfEvent event;

    sfMusic_pause(grc->menu.s_music);
    sfMusic_play(grc->game.s_music);
    while (sfRenderWindow_isOpen(wdw) && grc->menu.status == 1) {
        if (sfRenderWindow_pollEvent(wdw, &event))
            events_my_game(grc, wdw, event);
        damage_to_enemies(grc);
        display_my_game(grc, wdw);
        draw_score(grc, wdw);
        sfRenderWindow_display(wdw);
    }
}

void my_options(grc_t *grc, sfRenderWindow *wdw)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(wdw) && grc->menu.util == 0
            && (grc->menu.status == 2 || grc->menu.status == 4)) {
        if (sfRenderWindow_pollEvent(wdw, &event))
            events_my_options(grc, wdw, event);
        display_my_options(grc, wdw);
        sfRenderWindow_display(wdw);
    }
}

void my_menu(grc_t *grc, sfRenderWindow *wdw)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(wdw) && grc->menu.status == 0) {
        if (sfRenderWindow_pollEvent(wdw, &event))
            events_my_menu(grc, wdw, event);
        display_my_menu(grc, wdw);
        sfRenderWindow_display(wdw);
    }
}

int my_defender(grc_t *grc)
{
    sfRenderWindow *wdw;

    create_my_wind(1920, 1080, &wdw);
    create_all(grc);
    while (sfRenderWindow_isOpen(wdw) && grc->menu.status != 6) {
        if (grc->menu.util == 1)
            my_info(grc, wdw);
        if (grc->menu.status == 3)
            my_pause(grc, wdw);
        if (grc->menu.status == 2 || grc->menu.status == 4)
            my_options(grc, wdw);
        if (grc->menu.status == 1)
            my_game(grc, wdw);
        if (grc->menu.status == 0)
            my_menu(grc, wdw);
    }
    destroy_all(grc);
    if (grc->game.loose == 2)
        my_printf("You loose, Try again\n");
    return (0);
}
