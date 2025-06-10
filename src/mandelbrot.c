/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:25:47 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/10 02:30:53 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include "libft.h"

// TODO: BUG CHECK
// return param: iterations
// return	   : 1 or 0 is_mandelbrot
int	is_mandelbrot(t_nbr_i c, int iter_max, int *iters)
{
	double	tmp_real;
	t_nbr_i	z;

	z.real = 0;
	z.imag = 0;
	*iters = 0;
	while (*iters < iter_max)
	{
		tmp_real = (z.real * z.real) - (z.imag * z.imag);
		z.imag = (2 * z.real * z.imag) + c.imag;
		z.real = tmp_real + c.real;
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			return (0);
		(*iters)++;
	}
	return (1);
}
