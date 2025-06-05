/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst_manage.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 00:24:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/12 18:01:15 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arrlst.h"
#include <stdlib.h>
#include "libft.h"

t_arrlst	*ft_arrlst_create(size_t cap, size_t len)
{
	t_arrlst	*arrlst;

	if (cap < 10)
		cap = 10;
	arrlst = malloc(sizeof(*arrlst));
	if (!arrlst)
		return (NULL);
	arrlst->arr = ft_calloc(cap, sizeof(*(arrlst->arr)));
	if (!arrlst->arr)
		return (free(arrlst), NULL);
	if (len > cap)
		len = cap;
	arrlst->cap = cap;
	arrlst->len = len;
	arrlst->strt_cap = cap;
	arrlst->strt_len = len;
	return (arrlst);
}

void	ft_arrlst_free(t_arrlst **arrlst, void (*del)(void *))
{
	size_t	i;

	i = 0;
	while (i < (*arrlst)->len)
	{
		if ((*arrlst)->arr[i])
			del((*arrlst)->arr[i]);
		i++;
	}
	if ((*arrlst)->arr)
		free((*arrlst)->arr);
	if (*arrlst)
		free(*arrlst);
	*arrlst = NULL;
}

t_arrlst	*ft_arrlst_reset(t_arrlst **arrlst, void (*del)(void *))
{
	size_t	cap;
	size_t	len;

	cap = (*arrlst)->strt_cap;
	len = (*arrlst)->strt_len;
	ft_arrlst_free(arrlst, del);
	*arrlst = ft_arrlst_create(cap, len);
	if (!*arrlst)
		return (NULL);
	return (*arrlst);
}
