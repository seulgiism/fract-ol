/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 00:25:41 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/16 18:57:22 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRLST_H
# define FT_ARRLST_H

# include <stddef.h>

typedef struct s_arrlst
{
	void	**arr;
	size_t	cap;
	size_t	len;
	size_t	strt_cap;
	size_t	strt_len;
}	t_arrlst;

// (ft_arrlst_manage.c)
t_arrlst	*ft_arrlst_create(size_t cap, size_t len);
t_arrlst	*ft_arrlst_reset(t_arrlst **arrlst, void (*del)(void *));
void		ft_arrlst_free(t_arrlst **arrlst, void (*del)(void *));

// (ft_arrlst_utils.c)
t_arrlst	*ft_arrlst_grow(t_arrlst **arrlst, void (*del)(void *));
t_arrlst	*ft_arrlst_shrink(t_arrlst **arrlst, void (*del)(void *));

// (ft_arrlst_set.c)
t_arrlst	*ft_arrlst_append(t_arrlst **arrlst, void *content, \
								void (*del)(void *));
t_arrlst	*ft_arrlst_set(t_arrlst **arrlst, size_t i, void *content, \
								void (*del)(void *));

// (ft_arrlst_del.c)
t_arrlst	*ft_arrlst_del_null(t_arrlst **arrlst, size_t i, \
									void (*del)(void *));
t_arrlst	*ft_arrlst_del_shift(t_arrlst **arrlst, size_t i, \
									void (*del)(void *));
t_arrlst	*ft_arrlst_deppend(t_arrlst **arrlst, \
								void (*del)(void *));

// (ft_arrlst_get.c)
size_t		ft_arrlst_get_len(t_arrlst *arrlst);
size_t		ft_arrlst_get_cap(t_arrlst *arrlst);
void		*ft_arrlst_get_i(t_arrlst *arrlst, size_t i);

#endif
