/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 15:43:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/12 15:47:37 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "stdlib.h"

void	p_mlxerror(void)
{
	char	*str;

	str = mlx_strerror(mlx_errno);
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
