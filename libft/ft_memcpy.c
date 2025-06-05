/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 23:02:25 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 13:19:58 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*usrc;
	unsigned char		*udest;

	if (!dest && !src && n > 0)
		return (dest);
	usrc = (const unsigned char *) src;
	udest = (unsigned char *) dest;
	while (n--)
	{
		*udest++ = *usrc++;
	}
	return (dest);
}
