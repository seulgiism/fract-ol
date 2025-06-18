
NAME		:= fractol
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
INCLUDE		:= -I./include -I./MLX42/include/MLX42/
DFLAGS		:= -g -fsanitize=address -fsanitize=leak

DIR_SRC		:= ./src
DIR_LBFT	:= ./libft

DIR_MLX		:= ./MLX42
MLX_FLAGS	:= -I$(DIR_MLX)/include/MLX42 \
				-L$(DIR_MLX)/build \
				-lmlx42 \
				-ldl -lglfw -pthread -lm -Ofast -DDEBUG=1
DIR_MLX_A	:= $(DIR_MLX)/build/libmlx42.a

MAIN		:= src/main.c
SRC_FRACT	:= render.c render_zoom.c render_utils.c render_move.c \
				render_itermax_utils.c render_hooks.c render_fract.c \
				mandelbrot.c julia.c julia_cli.c \
				colors.c colors_lerpcol_utils.c colors_genpal_utils.c

OBJ_FRACT	:= $(addprefix $(DIR_SRC)/, $(SRC_FRACT:.c=.o))

OBJ			:= $(OBJ_FRACT)

all: $(NAME)

$(NAME): $(OBJ) $(DIR_MLX_A)
	@$(MAKE) -C $(DIR_LBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(MAIN) \
		$(DIR_LBFT)/libft.a $(MLX_FLAGS) -lm\
		-o $(NAME)

$(DIR_MLX_A):
	@git submodule update --init --recursive
	@cmake -S $(DIR_MLX) -B $(DIR_MLX)/build
	@cmake --build $(DIR_MLX)/build -j4

$(DIR_SRC)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(DIR_LBFT) clean
	@rm -rf $(DIR_MLX)/build

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	@norminette ./include ./libft ./src | grep "Error" || echo "success"
	./$(NAME)

.PHONY: all clean fclean re test
