/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_hooks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 19:19:41 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/26 17:00:38 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include "fractol.h"
#include "MLX42.h"
#include "fractol_move_utils.h"

// render_hooks.c
void	scroll_hook(double xdelta, double ydelta, void *render)
{
	(void) xdelta;
	zoom((t_render *) render, ydelta);
	render_fract((t_render *) render);
}

void	key_hook(mlx_key_data_t keydata, void *render)
{
	if (keydata.key == MLX_KEY_X)
	{
		close_hook(render);
	}
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
	{
		return (move_up((t_render *) render, MOVE_SPEED));
	}
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
	{
		return (move_right((t_render *) render, MOVE_SPEED));
	}
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
	{
		return (move_down((t_render *) render, MOVE_SPEED));
	}
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
	{
		return (move_left((t_render *) render, MOVE_SPEED));
	}
	render_fract((t_render *) render);
}

void	resize_hook(int32_t width, int32_t height, void *render)
{
	if (height > width)
		height = width;
	else
		width = height;
	mlx_resize_image(((t_render *) render)->img, width, height);
	render_fract((t_render *) render);
}

void	close_hook(void *render)
{
	mlx_close_window(((t_render *) render)->mlx);
}
