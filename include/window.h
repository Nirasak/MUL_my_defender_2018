/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** structs
*/

typedef struct menu
{
    sfTexture *t_menu;
    sfSprite *s_menu;
    sfTexture *t_but;
    sfSprite *s_play;
    sfSprite *s_opt;
    sfSprite *s_exit;
    sfIntRect r_play;
    sfVector2f p_play;
    sfIntRect r_opt;
    sfVector2f p_opt;
    sfIntRect r_exit;
    sfVector2f p_exit;
    int status;
    int util;
    sfMusic *s_music;
} menu_t;

typedef struct opt
{
    sfTexture *t_opt;
    sfSprite *s_opt;
    sfTexture *t_but;
    sfSprite *s_vol;
    sfIntRect r_vol;
    sfVector2f p_vol;
    sfSprite *s_back;
    sfIntRect r_back;
    sfVector2f p_back;
} opt_t;

typedef struct cl
{
    int score;
    sfText *text;
    sfClock *clock;
    sfTime time;
    float sec;
    sfFont *font;
} cl_t;

typedef struct gold
{
    sfSprite *s_gold;
    sfTexture *t_gold;
    sfVector2f p_gold;
    sfIntRect r_gold;
    sfClock *clock;
    sfTime time;
    float sec;
    int gold;
    sfText *txt_gold;
    sfFont *f_gold;
    sfClock *clock_gold;
    sfTime time_gold;
    float sec_gold;
} gold_t;

typedef struct life
{
    int *hp;
    sfText *txt_hp;
    sfFont *f_hp;
    sfVector2f p_hp;
} life_t;

typedef struct info
{
    sfTexture *t_info;
    sfSprite *s_info;
    sfVector2f p_info;
    sfIntRect r_info;
    sfTexture *t_book;
    sfSprite *s_book;
    sfVector2f p_book;
    sfTexture *t_arrow;
    sfSprite *s_arrow;
    sfIntRect r_arrow;
    sfVector2f p_arrow;
    sfSprite *s_next;
    sfTexture *t_next;
    sfTexture *t_arr;
    sfSprite *s_arr;
    sfIntRect r_arr;
    sfVector2f p_arr;
    sfSprite *s_ret;
    sfTexture *t_ret;
    sfVector2f p_ret;
    sfIntRect r_ret;
} info_t;

typedef struct crsr
{
    sfTexture *t_csr;
    sfSprite *s_csr;
    sfIntRect r_csr;
    sfVector2f p_csr;
} crsr_t;

typedef struct game
{
    sfTexture *t_map;
    sfSprite *s_map;
    sfTexture *t_enm;
    sfSprite *s_enm;
    sfIntRect *r_enm;
    sfVector2f *p_enm;
    sfMusic *s_music;
    sfClock *clock_enm;
    sfTime time_enm;
    float scd_enm;
    sfClock *clock_move;
    sfTime time_move;
    float scd_move;
    int *status_enm;
    int loose;
    int c;
    int memory;
    int count;
    int slow_enm;
    int slow;
    float *speed;
} game_t;

typedef struct pause
{
    sfSprite *s_pause;
    sfTexture *t_pause;
    sfVector2f p_pause;
    sfTexture *t_but;
    sfSprite *s_game;
    sfSprite *s_new;
    sfSprite *s_opt;
    sfSprite *s_exit;
    sfSprite *s_menu;
    sfVector2f p_game;
    sfVector2f p_new;
    sfVector2f p_exit;
    sfVector2f p_opt;
    sfVector2f p_menu;
    sfIntRect r_game;
    sfIntRect r_new;
    sfIntRect r_exit;
    sfIntRect r_opt;
    sfIntRect r_menu;
} pause_t;

typedef struct twr
{
    sfTexture *t_twr;
    sfSprite *s_twr;
    sfIntRect *r_twr;
    sfVector2f *p_twr;
    sfTexture *t_up;
    sfSprite *s_up;
    sfIntRect r_up;
    sfVector2f p_up;
    int *status;
    sfClock **clock_twr;
    sfTime *time_twr;
    float *scd_twr;
    float *delay_atk;
    int *lvl;
    int price;
    sfText *txt_price;
    sfFont *f_price;
    sfVector2f p_price;
    int status_price;
    int twr_up;
} twr_t;

typedef struct grc
{
    menu_t menu;
    opt_t opt;
    game_t game;
    crsr_t crsr;
    twr_t twr;
    pause_t pause;
    life_t life;
    info_t info;
    cl_t cl;
    gold_t gold;
} grc_t;
