/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_mallocpy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 13:18:12 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

// copies from src and len and returns allocated copy
// terminates the str automatically
char	*ft_str_mallocpy(const char *s, size_t ln)
{
	size_t	i;
	char	*s_new;

	s_new = malloc(ln + 1);
	if (!s_new)
		return (NULL);
	i = 0;
	while (i < ln)
	{
		s_new[i] = s[i];
		i++;
	}
	s_new[i] = '\0';
	return (s_new);
}
