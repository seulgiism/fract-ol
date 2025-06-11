/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 15:09:02 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/11 19:20:39 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	p_mlxerror(void);

int	draw_fract(int fractal_type)
{
	mlx_t	*mlx;
	
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!mlx)
		p_mlxerror();
	mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
}

static scroll_handler(double xdelta, double ydelta, void *param)
{
	if ()
}

static close_handle(void *param)

static void	p_mlxerror(void)
{
	char	*str;

	str = mlx_strerror(mlx_errno);
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
