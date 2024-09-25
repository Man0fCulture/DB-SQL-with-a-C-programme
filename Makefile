CC ?= gcc

CFLAGS	+=	-std=gnu17 -Wall -Wextra -Werror

SRC = Test_1.c

NAME	=	exo

all: $(NAME)

$(NAME):	$(SRC)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

fclean:
	$(RM) $(NAME)

re:	fclean all

.PHONY : clean all re fclean