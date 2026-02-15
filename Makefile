NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = brain.c sorting_algo.c parsing1.c parsing2.c utils.c rotate_oprs.c reverse_rotate_oprs.c swap_push_oprs.c ft_atoi.c ft_split.c ft_strlen.c ft_strjoin.c index_update.c call_sort.c
OBJ = $(SRC:.c=.o)
HEADER = push_swap.h 

all : $(NAME)

$(NAME) :$(OBJ) 
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean