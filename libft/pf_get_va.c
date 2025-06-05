/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 17:04:04 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/20 18:50:51 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "printf_helpers.h"
#include <stdlib.h>
#include <stdarg.h>

static char	*ft_va_to_str(va_list ap, t_flags *flags);

int	ft_write_var(va_list ap, t_flags *flags, int *bytes_wrote)
{
	char	*str;

	str = ft_va_to_str(ap, flags);
	if (!str)
		return (0);
	if (!ft_write_va_bonus(str, *flags, bytes_wrote))
		return (0);
	return (1);
}

static char	*ft_va_to_str(va_list ap, t_flags *flags)
{
	char	*str;

	if (flags->type == 'c')
		str = ft_ctoa(va_arg(ap, int));
	if (flags->type == 's')
		str = ft_strtoa(va_arg(ap, char *), *flags);
	if (flags->type == 'p')
		str = ft_ptoa(va_arg(ap, void *));
	if (flags->type == 'i')
		str = ft_itoa_base_signed(va_arg(ap, int), "0123456789", \
									&(flags->nbr_neg));
	if (flags->type == 'u')
		str = ft_itoa_base_unsigned(va_arg(ap, int), "0123456789");
	if (flags->type == 'x')
		str = ft_itoa_base_unsigned(va_arg(ap, int), "0123456789abcdef");
	if (flags->type == 'X')
		str = ft_itoa_base_unsigned(va_arg(ap, int), "0123456789ABCDEF");
	if (flags->type == '%')
		str = ft_strdup("%");
	return (str);
}

// get's the next % or '\0' if not found
// and mallocs the str intolst 
char	*ft_write_big_str(char *s, int *bytes_wrote)
{
	char		*s_end;
	size_t		s_len;

	s_end = ft_strchr(s, '%');
	if (s_end == NULL)
		s_end = ft_strchr(s, '\0');
	s_len = s_end - s;
	if (!ft_write(s, s_len, bytes_wrote))
		return (NULL);
	return (s_end);
}
