/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_set_flags2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/10 18:07:00 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/22 15:56:20 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stddef.h>

void	ft_reset_flags(t_flags *flags)
{
	flags->right_justf = 0;
	flags->left_justf = 0;
	flags->zeros_width = 0;
	flags->perc_zero = 0;
	flags->nbr_neg = 0;
	flags->type = 0;
}

int	ft_is_typelist(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_error_type_wrong_flag(t_flags flags, int *error)
{
	if ((flags.type == 'c' || flags.type == 'p'
			|| flags.type == '%') && flags.perc_zero == '.')
		return (*error = 1, 1);
	if ((flags.type == 'c' || flags.type == 'p'
			|| flags.type == '%' || flags.type == 's')
		&& flags.perc_zero == '0')
		return (*error = 1, 1);
	return (0);
}

void	ft_last_error_check(char c, int *error)
{
	if (c == '-')
	{
		*error = 1;
		ft_putstr_fd(RED"~[FLAGS ERROR]: \"%-\", "\
					"can not use - flag after width~\n"RESET, 2);
	}
	else
	{
		*error = 1;
		ft_putstr_fd(RED"~[TYPE ERROR or UNKNOWN FLAG]:"\
				" type or flag not supported by ft_printf~\n"RESET, 2);
	}
}
