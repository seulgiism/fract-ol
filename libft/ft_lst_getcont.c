/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_getcont.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 22:42:26 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/20 16:28:31 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

// gets the content at i
void	*ft_lst_getc(t_list *lst, size_t i)
{
	if (!lst)
		return (NULL);
	if (i == 0)
		return (ft_lst_getcfirst(lst));
	if (i >= lst->size)
		return (ft_lst_getclast(lst));
	return (ft_lst_get(lst, i)->content);
}

void	*ft_lst_getclast(t_list *lst)
{
	return (lst->last->content);
}

void	*ft_lst_getcfirst(t_list *lst)
{
	return (lst->first->content);
}
