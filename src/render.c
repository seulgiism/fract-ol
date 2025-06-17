/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 15:09:02 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/17 19:47:13 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol.h"
#include "fractol_render_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	render(int fractal_type)
{
	t_render	render;
	
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	render.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!render.mlx)
		p_mlxerror();
	render.img = mlx_new_image(render.mlx, WIDTH, HEIGHT);
	if (!render.img || (mlx_image_to_window(render.mlx, render.img, 0, 0) < 0))
		ft_error();
}

