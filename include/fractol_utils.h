/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:39:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/07 18:40:43 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_UTILS_H
# define FRACTOL_UTILS_H

# define EXPECTED_OUTP "expected outputs:\n \
1. ./fractol mandelbrot\n \
2. ./fractol julia {real nbr} {imaginary nbr}\n \
                    -300.501   -402.10i\n 3. ./fractol TODO\n"

# define INVALID_INP_NBR "[invalid nbr given]\n"

// imaginary nbr
typedef struct s_nbr_i
{
	double	imag;
	double	real;
}	t_nbr_i;

// julia.c
int		valid_imag(const char *imag);
int		valid_real(const char *real);
t_nbr_i	julia_parse(const char *real, const char *imag);

// colors.c + colors_utils.c
void	get_init_hsv(double *hue, double *sat, double *val, \
						double *hue_spread);

#endif
