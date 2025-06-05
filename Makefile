
NAME		:= fractol
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
INCLUDE		:= -I./include

DIR_SRC		:= ./src
DIR_LBFT	:= ./libft

SRC_PF		:= ft_print.c \
				pf_get_va.c \
				pf_print_out.c \
				pf_set_flags.c \
				pf_set_flags2.c \
				pf_sometoa.c \
				pf_sometoa2.c

SRC_LBFT	:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_toint.c \
				ft_tochar.c ft_isspace.c \
				ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c \
				ft_memcmp.c ft_bzero.c ft_calloc.c \
				ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strnstr.c \
				ft_strdup.c ft_str_mallocpy.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_atoi.c ft_isdigit.c ft_itoa.c ft_strmapi.c \
				ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_strlower.c ft_streq.c

OBJ_PF		:= $(addprefix $(DIR_SRC)/, $(SRC_PF:.c=.o))
OBJ_LBFT 	:= $(addprefix $(DIR_LBFT)/, $(SRC_LBFT:.c=.o))

OBJ			:= $(OBJ_PF) $(OBJ_LBFT)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(DIR_SRC)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(DIR_LBFT)/%.o: $(DIR_LBFT)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	@$(MAKE) re
	@cc -g -fsanitize=address -fsanitize=leak -Wall -Wextra -Werror -I./include ./test/printf_test1.c ./libftprintf.a
	@$(MAKE) fclean
	@./a.out
	@norminette ./include ./libft ./src | grep "Error"

.PHONY: all clean fclean re test bonus
