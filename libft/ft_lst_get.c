/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_get.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 22:42:26 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/20 19:42:06 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_node	*ft_lst_get(t_list *lst, size_t i)
{
	size_t	j;
	t_node	*curr;

	if (!lst)
		return (NULL);
	if (i == 0)
		return (ft_lst_getfirst(lst));
	if (i >= lst->size)
		return (ft_lst_getlast(lst));
	j = 0;
	curr = lst->first;
	while (j < i)
	{
		curr = curr->next;
		j++;
	}
	return (curr);
}

t_node	*ft_lst_getlast(t_list *lst)
{
	return (lst->last);
}

t_node	*ft_lst_getfirst(t_list *lst)
{
	return (lst->first);
}

size_t	ft_lst_getsize(t_list *lst)
{
	return (lst->size);
}
