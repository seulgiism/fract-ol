/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 13:16:58 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*s_new;

	size = ft_strlen(s) + 1;
	s_new = malloc(size);
	if (!s_new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s_new[i] = s[i];
		i++;
	}
	return (s_new);
}
