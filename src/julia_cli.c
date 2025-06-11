/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia_cli.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:25:47 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/11 16:04:33 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol_utils.h"
#include "ft_printf.h"

// 1. checks if imag is valid
int	valid_imag(const char *imag)
{
	int	dot_count;

	dot_count = 0;
	if (*imag == '-' || *imag == '+')
		imag++;
	while (ft_isdigit(*imag) || *imag == '.')
	{
		if (*imag == '.')
			dot_count++;
		imag++;
	}
	if (*imag != 'i' || imag[1] != '\0' || dot_count > 1)
		return (ft_printf(RED INVALID_INP_NBR RESET), 0);
	return (1);
}

// 1. checks if real is valid
int	valid_real(const char *real)
{
	int	dot_count;

	dot_count = 0;
	if (*real == '-' || *real == '+')
		real++;
	while (ft_isdigit(*real) || *real == '.')
	{
		if (*real == '.')
			dot_count++;
		real++;
	}
	if (*real != '\0' || dot_count > 1)
		return (ft_printf(RED INVALID_INP_NBR RESET), 0);
	return (1);
}

//1. atod
//2. get real and imaginary
t_nbr_i	julia_parse(const char *real, const char *imag)
{
	t_nbr_i	nbr_i;

	nbr_i.real = ft_atod(real);
	nbr_i.imag = ft_atod(imag);
	return (nbr_i);
}
