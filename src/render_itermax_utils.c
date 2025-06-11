/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_itermax_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 15:17:28 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/11 16:36:09 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	calc_itersmax(double zoom)
{
	static double	last_zoom = 0;
	static int		last_iters_max = 0;

	if (zoom == last_zoom)
		return (last_iters_max);
	if (zoom > 0.01)
		return (last_zoom = zoom, last_iters_max = 50);
	else if (zoom > 0.001)
		return (last_zoom = zoom, last_iters_max = 100);
	else if (zoom > 0.0001)
		return (last_zoom = zoom, last_iters_max = 200);
	else if (zoom > 0.00001)
		return (last_zoom = zoom, last_iters_max = 300);
	else if (zoom > 0.000001)
		return (last_zoom = zoom, last_iters_max = 500);
	else if (zoom > 0.0000001)
		return (last_zoom = zoom, last_iters_max = 700);
	else if (zoom > 0.000000001)
		return (last_zoom = zoom, last_iters_max = 1000);
	else if (zoom > 0.00000000001)
		return (last_zoom = zoom, last_iters_max = 1500);
	else
		return (last_zoom = zoom, last_iters_max = 3000);
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