/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:25:47 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/10 01:50:46 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include "libft.h"

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
	}
	if (ft_abs(z.real) < 2 && ft_abs(z.imag) < 2)
		return (1);
	return (0);
}
