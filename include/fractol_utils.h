/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:39:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/09 18:39:30 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_UTILS_H
# define FRACTOL_UTILS_H

#include <stdint.h>

# define EXPECTED_INPT "[EXPECTED INPUTS]:\n \
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

// [JULIA]
// julia.c
int		valid_imag(const char *imag);
int		valid_real(const char *real);
t_nbr_i	julia_parse(const char *real, const char *imag);

// [COLORS]
// colors.c
typedef struct s_rgb
{
	double	red;
	double	grn;
	double	blu;
}	t_rgb;

typedef struct s_rgb_uint8
{
	uint8_t	red;
	uint8_t	grn;
	uint8_t	blu;
}	t_rgb_uint8;

typedef struct s_palette_i
{
	double		fract;
	int			base;
	double		leftover;
}	t_palette_i;

// colors_genpal_utils.c
void		get_init_hsv(double *hue, double *sat, double *val, \
						double *hue_spread);
uint32_t	hsv_to_rgb(double hue, double sat, double val);

// colors_lerpcol_utils.c
uint8_t		lerp_byte(uint8_t color1, uint8_t color2, double inter_pol);
t_rgb_uint8	get_rgb_uint8(uint32_t color);
uint32_t	get_rgb_uint32(t_rgb_uint8 rgb);

#endif
