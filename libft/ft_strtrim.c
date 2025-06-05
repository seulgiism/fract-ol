/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/01 18:36:22 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

static const char	*ft_strend(char const *s);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;
	char	*start;
	char	*trim_s;
	size_t	trim_len;

	end = (char *) ft_strend(s1);
	start = (char *) s1;
	while (*start && ft_strchr(set, *start))
		start++;
	while (end >= s1 && ft_strchr(set, *end))
		end--;
	if (end < start)
		return (ft_strdup(""));
	trim_len = (size_t)((uintptr_t) end - (uintptr_t) start + 1);
	trim_s = malloc(trim_len + 1);
	if (!trim_s)
		return (NULL);
	ft_strlcpy(trim_s, start, trim_len + 1);
	return (trim_s);
}

static const char	*ft_strend(char const *s)
{
	if (*s == '\0')
		return (s);
	while (*s)
		s++;
	return (--s);
}
