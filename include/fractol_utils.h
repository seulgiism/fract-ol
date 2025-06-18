/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:39:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/18 16:40:14 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_UTILS_H
# define FRACTOL_UTILS_H

// libs
# include <stdint.h>
# include "MLX42.h"

// error messages
# define EXPECTED_INPT "[EXPECTED INPUTS]:\n \
1. ./fractol mandelbrot\n \
2. ./fractol julia {real nbr} {imaginary nbr}\n \
                    -300.501   -402.10i\n 3. ./fractol TODO\n"
# define INVALID_INP_NBR "[invalid nbr given]\n"

// fractol codes
# define JULIA 1
# define MANDELBROT 2
# define OTHER 3

// imaginary nbr
typedef struct s_nbr_i
{
	double	imag;
	double	real;
}	t_nbr_i;

typedef struct s_fract
{
	int		type;
	t_nbr_i	c;
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

void		p_mlxerror(void);

// [CLI PARSING]
// 	julia_cli.c
int			valid_imag(const char *imag);
int			valid_real(const char *real);
t_nbr_i		julia_parse(const char *real, const char *imag);

// [FRACTALS]
// 	julia.c mandelbrot.c
int			is_julia(t_nbr_i z, t_nbr_i c, int iter_max, int *iters);
int			is_mandelbrot(t_nbr_i c, int iter_max, int *iters);

// [COLORS]
// 	colors.c
uint32_t	get_color(int iters, t_nbr_i nbr_i, double time);

// [RENDER]
//	render.c
int			render(int fractal_type, t_nbr_i c);

//	render_move.c
void		move_up(t_render *render, uint32_t pixels);
void		move_down(t_render *render, uint32_t pixels);
void		move_right(t_render *render, uint32_t pixels);
void		move_left(t_render *render, uint32_t pixels);

// 	render_zoom.c
void		zoom(t_render *render, double ydelta);

//	render_itermax_utils.c
int			get_itersmax(t_render render);

//	render_hooks.c
void		scroll_hook(double xdelta, double ydelta, void *render);
void		key_hook(mlx_key_data_t keydata, void *render);
void		resize_hook(int32_t width, int32_t height, void *render);
void		close_hook(void *render);
void		loop_hook(void *render);

//	render_fract.c;
void		render_fract(t_render render);

#endif
