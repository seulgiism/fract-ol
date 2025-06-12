/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_render_utils.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 15:48:10 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/12 19:44:29 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_RENDER_UTILS_H
# define FRACTOL_RENDER_UTILS_H

# include "MLX42.h"



typedef struct s_fract
{
	double	i_start;
	double	i_end;
	double	r_start;
	double	r_end;
}	t_fract;

typedef struct s_render
{
	t_fract		fract;
	mlx_image_t	*img;
	mlx_t		*mlx;
}	t_render;

void	p_mlxerror(void);

#endif