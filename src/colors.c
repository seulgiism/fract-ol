/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/07 17:59:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/08 20:03:33 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_utils.h"
#include <stddef.h>
#include <stdint.h>

static void	generate_palette(uint32_t palette[]);

uint32_t get_color(int iters, int z)
{
	static uint32_t palette[PALETTE_SIZE] = {0};
	
	if (palette[0] == 0)
		generate_palette(palette);
}

static void	generate_palette(uint32_t palette[])
{
	double	hue;
	double	hue_spread;
	double	sat;
	double	val;
	int		i;

	hue = HUE_START;
	sat = SAT;
	val = VAL;
	get_init_hsv(&hue, &sat, &val, &hue_spread);
	i = 0;
	while (i < PALETTE_SIZE)
	{
		palette[i++] = hsv_to_rgb(hue, sat, val);
		hue += hue_spread;
	}
}

static uint32_t lerp_color(uint32_t color1, uint32_t color2, \
							double inter_pol)
{
	t_rgb_uint8	rgb1;
	t_rgb_uint8	rgb2;
	t_rgb_uint8 rgb_final;

	rgb1 = get_rgb_uint8(color1);
	rgb2 = get_rgb_uint8(color2);
	rgb_final.red = lerp_byte(rgb1.red, rgb2.red, inter_pol);
	rgb_final.grn = lerp_byte(rgb1.grn, rgb2.grn, inter_pol);
	rgb_final.blu = lerp_byte(rgb1.blu, rgb2.blu, inter_pol);
	return (get_rgb_uint32(rgb_final));
}

// #include <stdio.h>
// int main(void)
// {
// 	uint32_t red = 0xFF0000FF;
// 	uint32_t green = 0x00FF00FF;
// 	uint32_t mix = lerp_color(red, green, 0.5);
// 	printf("%.8X", mix);
// }
//