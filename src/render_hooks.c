/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_hooks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 19:19:41 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/18 16:31:41 by kclaes        ########   odam.nl         */
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
}

void	resize_hook(int32_t width, int32_t height, void *render)
{
	mlx_set_window_size(((t_render *) render)->mlx, width, height);
}

void	close_hook(void *render)
{
	mlx_close_window(((t_render *) render)->mlx);
}

void	loop_hook(void *render)
{
	render_fract(*((t_render *) render));
}
