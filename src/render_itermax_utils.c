/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_itermax_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 15:17:28 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/26 17:22:49 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include <math.h>

int	get_itersmax(t_render *render)
{
	static double	last_zoom = 0;
	double			zoom;

	zoom = ((*render).fract.i_start + (*render).fract.i_end + \
			(*render).fract.r_start + (*render).fract.r_end) / 4;
	if (zoom == last_zoom)
		return ((*render).fract.iter_max);
	zoom = fabs(zoom);
	
}

// #include <stdio.h>
// int main(void)
// {
// 	double	zoom = 0.00000000001;
// 	int		iters_max = 0;
//
// 	iters_max = calc_itersmax(zoom);
// 	printf("zoom: %f, iter: %i\n", zoom, iters_max);
//
// 	// same zoom
// 	iters_max = calc_itersmax(zoom);
// 	printf("zoom: %f, iter: %i\n", zoom, iters_max);
//
// 	zoom = 0.00001;
// 	iters_max = calc_itersmax(zoom);
// 	printf("zoom: %f, iter: %i\n", zoom, iters_max);
// }