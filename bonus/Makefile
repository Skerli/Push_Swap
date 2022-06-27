NAME = push_swap

SRC = operation.c push_swap.c sort_part.c two_to_five.c work_with_list.c

OBJ = $(SRC:.c=.o)

HDRS = push_swap.h

CC = gcc

#FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(HDRS) $(OBJ)
		$(CC) $(FLAGS) $(HDRS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean
