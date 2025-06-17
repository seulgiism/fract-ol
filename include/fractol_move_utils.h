/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_move_utils.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/17 15:46:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/17 15:49:15 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_MOVE_UTILS_H
# define FRACTOL_MOVE_UTILS_H

# include <stdbool.h>

typedef struct s_move
{
	double	start;
	double	end;
	bool	positive;
}	t_move;

#endif