/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/06 01:26:50 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/06 01:53:59 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atod_perc(const char *nptr, double nbr);

double	ft_atod(const char *nptr)
{
	double	nbr;
	double	sign;

	nbr = 0.0;
	sign = 1.0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1.0;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		nbr = nbr * 10.0 + *nptr++ - '0';
	if (*nptr++ == '.')
		nbr = ft_atod_perc(nptr++, nbr);
	return (nbr * sign);
}

static double	ft_atod_perc(const char *nptr, double nbr)
{
	double	div;

	div = 10.0;
	while (ft_isdigit(*nptr))
	{
		nbr += (*nptr++ - '0') / div;
		div *= 10.0;
	}
	return (nbr);
}
