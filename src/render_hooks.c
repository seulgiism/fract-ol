/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_hooks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 19:19:41 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/17 19:54:33 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_render_utils.h"
#include "fractol_utils.h"
#include "fractol.h"
#include "MLX42.h"

// render_hooks.c
void scroll_hook(double xdelta, double ydelta, t_render *render)
{
	(void) xdelta;
	zoom(render, ydelta);
}

void key_hook(mlx_key_data_t keydata, t_render *render)
{
	if (keydata.key == MLX_KEY_X)
	{
		close_hook(); // TODO
	}
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
	{
		return (move_up(render, MOVE_SPEED));
	}
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
	{
		return (move_right(render, MOVE_SPEED));
	}
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
	{
		return (move_down(render, MOVE_SPEED));
	}
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
	{
		return (move_left(render, MOVE_SPEED));
	}
}

void close_hook(t_render *render)
{
	// TODO?
}

void resize_hook(int32_t width, int32_t height, t_render *render)
{
	// RESIZE IMG WITH THIS
}

void render_fract()
{
	
}
