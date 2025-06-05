/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_add.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 22:42:26 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/20 19:34:08 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	*ft_lst_append(t_list *lst, void *content)
{
	t_node	*new;

	if (!lst || !content)
		return (NULL);
	new = ft_lst_newnode(content);
	if (!new)
		return (NULL);
	if (!lst->first)
	{
		lst->first = new;
		lst->last = new;
	}
	else
	{
		lst->last->next = new;
		lst->last = new;
	}
	lst->size++;
	return (lst);
}

void	*ft_lst_prepend(t_list *lst, void *content)
{
	t_node	*new;

	if (!lst || !content)
		return (NULL);
	new = ft_lst_newnode(content);
	if (!new)
		return (NULL);
	if (!lst->first)
	{
		lst->first = new;
		lst->last = new;
	}
	else
	{
		new->next = lst->first;
		lst->first = new;
	}
	lst->size++;
	return (lst);
}

void	*ft_lst_insert(t_list *lst, void *content, size_t i)
{
	t_node	*new;
	t_node	*curr;

	if (!lst || !content)
		return (NULL);
	if (lst->size == 0 || i >= lst->size)
		return (ft_lst_append(lst, content));
	else if (i == 0)
		return (ft_lst_prepend(lst, content));
	new = ft_lst_newnode(content);
	if (!new)
		return (NULL);
	curr = ft_lst_get(lst, i - 1);
	new->next = curr->next;
	curr->next = new;
	lst->size++;
	return (lst);
}

void	*ft_lst_set(t_list *lst, void *content, size_t i, void (*del)(void *))
{
	t_node	*curr;

	if (!lst || !content)
		return (NULL);
	curr = ft_lst_get(lst, i);
	if (curr->content)
		del(curr->content);
	curr->content = content;
	return (lst);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	t_list *lst = ft_lst_create();
// 	if (!lst)
// 		return (1);
// 	ft_lst_append(lst, strdup("bye"));
// 	ft_lst_append(lst, strdup("die"));
// 	ft_lst_prepend(lst, strdup("hello"));
// 	ft_lst_prepend(lst, strdup("zi"));
// 	ft_lst_append(lst, strdup("mie"));

// 	ft_lst_insert(lst, strdup("bye2"), 100);
// 	ft_lst_set(lst, strdup("!=!=!=!"), 7, free);
// 	ft_lst_del(lst, 7, free);
// 	size_t i = 0;
// 	while (i < lst->size)
// 	{
// 		fprintf(stderr, "[ %s ] -> ", (char *)ft_lst_getc(lst, i));
// 		i++;
// 	}
// 	ft_lst_free(&lst, free);
// }