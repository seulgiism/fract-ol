/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_del.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 16:44:06 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/20 17:27:01 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lst_depend(t_list *lst, void (*del)(void *))
{
	if (!lst || lst->size == 0)
		return ;
	if (lst->size == 1)
	{
		ft_lst_delnode(lst->first, del);
		lst->first = NULL;
		lst->last = NULL;
		lst->size = 0;
		return ;
	}
	lst->last = ft_lst_get(lst, lst->size - 2);
	ft_lst_delnode(lst->last->next, del);
	lst->last->next = NULL;
	lst->size--;
}

void	ft_lst_deprepend(t_list *lst, void (*del)(void *))
{
	t_node	*next;

	if (!lst || lst->size == 0)
		return ;
	if (lst->size == 1)
	{
		ft_lst_delnode(lst->first, del);
		lst->first = NULL;
		lst->last = NULL;
		lst->size = 0;
		return ;
	}
	next = lst->first->next;
	ft_lst_delnode(lst->first, del);
	lst->first = next;
	lst->size--;
}

void	ft_lst_del(t_list *lst, size_t i, void (*del)(void *))
{
	t_node	*curr;
	t_node	*next;

	if (!lst || lst->size == 0)
		return ;
	if (lst->size == 1)
	{
		ft_lst_delnode(lst->first, del);
		lst->first = NULL;
		lst->last = NULL;
		lst->size = 0;
		return ;
	}
	if (i == 0)
		return (ft_lst_deprepend(lst, del));
	if (i >= lst->size)
		return (ft_lst_depend(lst, del));
	curr = ft_lst_get(lst, i - 1);
	next = curr->next;
	curr->next = next->next;
	ft_lst_delnode(next, del);
	lst->size--;
}
