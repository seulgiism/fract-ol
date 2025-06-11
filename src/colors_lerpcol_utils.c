/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors_lerpcol_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 19:07:05 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/11 16:03:54 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// colors_lerpcol_utils.c
#include "fractol_color_utils.h"
#include <stdint.h>

uint8_t	lerp_byte(uint8_t color1, uint8_t color2, double inter_pol)
{
	double	inter_pol2;

	inter_pol2 = (1.0 - inter_pol);
	return ((uint8_t)((color1 * inter_pol2) + (color2 * inter_pol)));
}

t_rgb_uint8	get_rgb_uint8(uint32_t color)
{
	t_rgb_uint8	rgb;

	rgb.red = (color >> 24);
	rgb.grn = (color >> 16);
	rgb.blu = (color >> 8);
	return (rgb);
}

uint32_t	get_rgb_uint32(t_rgb_uint8 rgb)
{
	return (rgb.red << 24 | rgb.grn << 16 | rgb.blu << 8 | 0xFF);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_rgb_uint8 rgb;
//
// 	rgb = get_rgb_uint8(0xFF00FFFF);
// 	printf("%i, %i, %i\n", rgb.red, rgb.grn, rgb.blu);
// 	printf("%.8X\n", get_rgb_uint32(rgb));
// 	printf("%i", lerp_byte(0, 255, 0.5));
// }