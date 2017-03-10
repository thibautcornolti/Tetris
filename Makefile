##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Fri Mar 10 11:29:59 2017 Thibaut Cornolti
##

SRC	=	tetris.c		\
		parser.c		\
		parser_utils.c		\
		parser_setter.c		\
		setupterm.c		\
		utils.c			\
		utils2.c		\
		title.c			\
		tools.c			\
		debug.c			\
		display.c		\
		display_utils.c		\
		drawer.c		\
		tetrimino.c		\
		check_tetrimino.c	\
		set_rotated.c		\
		game.c			\
		action_game.c		\
		remove_line.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	tetris

CC	=	gcc -g

HEADER	=	include/

RM	=	rm -f

LIB_P	=	-Llib/my

LIB	=	-lmy -lncurses

all:	$(NAME)

$(NAME):
	cd lib/my/ && make
	$(CC) -o $(NAME) -I$(HEADER) $(SRC) $(LIB_P) $(LIB) -Wall -Wextra -pedantic

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
