/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 16:40:14 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/12 20:08:11 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol_render_utils.h"
#include "fractol.h"
#include <math.h>
#include <stdbool.h>

static double	get_move_speed(double start, double end, bool positive, \
								double scale);

void	move_right(t_render *render)
{
	double	step_size;
	double	scale;
	
	scale = (render->fract.i_end - render->fract.i_start) / render->img->width;
	step_size = get_move_speed(render->fract.i_start, render->fract.i_end, true,\
								scale);
	render->fract.i_end += step_size;
	render->fract.i_start += step_size;
}

void	move_up(t_render *render)
{
	double	step_size;
	double	scale;
	
	scale = (render->fract.r_end - render->fract.r_start) / render->img->width;
	step_size = get_move_speed(render->fract.r_start, render->fract.r_end, true,\
								scale);
	render->fract.r_end += step_size;
	render->fract.r_start += step_size;
}

void	move_left(t_render *render)
{
	double	step_size;
	double	scale;
	
	scale = (render->fract.i_end - render->fract.i_start) / render->img->width;
	step_size = get_move_speed(render->fract.i_start, render->fract.i_end, false,\
								scale);
	render->fract.i_end -= step_size;
	render->fract.i_start -= step_size;
}

void	move_down(t_render *render)
{
	double	step_size;
	double	scale;
	
	scale = (render->fract.r_end - render->fract.r_start) / render->img->width;
	step_size = get_move_speed(render->fract.r_start, render->fract.r_end, false,\
								scale);
	render->fract.r_end += step_size;
	render->fract.r_start += step_size;
}

static double	get_move_speed(double start, double end, bool positive, double scale)
{
	double	step_size;
	
	step_size = scale * MOVE_SPEED;
	if (positive)
	{
		if (end + step_size >= MAX_FRACT)
			step_size = MAX_FRACT - end;
	}
	else
	{
		if (start - step_size <= MIN_FRACT)
			step_size = start - MIN_FRACT;
	}
	return (step_size);
}

#include <stdio.h>
int	main(void)
{

	t_render	render;
	
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	render.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!render.mlx)
		p_mlxerror();
	render.img = mlx_new_image(render.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(render.mlx, render.img, 0, 0);

	render.fract.i_start = -0.060;
	render.fract.i_end = 0.015;
	
	printf("start: %.18f , end: %.18f\n", render.fract.i_start, render.fract.i_end);
	for (int i = 0; i < 500; i++)
	{
		move_left(&render);
		printf("start: %.18f , end: %.18f\n", render.fract.i_start, render.fract.i_end);
	}
}