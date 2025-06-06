/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:18:34 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/06 02:06:55 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fractol_utils.h"
#include "colors.h"

int	main(int argc, char *argv[])
{
	t_nbr_i	const_i;

	if (argc == 2 && ft_streq("mandelbrot", argv[1], true))
	{
		
	}
	else if (argc == 4 && ft_streq("julia", argv[1], true) \
			&& ft_valid_real(argv[2]) && ft_valid_imag(argv[3]))
	{
		const_i = ft_julia_parse(argv[2], argv[3]);
	}
	else
	{
		ft_printf(COLOR_BRIGHT_MAGENTA EXPECTED_OUTP COLOR_RESET);
	}
}
