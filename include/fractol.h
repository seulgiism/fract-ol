/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/05 18:39:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/06/11 20:08:28 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// color palette
# define PALETTE_SIZE 256//don't touch
# define HUE_START 0// min is 0
# define HUE_END 360// max is 360 
# define SAT 1 //min is 0, max is 1
# define VAL 1 //min is 0, max is 1
# define AMPLIFY 1// min is 1 // only touch for fun
# define BREATH 10// min is 1, the bigger the slower, 
// disable breath by typing # define BREATH time

// window
# define WIDTH 256
# define HEIGHT 256

#endif
