/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:35:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/01 18:33:33 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_set_negative(long *n, int *str_len, int *sign);
static int	ft_digits(long nbr);

char	*ft_itoa(int n)
{
	long	nbr;
	int		sign;
	char	*str;
	int		str_len;

	nbr = n;
	str_len = 0;
	sign = 0;
	ft_set_negative(&nbr, &str_len, &sign);
	str_len += ft_digits(nbr);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	str[str_len--] = '\0';
	while (str_len >= 0)
	{
		str[str_len] = ft_tochar(nbr % 10);
		nbr /= 10;
		str_len--;
	}
	if (sign)
		str[0] = '-';
	return (str);
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

static void	ft_set_negative(long *n, int *str_len, int *sign)
{
	if (*n < 0)
	{
		(*str_len)++;
		*sign = 1;
		*n = -(*n);
	}
}
