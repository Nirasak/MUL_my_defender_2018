/*
** EPITECH PROJECT, 2019
** create_my_gold
** File description:
** .c
*/

#include "my.h"

void create_my_gold2(grc_t *grc)
{
    sfVector2f pos_gold = {grc->gold.p_gold.x + 75, grc->gold.p_gold.y + 8};

    grc->gold.gold = 200;
    grc->gold.f_gold = sfFont_createFromFile("assets/font/Jersey_554.ttf");
    grc->gold.txt_gold = sfText_create();
    sfText_setFont(grc->gold.txt_gold, grc->gold.f_gold);
    sfText_setColor(grc->gold.txt_gold, sfYellow);
    sfText_setCharacterSize(grc->gold.txt_gold, 40);
    grc->gold.clock_gold = sfClock_create();
    grc->gold.sec_gold = 0;
    sfText_setPosition(grc->gold.txt_gold, pos_gold);
    sfText_setString(grc->gold.txt_gold, my_itoa(grc->gold.gold));
}

void create_my_gold(grc_t *grc)
{
    sfVector2f scale;

    grc->gold.t_gold = sfTexture_createFromFile("assets/game/gold.png",
                                                NULL);
    grc->gold.s_gold = sfSprite_create();
    grc->gold.r_gold.top = 0;
    grc->gold.r_gold.left = 0;
    grc->gold.r_gold.width = 200;
    grc->gold.r_gold.height = 200;
    grc->gold.p_gold.x = 1500;
    grc->gold.p_gold.y = 920;
    scale.x = 0.3;
    scale.y = 0.3;
    sfSprite_setScale(grc->gold.s_gold, scale);
    sfSprite_setTexture(grc->gold.s_gold, grc->gold.t_gold, sfTrue);
    sfSprite_setTextureRect(grc->gold.s_gold, grc->gold.r_gold);
    sfSprite_setPosition(grc->gold.s_gold, grc->gold.p_gold);
    grc->gold.clock = sfClock_create();
    grc->gold.sec = 0;
    create_my_gold2(grc);
}

void my_clock_gold(grc_t *grc)
{
    grc->gold.time = sfClock_getElapsedTime(grc->gold.clock);
    grc->gold.sec = grc->gold.time.microseconds / 1000000.0f;
    grc->gold.time_gold = sfClock_getElapsedTime(grc->gold.clock_gold);
    grc->gold.sec_gold = grc->gold.time_gold.microseconds / 1000000.0f;
}

void anime_my_gold(grc_t *grc)
{
    my_clock_gold(grc);
    if (grc->gold.sec > 0.1) {
        grc->gold.r_gold.left += 200;
        if (grc->gold.r_gold.left >= 990)
            grc->gold.r_gold.left = 0;
        sfClock_restart(grc->gold.clock);
    }
    if (grc->gold.sec_gold > 0.6) {
        grc->gold.gold = grc->gold.gold + 1;
        sfClock_restart(grc->gold.clock_gold);
    }
    sfText_setString(grc->gold.txt_gold, my_itoa(grc->gold.gold));
    sfSprite_setTextureRect(grc->gold.s_gold, grc->gold.r_gold);
}
