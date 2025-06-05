/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 13:17:57 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*us;
	unsigned char		uc;

	us = (const unsigned char *) s;
	uc = (unsigned char) c;
	while (*us)
	{
		if (*us == uc)
			return ((char *) us);
		us++;
	}
	if (uc == '\0')
		return ((char *) us);
	return (NULL);
}
