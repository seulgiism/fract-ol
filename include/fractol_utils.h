/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:39:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/11 20:11:29 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_UTILS_H
# define FRACTOL_UTILS_H

// libs
# include <stdint.h>

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

#endif
