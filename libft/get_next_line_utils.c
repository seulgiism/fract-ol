/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 15:10:47 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/08 15:55:16 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_stash_append_helpr(char *stash_new, t_stash *stash, \
									const char *buff);
char	*ft_clean_exit(t_stash *stash);

// if (stash_old is NULL) ~ starting condition,
// it will create an empty ft_strempty
char	*ft_stash_append(t_stash *stash, const char *buff)
{
	char	*stash_new;

	stash_new = malloc(ft_strlen(stash->stash) + ft_strlen(buff) + 1);
	if (!stash_new)
		return (ft_clean_exit(stash));
	ft_stash_append_helpr(stash_new, stash, buff);
	return (stash->stash_strt_ptr);
}

void	ft_stash_append_helpr(char *stash_new, t_stash *stash, \
								const char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (stash->stash[j])
		stash_new[i++] = stash->stash[j++];
	j = 0;
	while (buff[j])
		stash_new[i++] = buff[j++];
	stash_new[i] = '\0';
	ft_clean_exit(stash);
	stash->stash_strt_ptr = stash_new;
	stash->stash = stash_new;
}

char	*ft_stash_init(t_stash *stash)
{
	if (!stash->stash_strt_ptr)
	{
		stash->stash_strt_ptr = malloc(1);
		stash->stash = stash->stash_strt_ptr;
		if (!stash->stash)
			return (ft_clean_exit(stash));
		stash->stash[0] = '\0';
	}
	return (stash->stash);
}

char	*ft_clean_exit(t_stash *stash)
{
	if (stash->stash_strt_ptr)
		free(stash->stash_strt_ptr);
	stash->stash = NULL;
	stash->stash_strt_ptr = NULL;
	return (NULL);
}
