/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 15:09:02 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/26 17:01:42 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol.h"
#include "fractol_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	init_fract(t_render *render, int fractal_type, t_nbr_i c);

int	render(int fractal_type, t_nbr_i c)
{
	t_render	render;

	init_fract(&render, fractal_type, c);
	render.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!render.mlx)
		p_mlxerror();
	render.img = mlx_new_image(render.mlx, WIDTH, HEIGHT);
	if (!render.img || (mlx_image_to_window(render.mlx, render.img, 0, 0) < 0))
		p_mlxerror();
	mlx_scroll_hook(render.mlx, scroll_hook, &render);
	mlx_key_hook(render.mlx, key_hook, &render);
	mlx_resize_hook(render.mlx, resize_hook, &render);
	mlx_close_hook(render.mlx, close_hook, &render);
	render_fract(&render);
	mlx_loop(render.mlx);
	mlx_terminate(render.mlx);
	return (EXIT_SUCCESS);
}

static void	init_fract(t_render *render, int fractal_type, t_nbr_i c)
{
	render->fract.type = fractal_type;
	render->fract.c = c;
	render->fract.r_start = MIN_FRACT;
	render->fract.i_start = MIN_FRACT;
	render->fract.r_end = MAX_FRACT;
	render->fract.i_end = MAX_FRACT;
	render->fract.iter_max = 100;
}
