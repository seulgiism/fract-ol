/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlower.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 16:58:49 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/05 17:01:18 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
