/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/07 17:59:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/07 19:10:09 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	get_init_hsv(double *hue, double *sat, double *val, \
						double *hue_spread)
{
	double	hue_end;

	hue_end = HUE_END;
	if (*hue < 0)
		*hue = 0;
	else if (*hue >= PALETTE_SIZE)
		*hue = PALETTE_SIZE - 1;
	if (*sat < 0)
		*sat = 0;
	else if (*sat > 1)
		*sat = 1;
	if (*val < 0)
		*val = 0;
	else if (*val > 1)
		*val = 1;
	if (hue_end <= *hue)
		hue_end = *hue + 1;
	else if (hue_end >= PALETTE_SIZE)
		hue_end = PALETTE_SIZE;
	*hue_spread = (hue_end - *hue) / PALETTE_SIZE;
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	double	hue;
// 	double	hue_spread;
// 	double	sat;
// 	double	val;
// 	double	hue_end;

// 	if (argc != 5)
// 		return (1);
// 	hue = ft_atod(argv[1]);
// 	hue_end = ft_atod(argv[2]);
// 	sat = ft_atod(argv[3]);
// 	val = ft_atod(argv[4]);
// 	get_init_hsv(&hue, &sat, &val, &hue_spread, hue_end);
// 	printf("hue:        %f\n"\
// 			"hue_spread: %f\n"\
// 			"sat:        %f\n"\
// 			"val:        %f\n"\
// 			, hue, hue_spread, sat, val);
// 	for (int i = 0; i < PALETTE_SIZE; i++)
// 		hue += hue_spread;
// 	printf("hue_end:    %f\n", hue);
// }