##
## EPITECH PROJECT, 2018
## my_defender
## File description:
## Makefile
##

SRC	=	src/main.c				\
		src/util/print_descr.c			\
		src/my_defender.c			\
		src/window/create_my_window.c		\
		src/menu/create_my_menu.c		\
		src/menu/display_my_menu.c		\
		src/menu/create_my_options.c		\
		src/menu/display_my_options.c		\
		src/menu/create_music_menu.c		\
		src/menu/events_my_menu.c		\
		src/util/my_strcmp.c			\
		src/window/destroy_all.c		\
		src/game/create_my_game.c		\
		src/game/display_my_game.c		\
		src/game/create_music_game.c		\
		src/game/create_my_enemy.c		\
		src/game/display_my_enemys.c		\
		src/game/create_my_pause.c		\
		src/game/create_but_pause.c		\
		src/game/create_all_but.c		\
		src/game/create_but_pause_two.c		\
		src/game/events_my_towers.c		\
		src/game/events_my_pause.c		\
		src/util/itoa.c				\
		src/game/events_my_pause_two.c		\
		src/menu/create_info_book.c		\
		src/game/damage_enemies.c		\
		src/menu/create_next_page.c		\
		src/game/display_my_towers.c		\
		src/menu/create_arrow_menu.c		\
		src/menu/create_return_but.c		\
		src/game/create_my_score.c		\
		src/game/create_my_gold.c		\
		src/game/create_my_upgrade.c		\
		src/game/lvl_up.c			\
		src/create_all.c			\
		src/menu/display_my_options_two.c	\
		src/game/check_enemies.c		\
		src/game/construct_my_towers.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS	=	-l csfml-window -l csfml-system -l csfml-audio -l csfml-graphics

CPPFLAGS	=	 -W -Wall -Wextra -pedantic -I include/ -g3

LIB	=	-L./ -lmy

all: $(NAME)

$(NAME):	$(OBJ)
	cd ./lib/ && make
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LIB)

clean:
	rm -f $(OBJ)
	cd ./lib/ && make fclean

fclean:	clean
	rm -f $(NAME)
	cd ./lib/ && make fclean

re: fclean all

.PHONY: all clean fclean re
