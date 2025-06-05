/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 23:02:25 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 13:19:46 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*usrc;
	unsigned char		*udest;

	if (!dest && !src && n > 0)
		return (dest);
	usrc = (const unsigned char *) src;
	udest = (unsigned char *) dest;
	if (udest > usrc && usrc + n > udest)
	{
		usrc += n - 1;
		udest += n - 1;
		while (n--)
			*udest-- = *usrc--;
	}
	else
	{
		while (n--)
			*udest++ = *usrc++;
	}
	return (dest);
}
