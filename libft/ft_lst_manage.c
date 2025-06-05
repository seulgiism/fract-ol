/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_manage.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 22:42:26 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/20 17:27:08 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

t_list	*ft_lst_create(void)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}

t_node	*ft_lst_newnode(void *content)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lst_free(t_list **lst, void (*del)(void*))
{
	t_node	*next;
	t_node	*curr;

	if (!lst || !*lst)
		return ;
	next = (*lst)->first;
	curr = (*lst)->first;
	while (curr)
	{
		next = curr->next;
		ft_lst_delnode(curr, del);
		curr = next;
	}
	free(*lst);
	*lst = NULL;
}

void	ft_lst_delnode(t_node *node, void (*del)(void*))
{
	if (del && node->content)
		del(node->content);
	if (node)
		free(node);
}
