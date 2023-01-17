NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
SRC = *.c

OBJ = $(SRC:.c=.o)

INC = libft.h

all: $(NAME)

$(NAME):
    cc -I $(INC) $(CFLAGS) -c $? $(SRC)
    ar rc $(NAME) $? $(OBJ)
    ranlib $(NAME)

clean:
    rm -f $(OBJ)

fclean: clean
    rm $(NAME)

re: fclean all
