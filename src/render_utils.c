/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 15:43:18 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/18 16:38:01 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	p_mlxerror(void)
{
	const char	*str;

	str = mlx_strerror(mlx_errno);
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
