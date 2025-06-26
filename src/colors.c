/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/07 17:59:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/26 17:13:51 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_utils.h"
#include "fractol_color_utils.h"
#include "libft.h"
#include <stddef.h>
#include <stdint.h>
#include <math.h>

static void			generate_palette(uint32_t palette[]);
static t_palette_i	get_palette_index(int iters, t_render render);
static uint32_t		lerp_color(uint32_t color1, uint32_t color2, \
								double inter_pol);

uint32_t	get_color(int iters, t_render render, double time)
{
	static uint32_t	palette[PALETTE_SIZE] = {0};
	t_palette_i		palette_i;
	uint32_t		color1;
	uint32_t		color2;

	if (palette[0] == 0)
		generate_palette(palette);
	palette_i = get_palette_index(iters, render);
	color1 = palette[(palette_i.base + (int)(time * BREATH)) \
						& (PALETTE_SIZE - 1)];
	color2 = palette[(palette_i.base + 1 + (int)(time * BREATH)) \
						& (PALETTE_SIZE - 1)];
	return (lerp_color(color1, color2, palette_i.leftover));
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

static t_palette_i	get_palette_index(int iters, t_render render)
{
	t_palette_i	palette_i;

	palette_i.fract = (double)iters / render.fract.iter_max \
						* (PALETTE_SIZE - 1);
	palette_i.base = (int)palette_i.fract;
	palette_i.leftover = palette_i.fract - palette_i.base;
	return (palette_i);
}

static uint32_t	lerp_color(uint32_t color1, uint32_t color2, \
							double inter_pol)
{
	t_rgb_uint8	rgb1;
	t_rgb_uint8	rgb2;
	t_rgb_uint8	rgb_final;

	rgb1 = get_rgb_uint8(color1);
	rgb2 = get_rgb_uint8(color2);
	rgb_final.red = lerp_byte(rgb1.red, rgb2.red, inter_pol);
	rgb_final.grn = lerp_byte(rgb1.grn, rgb2.grn, inter_pol);
	rgb_final.blu = lerp_byte(rgb1.blu, rgb2.blu, inter_pol);
	return (get_rgb_uint32(rgb_final));
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	if (argc != 4)
// 		return (1);
// 	int iters = ft_atoi(argv[1]);
// 	t_nbr_i z;
// 	z.real = ft_atod(argv[2]);
// 	z.imag = ft_atod(argv[3]);
// 	printf("iters: %i, z.real: %f, z.imag: %f\n\n", iters, z.real, z.imag);
// 	uint32_t color = get_color(iters, z);
// 	printf("get-color: %.8X\n", color);
// }
// #include <stdio.h>
// int main(void)
// {
// 	uint32_t palette[PALETTE_SIZE] = {0};
// 	generate_palette(palette);
// 	for (int i = 0; i < PALETTE_SIZE; i++)
// 	{
// 		printf("%.8X\n", palette[i]);
// 	}
// }
// #include <stdio.h>
// int main(void)
// {
// 	uint32_t red = 0xFF0000FF;
// 	uint32_t green = 0x00FF00FF;
// 	uint32_t mix = lerp_color(red, green, 0.5);
// 	printf("%.8X", mix);
// }
//