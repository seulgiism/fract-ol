/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst_del.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 18:13:31 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/13 14:11:41 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arrlst.h"
#include <stddef.h>

// this function will delete the content at i
// and will just NULL it out.
t_arrlst	*ft_arrlst_del_null(t_arrlst **arrlst, size_t i, \
									void (*del)(void *))
{
	if (i == (*arrlst)->len - 1)
		return (ft_arrlst_deppend(arrlst, del));
	return (ft_arrlst_set(arrlst, i, NULL, del));
}

// this function will delete the content at i
// and then shift all the elements 
t_arrlst	*ft_arrlst_del_shift(t_arrlst **arrlst, size_t i, \
									void (*del)(void *))
{
	if (i == (*arrlst)->len - 1)
		return (ft_arrlst_deppend(arrlst, del));
	ft_arrlst_set(arrlst, i, NULL, del);
	if (i < (*arrlst)->len && (*arrlst)->len > 0)
	{
		while (i < (*arrlst)->len)
		{
			(*arrlst)->arr[i] = (*arrlst)->arr[i + 1];
			i++;
		}
		(*arrlst)->arr[i] = NULL;
		(*arrlst)->len--;
		if (((*arrlst)->len < (*arrlst)->cap / 3) && (*arrlst)->cap > 10)
		{
			if (!ft_arrlst_shrink(arrlst, del))
				return (NULL);
		}
	}
	return (*arrlst);
}

t_arrlst	*ft_arrlst_deppend(t_arrlst **arrlst, \
								void (*del)(void *))
{
	if ((*arrlst)->len > 0)
	{
		del((*arrlst)->arr[(*arrlst)->len - 1]);
		(*arrlst)->arr[(*arrlst)->len - 1] = NULL;
		(*arrlst)->len--;
	}
	if (((*arrlst)->len < (*arrlst)->cap / 3) && (*arrlst)->cap > 10)
	{
		if (!ft_arrlst_shrink(arrlst, del))
			return (NULL);
	}
	return (*arrlst);
}
