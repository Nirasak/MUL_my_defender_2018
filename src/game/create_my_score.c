/*
** EPITECH PROJECT, 2019
** create_my_score
** File description:
** .c
*/

#include "my.h"

void create_my_score(grc_t *grc)
{
    sfVector2f pos;

    grc->cl.score = 0;
    pos.x = 1750;
    pos.y = 60;
    grc->cl.font = sfFont_createFromFile("assets/font/font.ttf");
    grc->cl.text = sfText_create();
    sfText_setFont(grc->cl.text, grc->cl.font);
    sfText_setColor(grc->cl.text, sfBlack);
    sfText_setPosition(grc->cl.text, pos);
    sfText_setCharacterSize(grc->cl.text, 30);
    grc->cl.clock = sfClock_create();
    grc->cl.sec = 0;
}

void get_clock(grc_t *grc)
{
    grc->cl.time = sfClock_getElapsedTime(grc->cl.clock);
    grc->cl.sec = grc->cl.time.microseconds / 1000000.0;
}

void draw_score(grc_t *grc, sfRenderWindow *wdw)
{
    get_clock(grc);
    if (grc->cl.sec > 1) {
        grc->cl.score = grc->cl.score + 1;
        sfClock_restart(grc->cl.clock);
    }
    sfText_setString(grc->cl.text, my_itoa(grc->cl.score));
    sfRenderWindow_drawText(wdw, grc->cl.text, NULL);
}
