
NAME		:= fractol
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
INCLUDE		:= -I./include
DFLAGS		:= -g -fsanitize=address -fsanitize=leak

DIR_SRC		:= ./src
DIR_LBFT	:= ./libft

MAIN		:= src/main.c
SRC_FRACT	:= julia.c #mandelbrot.c \
				math_utils.c color.c\#

OBJ_FRACT	:= $(addprefix $(DIR_SRC)/, $(SRC_FRACT:.c=.o))

OBJ			:= $(OBJ_FRACT)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(DIR_LBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(MAIN) $(DIR_LBFT)/libft.a -o $(NAME)

$(DIR_SRC)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
#	@$(MAKE) -C $(DIR_LBFT) clean

fclean: clean
	rm -f $(NAME)
#	@$(MAKE) -C $(DIR_LBFT) fclean

re: fclean all

test: re
	@norminette ./include ./libft ./src | grep "Error"

.PHONY: all clean fclean re test bonus
