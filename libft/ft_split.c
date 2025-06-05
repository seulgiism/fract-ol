/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/27 13:28:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 13:18:26 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

// ft_split helpers
static char	**ft_malloc_ss(const char *s, char c, size_t *strs_count);
static void	ft_get_start_len(const char *s, char c, t_ss s_ss);
static int	ft_populate(const char *s, t_ss s_ss);
static char	**ft_ss_empty_alloc(void);

char	**ft_split(char const *s, char c)
{
	t_ss	s_ss;

	if (*s == '\0')
		return (ft_ss_empty_alloc());
	s_ss.ss = ft_malloc_ss(s, c, &(s_ss.ss_ln));
	if (!s_ss.ss)
		return (NULL);
	s_ss.s_starts = malloc(s_ss.ss_ln * sizeof(size_t));
	if (!s_ss.s_starts)
		return (free(s_ss.ss), NULL);
	s_ss.s_lens = malloc(s_ss.ss_ln * sizeof(size_t));
	if (!s_ss.s_lens)
		return (free(s_ss.ss), free(s_ss.s_starts), NULL);
	ft_get_start_len(s, c, s_ss);
	if (!ft_populate(s, s_ss))
	{
		free(s_ss.s_starts);
		free(s_ss.s_lens);
		free(s_ss.ss);
		return (NULL);
	}
	free(s_ss.s_starts);
	free(s_ss.s_lens);
	s_ss.ss[s_ss.ss_ln] = NULL;
	return (s_ss.ss);
}

// malloc strs
static char	**ft_malloc_ss(const char *s, char c, size_t *strs_count)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	*strs_count = count;
	return (malloc((count + 1) * sizeof(char *)));
}

// malloc arr_start arr_len
// returns:		arr_start
// return parm: arr_len
static void	ft_get_start_len(const char *s, char c, t_ss s_ss)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			s_ss.s_starts[j] = i;
			s_ss.s_lens[j] = 0;
			while (s[i] != c && s[i])
			{
				s_ss.s_lens[j]++;
				i++;
			}
			i--;
			j++;
		}
		i++;
	}
}

// ss will become *ss == NULL if strs malloc fails
static int	ft_populate(const char *s, t_ss s_ss)
{
	size_t	i;

	i = 0;
	while (i < s_ss.ss_ln)
	{
		s_ss.ss[i] = ft_str_mallocpy(s + s_ss.s_starts[i], s_ss.s_lens[i]);
		if (!s_ss.ss[i])
		{
			while (i)
				free(s_ss.ss[--i]);
			return (0);
		}
		i++;
	}
	return (1);
}

static char	**ft_ss_empty_alloc(void)
{
	char	**ss;

	ss = malloc(sizeof(char *));
	if (!ss)
		return (NULL);
	*ss = NULL;
	return (ss);
}
