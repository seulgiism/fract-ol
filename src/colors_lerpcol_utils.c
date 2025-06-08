/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors_lerpcol_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 19:07:05 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/08 19:13:51 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// colors_lerpcol_utils.c
#include <stdint.h>

uint8_t	lerp_byte(uint8_t color1, uint8_t color2, double inter_pol)
{
	double	inter_pol2;

	inter_pol2 = (1.0 - inter_pol);
	return ((uint8_t)((color1 * inter_pol2) + (color2 * inter_pol)));	
}
