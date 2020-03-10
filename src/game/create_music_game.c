/*
** EPITECH PROJECT, 2019
** create_music_game
** File description:
** .c
*/

#include "my.h"

void create_music_game(grc_t *grc)
{
    grc->game.s_music = sfMusic_createFromFile("assets/music/music.ogg");
    sfMusic_setVolume(grc->game.s_music, 50);
}
