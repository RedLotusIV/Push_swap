NAME	=	push_swap

SRC		= 	src/main.c utils/parsing.c utils/utils.c\
			utils/structs.c utils/structs2.c src/initstacks.c\
			src/bigsort.c src/smallsort.c utils/utils2.c\
			src/rules1.c src/rules2.c src/instructions.c\
			utils/structs3.c\

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra -g

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
