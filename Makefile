##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME	=		libmy_malloc.so

CC		=		gcc

SRC		=		src/alloc.c	\
				src/tool.c		\

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-fPIC -Wall -Wextra

LDFLAGS	=		-shared -fPIC

CPPFLAGS	=		-I ./include

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS)

all:	$(NAME)

clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re