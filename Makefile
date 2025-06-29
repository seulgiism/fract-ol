#──────────────────── meta ────────────────────
NAME       := fractol
CC         := cc

#─────────────────── flags ────────────────────
CFLAGS     := -Wall -Wextra -Werror -O3 -ffast-math -g -DDEBUG=1
INCLUDE    := -I./include -I./MLX42/include/MLX42

# home-brew glfw (apple-silicon)
GLFW_DIR   := $(shell brew --prefix glfw)
GLFW_FLAGS := -I$(GLFW_DIR)/include -L$(GLFW_DIR)/lib -lglfw

#────────────────── directories ───────────────
DIR_SRC    := src
DIR_LIBFT  := libft
DIR_MLX    := MLX42
DIR_MLX_A  := $(DIR_MLX)/build/libmlx42.a

#────────────────── MLX flags ─────────────────
MLX_FLAGS  := -I$(DIR_MLX)/include/MLX42 \
              -L$(DIR_MLX)/build \
              -lmlx42 \
              $(GLFW_FLAGS) \
              -framework Cocoa -framework OpenGL -framework IOKit

#───────────────── sources / obj ──────────────
SRC_FRACT  := render.c render_zoom.c render_utils.c render_move.c \
              render_itermax_utils.c render_hooks.c render_drag.c render_fract.c \
              mandelbrot.c julia.c julia_cli.c \
              colors.c colors_lerpcol_utils.c colors_genpal_utils.c

OBJ_FRACT  := $(addprefix $(DIR_SRC)/,$(SRC_FRACT:.c=.o))

#───────────────── default target ─────────────
all: $(NAME)

#────────────── link final binary ─────────────
$(NAME): $(OBJ_FRACT) $(DIR_MLX_A)
	$(MAKE) -C $(DIR_LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_FRACT) src/main.c \
	      $(DIR_LIBFT)/libft.a $(MLX_FLAGS) -lm -o $@

#──────────── compile .c → .o (fractol only) ──
$(DIR_SRC)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#──────────── build MLX42 (cmake) ─────────────
$(DIR_MLX_A):
	git submodule update --init --recursive
	cmake -S $(DIR_MLX) -B $(DIR_MLX)/build
	cmake --build $(DIR_MLX)/build -j4

#──────────── housekeeping ────────────────────
clean:
	$(MAKE) -C $(DIR_LIBFT) clean
	rm -f $(OBJ_FRACT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
