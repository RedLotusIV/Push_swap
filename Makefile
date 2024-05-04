NAME	=	push_swap

BONUS	=	checker

SRC		=	src/main.c utils/parsing.c utils/utils.c\
			utils/structs.c utils/structs2.c src/initstacks.c\
			src/bigsort.c src/smallsort.c utils/utils2.c\
			src/rules1.c src/rules2.c src/instructions.c\
			utils/structs3.c utils/parsing_utils.c\
			src/bigsort_utils.c\

BSRC	=	src/checker/main.c src/checker/utils.c utils/structs.c\
			utils/parsing.c utils/parsing_utils.c utils/utils2.c\
			src/instructions.c utils/structs2.c utils/utils.c\
			src/initstacks.c


CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra -g

LIBFT	=	libft/libft.a

OBJ		=	$(SRC:.c=.o)
BOBJ	=	$(BSRC:.c=.o)

all		:	$(NAME)
# -s to make the commands silent, -C to change directory before making
$(NAME):	$(OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

$(BONUS):	$(BOBJ) $(LIBFT)
			@$(CC) $(CFLAGS) $(BOBJ) -L libft/ -lft -o $(BONUS)

%.o	 : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@make -C libft/
clean:
		@make clean -s -C libft
		@rm -rf $(OBJ) $(BOBJ)

fclean: clean
		@rm -rf $(NAME) $(NAME) $(BONUS)
		@make fclean -s -C libft

re:	fclean all

bonus:	$(BONUS)

.PHONY: all clean fclean re
