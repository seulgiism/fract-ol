/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst_get.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 18:57:42 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/12 21:47:55 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arrlst.h"

size_t	ft_arrlst_get_len(t_arrlst *arrlst)
{
	return (arrlst->len);
}

size_t	ft_arrlst_get_cap(t_arrlst *arrlst)
{
	return (arrlst->cap);
}

// returns the content at i
void	*ft_arrlst_get_i(t_arrlst *arrlst, size_t i)
{
	if (i > arrlst->len)
		return (NULL);
	return (arrlst->arr[i]);
}
