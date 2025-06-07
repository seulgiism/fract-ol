
NAME		:= fractol
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -lm 
INCLUDE		:= -I./include
DFLAGS		:= -g -fsanitize=address -fsanitize=leak

DIR_SRC		:= ./src
DIR_LBFT	:= ./libft

DIR_MLX		:= ./MLX42
MLX_FLAGS	:= -I$(DIR_MLX)/include \
				-L$(DIR_MLX)/build \
				-lmlx42 \
				-ldl -lglfw -pthread -lm
DIR_MLX_A	:= $(DIR_MLX)/build/libmlx42.a

MAIN		:= src/main.c
SRC_FRACT	:= julia_input.c #mandelbrot.c \
				math_utils.c color.c\#

OBJ_FRACT	:= $(addprefix $(DIR_SRC)/, $(SRC_FRACT:.c=.o))

OBJ			:= $(OBJ_FRACT)

all: $(NAME)

$(NAME): $(OBJ) $(DIR_MLX_A)
	@$(MAKE) -C $(DIR_LBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(MAIN) \
		$(DIR_LBFT)/libft.a $(MLX_FLAGS) \
		-o $(NAME)

$(DIR_MLX_A):
	@git submodule update --init --recursive
	@cmake -S $(DIR_MLX) -B $(DIR_MLX)/build
	@cmake --build $(DIR_MLX)/build -j4

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

.PHONY: all clean fclean re test
