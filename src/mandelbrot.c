/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:25:47 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/11 16:37:14 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include "libft.h"

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

// #include <stdio.h>
// int main(void)
// {
// 	t_nbr_i c1 = {.real = 0.0, .imag = 0.0};
// 	int iters = 0;
//
// 	printf("is_mandel: %i, ", is_mandelbrot(c1, 1000, &iters));
// 	printf("iters: %i\n", iters);
// 	iters = 0;
//
// 	t_nbr_i c2 = {.real = 2.0, .imag = 1.0};
// 	printf("is_mandel: %i, ", is_mandelbrot(c2, 100, &iters));
// 	printf("iters: %i\n", iters);
// 	iters = 0;
//
// 	t_nbr_i c3 = {.real = -0.45, .imag = 0.45};
// 	printf("is_mandel: %i, ", is_mandelbrot(c3, 1000, &iters));
// 	printf("iters: %i\n", iters);
// 	iters = 0;
// }