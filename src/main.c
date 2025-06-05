/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:18:34 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/05 20:17:41 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fractol_utils.h"
#include "colors.h"

int	main(int argc, char *argv[])
{
	if (argc == 2 && ft_streq("mandelbrot", argv[1], true))
	{
		ft_printf("MANDEL!");
	}
	else if (argc == 3 && ft_streq("julia", argv[1], true) \
			&& ft_valid_nbr(argv[2], argv[3]))
	{
		ft_printf("JULIA!");
	}
	ft_printf(COLOR_BRIGHT_MAGENTA EXPECTED_OUTP COLOR_RESET);
}
