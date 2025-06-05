/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:35:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/01 18:34:02 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_digits(long nbr);
static void	ft_putnbrlong_fd(long nbr, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbrlong_fd(n, fd);
}

static void	ft_putnbrlong_fd(long nbr, int fd)
{
	int		sign;
	char	str[12];
	int		str_len;
	int		str_len_cpy;

	str_len = 0;
	sign = 0;
	if (nbr < 0)
	{
		str_len++;
		sign = 1;
		nbr = -nbr;
	}
	str_len += ft_digits(nbr);
	str_len_cpy = str_len--;
	while (str_len >= 0)
	{
		str[str_len] = ft_tochar(nbr % 10);
		nbr /= 10;
		str_len--;
	}
	if (sign)
		str[0] = '-';
	write(fd, str, str_len_cpy);
}

static int	ft_digits(long nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
