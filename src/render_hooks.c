/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_hooks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 19:19:41 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/12 17:16:33 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_render_utils.h"
#include "fractol.h"
#include "MLX42.h"

// render_hooks.c
scroll_hook(double xdelta, double ydelta, t_render *render)
{
	(void) xdelta;
	if (
}

key_hook(mlx_key_data_t keydata, t_render *render)
{
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP
		&& render->fract.i_start + move_speed() < MAX_FRACT)
	{
		
	}
}

close_hook(void *param)
{
	
}

resize_hook(int32_t width, int32_t height, void *param)
{
	
}
