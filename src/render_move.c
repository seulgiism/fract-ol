/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 16:40:14 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/17 18:53:40 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol_render_utils.h"
#include "fractol_move_utils.h"
#include "fractol.h"
#include <math.h>
#include <stdbool.h>

static double	get_move_speed(t_move move, double scale, int32_t pixels);

void	move_up(t_render *render, int32_t pixels)
{
	double	step_size;
	double	scale;
	t_move	move;

	move.start = render->fract.i_start;
	move.end = render->fract.i_end;
	move.positive = true;
	scale = (render->fract.i_end - render->fract.i_start) / render->img->width;
	step_size = get_move_speed(move, scale, pixels);
	render->fract.i_end += step_size;
	render->fract.i_start += step_size;
}

void	move_right(t_render *render, int32_t pixels)
{
	double	step_size;
	double	scale;
	t_move	move;

	move.start = render->fract.r_start;
	move.end = render->fract.r_end;
	move.positive = true;
	scale = (render->fract.r_end - render->fract.r_start) / render->img->width;
	step_size = get_move_speed(move, scale, pixels);
	render->fract.r_end += step_size;
	render->fract.r_start += step_size;
}

void	move_down(t_render *render, int32_t pixels)
{
	double	step_size;
	double	scale;
	t_move	move;

	move.start = render->fract.i_start;
	move.end = render->fract.i_end;
	move.positive = false;
	scale = (render->fract.i_end - render->fract.i_start) / render->img->width;
	step_size = get_move_speed(move, scale, pixels);
	render->fract.i_end -= step_size;
	render->fract.i_start -= step_size;
}

void	move_left(t_render *render, uint32_t pixels)
{
	double	step_size;
	double	scale;
	t_move	move;

	move.start = render->fract.r_start;
	move.end = render->fract.r_end;
	move.positive = true;
	scale = (render->fract.r_end - render->fract.r_start) / render->img->width;
	step_size = get_move_speed(move, scale, pixels);
	render->fract.r_end -= step_size;
	render->fract.r_start -= step_size;
}

// scale == 1 pixel in fractal depth
static double	get_move_speed(t_move move, double scale, int32_t pixels)
{
	double	step_size;

	step_size = scale * pixels;
	if (move.positive)
	{
		if (move.end + step_size >= MAX_FRACT)
			step_size = MAX_FRACT - move.end;
	}
	else
	{
		if (move.start - step_size <= MIN_FRACT)
			step_size = move.start - MIN_FRACT;
	}
	return (step_size);
}

// #include <stdio.h>
// int	main(void)
// {
//
// 	t_render	render;
//
// 	mlx_set_setting(MLX_STRETCH_IMAGE, true);
// 	render.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
// 	render.img = mlx_new_image(render.mlx, WIDTH, HEIGHT);
// 	mlx_image_to_window(render.mlx, render.img, 0, 0);
//
// 	render.fract.i_start = -1.75;
// 	render.fract.i_end = 1.75;
// 	render.fract.r_start = -1.75;
// 	render.fract.r_end = 1.75;
//
// 	printf("start: %.18f , end: %.18f\n", render.fract.r_start, render.fract.r_end);
// 	for (int i = 0; i < 1; i++)
// 	{
// 		move_down(&render, 30);
// 		//move_right(&render, MOVE_SPEED);
// 		printf("start: %.18f , end: %.18f\n", render.fract.r_start, render.fract.r_end);
// 	}
// }