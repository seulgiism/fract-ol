/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 00:58:22 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/16 18:11:35 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arrlst.h"
#include <stdlib.h>

t_arrlst	*ft_arrlst_shrink(t_arrlst **arrlst, void (*del)(void *))
{
	t_arrlst	*new_arrlst;
	size_t		strt_cap;
	size_t		strt_len;
	size_t		i;

	if ((*arrlst)->cap >= 20)
	{
		strt_cap = (*arrlst)->strt_cap;
		strt_len = (*arrlst)->strt_len;
		new_arrlst = ft_arrlst_create((*arrlst)->cap / 2, (*arrlst)->len);
		if (!new_arrlst)
			return (ft_arrlst_free(arrlst, del), NULL);
		i = 0;
		while (i < (*arrlst)->len)
		{
			new_arrlst->arr[i] = (*arrlst)->arr[i];
			i++;
		}
		free((*arrlst)->arr);
		free(*arrlst);
		*arrlst = new_arrlst;
		(*arrlst)->strt_cap = strt_cap;
		(*arrlst)->strt_len = strt_len;
	}
	return (*arrlst);
}

static void	ft_arrlst_grow_copy_init(t_arrlst *arrlst, t_arrlst *old_arrlst);

t_arrlst	*ft_arrlst_grow(t_arrlst **arrlst, void (*del)(void *))
{
	t_arrlst	*new_arrlst;
	size_t		strt_cap;
	size_t		strt_len;

	strt_cap = (*arrlst)->strt_cap;
	strt_len = (*arrlst)->strt_len;
	new_arrlst = ft_arrlst_create((*arrlst)->cap * 2, (*arrlst)->len);
	if (!new_arrlst)
		return (ft_arrlst_free(arrlst, del), NULL);
	ft_arrlst_grow_copy_init(new_arrlst, *arrlst);
	free((*arrlst)->arr);
	free(*arrlst);
	*arrlst = new_arrlst;
	(*arrlst)->strt_cap = strt_cap;
	(*arrlst)->strt_len = strt_len;
	return (*arrlst);
}

static void	ft_arrlst_grow_copy_init(t_arrlst *arrlst, t_arrlst *old_arrlst)
{
	size_t		i;

	i = 0;
	while (i < arrlst->len)
	{
		arrlst->arr[i] = old_arrlst->arr[i];
		i++;
	}
	while (i < arrlst->cap)
		arrlst->arr[i++] = NULL;
}
