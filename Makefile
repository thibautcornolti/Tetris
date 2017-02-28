##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Tue Feb 28 15:59:58 2017 Bastien
##

SRC	=	tetris.c		\
		parser.c		\
		parser_utils.c		\
		parser_setter.c		\
		utils.c			\
		utils2.c		\
		tools.c			\
		debug.c			\
		tetrimino.c		\
		check_tetrimino.c	\
		set_rotated.c		\

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

clean_lib:
	cd lib/my/ && make fclean

fclean:	clean clean_lib
	$(RM) $(NAME)

re:	fclean all
