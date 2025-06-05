/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 13:22:23 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/20 17:26:21 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include <stddef.h>

// (ft_lst)
typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	struct s_node	*first;
	struct s_node	*last;
	size_t			size;
}	t_list;

// (ft_lst_manage.c)
t_list	*ft_lst_create(void);
t_node	*ft_lst_newnode(void *content);
void	ft_lst_free(t_list **lst, void (*del)(void*));
void	ft_lst_delnode(t_node *node, void (*del)(void*));

// (ft_lst_add.c)
void	*ft_lst_append(t_list *lst, void *content);
void	*ft_lst_prepend(t_list *lst, void *content);
void	*ft_lst_insert(t_list *lst, void *content, size_t i);
void	*ft_lst_set(t_list *lst, void *content, size_t i, void (*del)(void *));

// (ft_lst_del.c)
void	ft_lst_depend(t_list *lst, void (*del)(void *));
void	ft_lst_deprepend(t_list *lst, void (*del)(void *));
void	ft_lst_del(t_list *lst, size_t i, void (*del)(void *));

// (ft_lst_get.c)
t_node	*ft_lst_get(t_list *lst, size_t i);
t_node	*ft_lst_getlast(t_list *lst);
t_node	*ft_lst_getfirst(t_list *lst);
size_t	ft_lst_getsize(t_list *lst);

// (ft_lst_getcont.c)
void	*ft_lst_getc(t_list *lst, size_t i);
void	*ft_lst_getclast(t_list *lst);
void	*ft_lst_getcfirst(t_list *lst);

#endif