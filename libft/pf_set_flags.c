/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_set_flags.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/10 18:07:00 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/22 16:05:59 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char		*ft_error_type_wrong_flag(t_flags flags, int *error);
void		ft_last_error_check(char c, int *error);
int			ft_is_typelist(char c);
static void	ft_set_type(char c, t_flags *flags, int *error);
static void	ft_set_zero(char **s, t_flags *flags, int *error);
static void	ft_set_perc(char **s, t_flags *flags, int *error);
static void	ft_set_left_justf(char **s, t_flags *flags, int *error);

// get flags
char	*ft_get_flags(char *s, t_flags *flags, int *error)
{
	*error = 0;
	s++;
	if (*s == '0')
		ft_set_zero(&s, flags, error);
	if (*s == '-' && !*error)
		ft_set_left_justf(&s, flags, error);
	else if (ft_isdigit(*s) && !*error)
	{
		flags->right_justf = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
	}
	if (*s == '.' && !*error)
		ft_set_perc(&s, flags, error);
	if (!*error)
		ft_set_type(*s++, flags, error);
	return (s);
}

static void	ft_set_left_justf(char **s, t_flags *flags, int *error)
{
	(*s)++;
	if (**s == '0')
	{
		*error = 1;
		return (ft_putstr_fd(RED"~[FLAGS ERROR]: \"%-\", "\
							"- flag can not be used together with "\
							"'0'~\n"RESET, 2));
	}
	if (!ft_isdigit(**s))
		flags->left_justf = 0;
	else
	{
		flags->left_justf = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
}

static void	ft_set_perc(char **s, t_flags *flags, int *error)
{
	(*s)++;
	if (!ft_isdigit(**s))
	{
		*error = 1;
		return (ft_putstr_fd(RED"~[FLAGS ERROR]: \"%.\", "\
							"no number specified~\n"RESET, 2));
	}
	flags->perc_zero = '.';
	flags->zeros_width = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
}

static void	ft_set_zero(char **s, t_flags *flags, int *error)
{
	(*s)++;
	if (ft_is_typelist(**s))
		return ;
	if (**s == '-' || **s == '.')
	{
		*error = 1;
		return (ft_putstr_fd(RED"~[FLAGS ERROR]: \"%0\", "\
							"0 flag can not be used together with "\
							"'-' or '.'~\n"RESET, 2));
	}
	if (!ft_isdigit(**s))
	{
		*error = 1;
		return (ft_putstr_fd(RED"~[FLAGS ERROR]: \"%0\", "\
							"no number specified~\n"RESET, 2));
	}
	flags->perc_zero = '0';
	flags->zeros_width = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
}

static void	ft_set_type(char c, t_flags *flags, int *error)
{
	if (c == 'c')
		flags->type = 'c';
	else if (c == 's')
		flags->type = 's';
	else if (c == 'p')
		flags->type = 'p';
	else if (c == 'd' || c == 'i')
		flags->type = 'i';
	else if (c == 'u')
		flags->type = 'u';
	else if (c == 'x')
		flags->type = 'x';
	else if (c == 'X')
		flags->type = 'X';
	else if (c == '%')
		flags->type = '%';
	else
		return (ft_last_error_check(c, error));
	if (ft_error_type_wrong_flag(*flags, error))
		return (ft_putstr_fd(RED"[FLAG ERROR] . "\
							"or 0 with wrong type\n"RESET, 2));
	if (flags->type == 'x' || flags->type == 'X' || flags->type == 'u')
		flags->nbr_neg = 0;
}

// #include <stdlib.h>
// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	(void) argc;
// 	t_flags	flags = {0};
// 	int		error;
// 	char	*s = argv[1];
// 	char	*error_msg;

// 	error_msg = ft_get_flags(s, &f&lelags, &error);
// 	if (error)
// 	{
// 		printf("%s\n", error_msg);
// 		free(error_msg);
// 	}
// 	printf("%i :left_justify\n", flags.left_justf);
// 	printf("%i :right_justify\n", flags.right_justf);
// 	printf("%c :perc_zero\n", flags.perc_zero);
// 	printf("%i :zeros_width\n", flags.zeros_width);
// 	printf("%c :type\n", flags.type);
// }