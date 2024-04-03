NAME	=	push_swap

SRC		= 	src/algo.c src/main.c utils/parsing.c utils/utils.c\
			utils/structs.c utils/structs2.c src/initstacks.c\
			src/radixsort.c src/smallsort.c\

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

LIBFT	=	libft/libft.a

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)
# -s to make the commands silent, -C to change directory before making 
$(NAME):	$(OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -o bin/$(NAME)

%.o	 : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@make -C libft/
clean:
		@make clean -s -C libft
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME) bin/$(NAME)
		@make fclean -s -C libft

re:	fclean all

.PHONY: all clean fclean re