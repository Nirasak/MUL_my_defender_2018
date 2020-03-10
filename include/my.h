/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "window.h"

int print_descr(void);
int my_defender(grc_t *);
void create_my_wind(int, int, sfRenderWindow **);
void create_my_menu(grc_t *);
void create_music_menu(grc_t *);
void create_my_options(grc_t *);
void create_my_map(grc_t *);
void events_my_options(grc_t *, sfRenderWindow *, sfEvent);
void events_my_game(grc_t *, sfRenderWindow *, sfEvent);
void events_my_menu(grc_t *, sfRenderWindow *, sfEvent);
void display_my_options(grc_t *, sfRenderWindow *);
void display_my_game(grc_t *, sfRenderWindow *);
void display_my_menu(grc_t *, sfRenderWindow *);
int my_strcmp(char const *, char const *);
void my_printf(char *, ...);
void destroy_all(grc_t *);
void create_music_game(grc_t *);
void create_my_enemy(grc_t *);
void going_up(grc_t *, int);
void going_right(grc_t *, int);
void going_down(grc_t *, int);
void anim_my_enemys(grc_t *, int);
void my_menu(grc_t *, sfRenderWindow *);
void display_my_puase(grc_t *, sfRenderWindow *);
void my_pause(grc_t *, sfRenderWindow *);
void event_my_pause(grc_t *, sfRenderWindow *, sfEvent);
void create_but_game(grc_t *);
void create_my_pause(grc_t *);
void create_but_all(grc_t *);
void create_but_new(grc_t *);
void create_all_but(grc_t *);
void create_but_game(grc_t *);
void create_but_opt(grc_t *);
void create_but_menu(grc_t *);
void create_but_exit(grc_t *);
void display_my_towers(grc_t *, sfRenderWindow *);
void events_my_towers(grc_t *, sfEvent, sfVector2i);
void event_but_game(grc_t *, sfVector2i, sfEvent);
void events_my_pause(grc_t *, sfRenderWindow *, sfEvent);
char *my_itoa(int);
void event_but_new(grc_t *, sfVector2i, sfEvent);
void destroy_set_game(grc_t *);
void create_info_book(grc_t *);
void my_info(grc_t *, sfRenderWindow *);
void create_book(grc_t *);
void damage_to_enemies(grc_t *);
void event_info_book(grc_t *, sfVector2i, sfEvent);
void create_arrow_book(grc_t *);
void my_book(grc_t *, sfRenderWindow *);
void create_next_button(grc_t *);
void event_next_book(grc_t *, sfRenderWindow *, sfEvent);
void display_my_towers(grc_t *, sfRenderWindow *);
void event_my_info(grc_t *, sfRenderWindow *, sfEvent);
void create_arrow_book(grc_t *);
void events_arrow_book(grc_t *, sfVector2i, sfEvent, sfRenderWindow *);
void create_arrow_book_two(grc_t *);
void event_arrow_book_two(grc_t *, sfVector2i, sfEvent, sfRenderWindow *);
void event_arr(grc_t *, sfRenderWindow *, sfEvent);
void my_arr(grc_t *, sfRenderWindow *);
void create_return_but(grc_t *);
void events_return_but(grc_t *, sfVector2i, sfEvent);
void create_my_score(grc_t *);
void get_clock(grc_t *);
void draw_score(grc_t *, sfRenderWindow *);
void create_my_gold(grc_t *);
void my_clock_gold(grc_t *);
void anime_my_gold(grc_t *);
void create_upgrade(grc_t *);
void check_lvl(grc_t *, sfVector2i, sfEvent);
void create_all(grc_t *);
int event_my_volume(sfEvent);
void construct_my_towers(grc_t *, sfVector2i, sfEvent, int);
void damage_continue(grc_t *, int, int);
void check_enemies_life(grc_t *);

#endif
