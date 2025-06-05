/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:25:47 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/05 20:12:39 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol_utils.h"
#include "ft_printf.h"

// 1. checks if nbr is valid
int	ft_valid_nbr(const char *arg1, const char *arg2)
{
	if (*arg1 == '-' || *arg1 == '+')
		arg1++;
	while (ft_isdigit(*arg1) || *arg1 == '.')
		arg1++;
	if (*arg1 != '\0')
		return (ft_printf(RED INVALID_INP_NBR RESET), 0);
	if (*arg2 == '-' || *arg2 == '+')
		arg2++;
	while (ft_isdigit(*arg2) || *arg2 == '.')
		arg2++;
	if (*arg2 != 'i' || *(arg2 + 1) != '\0')
		return (ft_printf(RED INVALID_INP_NBR RESET), 0);
	return (1);
}

// 1. atod
// 2. get real and imaginary
// int	ft_julia_parse(const char *arg1, const char *arg2, t_nbr_i *nbr_i)
// {
// }
