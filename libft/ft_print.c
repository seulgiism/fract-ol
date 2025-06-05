/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:10:09 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/24 18:17:14 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_helpers.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

static int	ft_printf_store_strs(char *s, int error, va_list ap);

int	ft_printf(char *s, ...)
{
	int		error;
	va_list	ap;

	if (!s)
		return (-1);
	error = 0;
	va_start(ap, s);
	return (ft_printf_store_strs(s, error, ap));
}

static int	ft_printf_store_strs(char *s, int error, va_list ap)
{
	t_flags	flags;
	int		bytes_wrote;

	bytes_wrote = 0;
	while (*s)
	{
		if (*s == '%')
		{
			ft_reset_flags(&flags);
			s = ft_get_flags(s, &flags, &error);
			if (error || !ft_write_var(ap, &flags, &bytes_wrote))
				return (-1);
		}
		else
		{
			s = ft_write_big_str(s, &bytes_wrote);
			if (!s)
				return (-1);
		}
	}
	va_end(ap);
	return (bytes_wrote);
}

int	ft_write(char *str, size_t length, int *bytes_wrote)
{
	int	bytes;

	bytes = write(1, str, length);
	if (bytes == -1)
		return (0);
	*bytes_wrote += bytes;
	return (1);
}

int	ft_write_free(char *str, size_t length, int *bytes_wrote)
{
	int	bytes;

	bytes = write(1, str, length);
	if (bytes == -1)
		return (0);
	*bytes_wrote += bytes;
	if (str)
		free(str);
	return (1);
}

int	ft_write_flagscheck(char *str, size_t length, int *bytes_wrote, \
						t_flags flags)
{
	int	bytes;

	if (flags.type == 'c' && *str == '\0')
		bytes = write(1, "\0", 1);
	else
		bytes = write(1, str, length);
	if (bytes == -1)
		return (0);
	*bytes_wrote += bytes;
	return (1);
}
