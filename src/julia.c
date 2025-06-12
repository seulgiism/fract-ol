/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:25:47 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/12 17:17:38 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include "fractol.h"
#include "libft.h"
#include "math.h"

// return param: iterations
// return	   : 1 or 0 is_julia
int	is_julia(t_nbr_i z, t_nbr_i c, int iter_max, int *iters)
{
	double	tmp_real;

	*iters = 0;
	while (*iters < iter_max)
	{
		tmp_real = (z.real * z.real) - (z.imag * z.imag);
		z.imag = (2 * z.real * z.imag) + c.imag;
		z.real = tmp_real + c.real;
		if ((z.real * z.real) + (z.imag * z.imag) \
			> fabs(MAX_FRACT) * fabs(MIN_FRACT))
			return (0);
		(*iters)++;
	}
	return (1);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_nbr_i c1 = {.real = 0.0, .imag = 0.0};
// 	t_nbr_i z1 = {.real = -0.8, .imag = 0.156};
// 	int iters = 0;
//
// 	printf("is_julia: %i, ", is_julia(z1, c1, 300, &iters));
// 	printf("iters: %i\n", iters);
// 	iters = 0;
//
// 	t_nbr_i c2 = {.real = 1.5, .imag = 1.5};
// 	t_nbr_i z2 = {.real = -0.8, .imag = 0.156};
// 	printf("is_julia: %i, ", is_julia(z2, c2, 100, &iters));
// 	printf("iters: %i\n", iters);
// 	iters = 0;
//
// 	t_nbr_i c3 = {.real = -0.1, .imag = 0.651};
// 	t_nbr_i z3 = {.real = -0.8, .imag = 0.156};
// 	printf("is_julia: %i, ", is_julia(z3, c3, 1000, &iters));
// 	printf("iters: %i\n", iters);
// 	iters = 0;
// }