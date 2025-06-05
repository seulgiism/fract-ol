/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_print_out.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 12:08:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/24 18:17:46 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printf_helpers.h"
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static int	ft_justify_write(char *str, t_flags flags, int *bytes_wrote);
static int	ft_zeros_write(char *str, t_flags flags, int *bytes_wrote);
static void	ft_perc_str(char *str, t_flags flags);
static int	ft_calculate_zero_s_length(t_flags flags, char *str);

int	ft_write_va_bonus(char *str, t_flags flags, int *bytes_wrote)
{
	if (flags.right_justf)
	{
		if (!ft_justify_write(str, flags, bytes_wrote))
			return (free(str), 0);
	}
	if (flags.perc_zero)
	{
		if (!ft_zeros_write(str, flags, bytes_wrote))
			return (free(str), 0);
	}
	else if (flags.nbr_neg)
	{
		if (!ft_write("-", 1, bytes_wrote))
			return (free(str), 0);
	}
	if (!ft_write_flagscheck(str, ft_strlen(str), bytes_wrote, flags))
		return (free(str), 0);
	if (flags.left_justf)
	{
		if (!ft_justify_write(str, flags, bytes_wrote))
			return (free(str), 0);
	}
	return (free(str), 1);
}

// calculates how much justify 
static int	ft_justify_write(char *str, t_flags flags, int *bytes_wrote)
{
	int		justify_length;
	char	*justify;
	int		i;

	if (flags.left_justf)
		justify_length = flags.left_justf - ft_strlen(str) - flags.nbr_neg;
	else
		justify_length = flags.right_justf - ft_strlen(str) - flags.nbr_neg;
	if (flags.type == 's' && flags.right_justf && flags.perc_zero)
		justify_length += ft_strlen(str) - flags.zeros_width;
	else if (flags.perc_zero)
		justify_length -= ft_calculate_zero_s_length(flags, str) \
						- flags.nbr_neg;
	if (justify_length <= 0)
		return (1);
	justify = malloc(justify_length);
	if (!justify)
		return (0);
	i = 0;
	while (i < justify_length)
		justify[i++] = ' ';
	return (ft_write_free(justify, (size_t) justify_length, bytes_wrote));
}

static int	ft_calculate_zero_s_length(t_flags flags, char *str)
{
	if (flags.perc_zero == '.')
		return (flags.zeros_width - ft_strlen(str) + flags.nbr_neg);
	else
		return (flags.zeros_width - ft_strlen(str));
}

static int	ft_zeros_write(char *str, t_flags flags, int *bytes_wrote)
{
	int		zero_s_length;
	char	*zero_s;
	int		i;

	if (flags.type == 's')
		return (ft_perc_str(str, flags), 1);
	zero_s_length = ft_calculate_zero_s_length(flags, str);
	if (zero_s_length <= 0 && flags.nbr_neg == false)
		return (1);
	else if (zero_s_length <= 0 && flags.nbr_neg == true)
		return (ft_write("-", 1, bytes_wrote));
	zero_s = malloc(zero_s_length);
	if (!zero_s)
		return (0);
	i = 0;
	while (i < zero_s_length)
		zero_s[i++] = '0';
	if (flags.nbr_neg == true)
		zero_s[0] = '-';
	return (ft_write_free(zero_s, zero_s_length, bytes_wrote));
}

static void	ft_perc_str(char *str, t_flags flags)
{
	size_t	len;
	size_t	perc;

	len = ft_strlen(str);
	perc = (size_t) flags.zeros_width;
	if (perc < len)
		str[perc] = '\0';
}
