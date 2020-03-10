/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create window
*/

#include "my.h"

void create_my_wind(int width, int height, sfRenderWindow **wdw)
{
    sfVideoMode vm = {width, height, 32};

    *wdw = sfRenderWindow_create
        (vm, "my_defender", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(*wdw, 60);
    sfRenderWindow_setVerticalSyncEnabled(*wdw, sfTrue);
    sfRenderWindow_setMouseCursorVisible(*wdw, sfFalse);
}
