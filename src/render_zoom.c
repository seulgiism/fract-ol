/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_zoom.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/17 18:32:43 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/18 16:42:46 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol_utils.h"
#include "fractol.h"
#include <math.h>
#include <stdbool.h>

//static t_nbr_i	get_mouse_pos(t_render render, int32_t x, int32_t y);
static void		move(t_render *render, uint32_t x, uint32_t y);
static void		zoom_center(t_render *render, uint32_t ydelta);
static void		boundry_correction(t_render *render);

void	zoom(t_render *render, double ydelta)
{
	int32_t	x;
	int32_t	y;
	//t_nbr_i	mouse_pos;

	if (ydelta > 0)
	{
		//mouse_pos = get_mouse_pos(*render, x, y);
		mlx_get_mouse_pos(render->mlx, &x, &y);
		move(render, x, y);
		zoom_center(render, ydelta);
	}
	else if (ydelta < 0)
	{
		zoom_center(render, ydelta);
		boundry_correction(render);
	}
	else
		return ;
}

// static t_nbr_i	get_mouse_pos(t_render render, int32_t *x, int32_t *y)
// {
// 	t_nbr_i	mouse_pos;
// 	t_nbr_i	scale;
//
// 	mlx_get_mouse_pos(render.mlx, &x, &y);
// 	scale.imag = (render.fract.i_end - render.fract.i_start) \
// 					/ render.img->height;
// 	scale.real = (render.fract.r_end - render.fract.r_start) \
// 					/ render.img->width;
// 	mouse_pos.imag = (y * scale.imag) + render.fract.i_start;
// 	mouse_pos.real = (x * scale.real) + render.fract.r_start;
// 	return (mouse_pos);
// }

static void	move(t_render *render, uint32_t x, uint32_t y)
{
	if (x >= render->img->width / 2)
		move_right(render, x - (render->img->width / 2));
	else
		move_left(render, (render->img->width / 2) - x);
	if (y >= render->img->height / 2)
		move_up(render, y - (render->img->width / 2));
	else
		move_down(render, (render->img->width / 2) - y);
}

static void	zoom_center(t_render *render, uint32_t ydelta)
{
	t_nbr_i	center;
	t_nbr_i	offset;
	double	scroll_speed;

	if (ydelta > 0)
		scroll_speed = SCROLL_SPEED;
	else
		scroll_speed = 1 / SCROLL_SPEED;
	center.real = (render->fract.r_start + render->fract.r_end) / 2;
	center.imag = (render->fract.i_start + render->fract.i_end) / 2;
	offset.real = (render->fract.r_end - center.real) / scroll_speed;
	offset.imag = (render->fract.i_end - center.imag) / scroll_speed;
	render->fract.r_end = center.real + offset.real;
	render->fract.r_start = center.real - offset.real;
	render->fract.i_end = center.imag + offset.imag;
	render->fract.i_start = center.imag - offset.imag;
}

static void	boundry_correction(t_render *render)
{
	if (render->fract.r_start < MIN_FRACT)
		render->fract.r_start = MIN_FRACT;
	if (render->fract.r_end > MAX_FRACT)
		render->fract.r_end = MAX_FRACT;
	if (render->fract.i_start < MIN_FRACT)
		render->fract.i_start = MIN_FRACT;
	if (render->fract.i_end > MAX_FRACT)
		render->fract.i_end = MAX_FRACT;
}
