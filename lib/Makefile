##
## EPITECH PROJECT, 2018
## PSU_my_printf_2018
## File description:
## Makefile
##

LIB	=	my/my_putchar.c	\
		my/my_put_nbr.c	\
		my/my_putstr.c	\
		my/my_octal.c	\
		my/my_put_unsigned_int.c	\
		my/my_unsign_hexa_min.c	\
		my/my_unsign_hexa_maj.c	\
		my/my_printf.c	\
		my/my_print_invisible_char.c	\
		my/my_strcpy.c	\
		my/my_put_long.c	\
		my/my_put_ll.c	\
		my/my_put_pointer_adr.c	\
		my/htag_flags.c	\
		my/my_hexa_l.c

OBJ	=	$(LIB:.c=.o)

NAME	=	libmy.a

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -pedantic

CPPFLAGS	=	-I ./include

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv libmy.a ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY:	all clean fclean re
