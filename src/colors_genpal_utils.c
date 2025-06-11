/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors_genpal_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/07 17:59:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/11 14:27:56 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// colors_generate_palette_utils.c
#include "fractol.h"
#include "fractol_color_utils.h"
#include "stdint.h"
#include <math.h>

void	get_init_hsv(double *hue, double *sat, double *val, \
						double *hue_spread)
{
	double	hue_end;

	hue_end = HUE_END;
	if (*hue < 0)
		*hue = 0;
	else if (*hue >= 360)
		*hue = 360 - 1;
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
	else if (hue_end >= 360)
		hue_end = 360;
	*hue_spread = (hue_end - *hue) / PALETTE_SIZE;
}

static t_rgb	get_rgb(double chroma, double mid_rgb, double hue);
static t_rgb	set_rgb(double red, double green, double blue);

// chroma is max - min of RGB values
// https://cs.stackexchange.com/questions/64549/convert-hsv-to-rgb-colors
uint32_t	hsv_to_rgb(double hue, double sat, double val)
{
	double	chroma;
	double	min;
	double	mid_rgb;
	t_rgb	rgb;
	uint8_t	red;
	uint8_t	grn;
	uint8_t blu;

	chroma = sat * val;
	min = val - chroma;
	mid_rgb = chroma * (1 - fabs(fmod(hue / 60.0, 2) - 1));
	rgb = get_rgb(chroma, mid_rgb, hue);
	red = (uint8_t)((rgb.red + min) * 255 + 0.5);
	grn = (uint8_t)((rgb.grn + min) * 255 + 0.5);
	blu = (uint8_t)((rgb.blu + min) * 255 + 0.5);
	return (red << 24 | grn << 16 | blu << 8 | 255);
}

static t_rgb	get_rgb(double chroma, double mid_rgb, double hue)
{
	if (hue < 60)
		return (set_rgb(chroma, mid_rgb, 0));
	else if (hue < 120)
		return (set_rgb(mid_rgb, chroma, 0));
	else if (hue < 180)
		return (set_rgb(0, chroma, mid_rgb));
	else if (hue < 240)
		return (set_rgb(0, mid_rgb, chroma));
	else if (hue < 300)
		return (set_rgb(mid_rgb, 0, chroma));
	else
		return (set_rgb(chroma, 0, mid_rgb));
}

static t_rgb	set_rgb(double red, double green, double blue)
{
	t_rgb	rgb;

	rgb.red = red;
	rgb.grn = green;
	rgb.blu = blue;
	return (rgb);
}

// test for get_init_hsv
// #include "libft.h"
// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	double	hue;
// 	double	hue_spread;
// 	double	sat;
// 	double	val;
// 	double	hue_end;
//
// 	if (argc != 5)
// 		return (1);
// 	hue = ft_atod(argv[1]);
// 	hue_end = ft_atod(argv[2]);
// 	sat = ft_atod(argv[3]);
// 	val = ft_atod(argv[4]);
// 	get_init_hsv(&hue, &sat, &val, &hue_spread, hue_end);
// 	printf("hue:        %f\n"
// 			"hue_spread: %f\n"
// 			"sat:        %f\n"
// 			"val:        %f\n"
// 			, hue, hue_spread, sat, val);
// 	for (int i = 0; i < PALETTE_SIZE; i++)
// 		hue += hue_spread;
// 	printf("hue_end:    %f\n", hue);
// }
//
// // test hex translations
// #include "libft.h"
// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	double	hue;
// 	double	sat;
// 	double	val;
// 	uint32_t	COLOR;
//
// 	if (argc != 4)
// 		return (1);
// 	hue = ft_atod(argv[1]);
// 	sat = ft_atod(argv[2]);
// 	val = ft_atod(argv[3]);
// 	printf("hue: %lf\n", hue);
// 	printf("sat: %lf\n", sat);
// 	printf("val: %lf\n", val);
// 	COLOR = hsv_to_rgb(hue, sat, val);
// 	printf("%.8X\n", COLOR);
// }
