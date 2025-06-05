/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_streq.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 16:46:07 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/05 17:28:54 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_printf.h"
#include <stdbool.h>
#include <stddef.h>

// case insensitive str comp
int	ft_streq(const char *s1, const char *s2, bool case_sensitive)
{
	char	*s1_cpy;
	char	*s2_cpy;
	size_t	i;

	if (case_sensitive)
	{
		s1_cpy = ft_strlower(ft_strdup(s1));
		s2_cpy = ft_strlower(ft_strdup(s2));
	}
	else
	{
		s1_cpy = ft_strdup(s1);
		s2_cpy = ft_strdup(s2);
	}
	i = 0;
	while (s1_cpy[i] == s2_cpy[i] && s1_cpy[i])
		i++;
	if ((int)((unsigned char) s1_cpy[i] == (unsigned char) s2_cpy[i]))
		return (free(s1_cpy), free(s2_cpy), 1);
	return (free(s1_cpy), free(s2_cpy), 0);
}

// int main (int argc, char *argv[])
// {
// 	if (argc == 3)
// 	{
// 		ft_printf("%i", ft_streq(argv[1], argv[2], true));
// 	}
// 	else
// 		ft_printf("wrong one?");
// }
//