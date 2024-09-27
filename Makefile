CC ?= gcc

CFLAGS	+=	-std=gnu17 -Wall -Wextra -Werror -Iinclude

SRC = 	src/main.c	\
		src/repl.c	\
		src/btree.c	\
		src/tables.c

NAME	=	Btree

all: $(NAME)

$(NAME):	$(SRC)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

fclean:
	$(RM) $(NAME)

re:	fclean all

.PHONY : clean all re fclean
