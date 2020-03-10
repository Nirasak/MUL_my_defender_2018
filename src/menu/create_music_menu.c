/*
** EPITECH PROJECT, 2019
** create_music_menu
** File description:
** create music
*/

#include "my.h"

void create_music_menu(grc_t *grc)
{
    grc->menu.s_music = sfMusic_createFromFile("assets/music/music_menu.ogg");
    sfMusic_play(grc->menu.s_music);
    sfMusic_setVolume(grc->menu.s_music, 100);
    sfMusic_setLoop(grc->menu.s_music, sfTrue);
}
