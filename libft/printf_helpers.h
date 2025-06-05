/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_helpers.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/11 17:32:11 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/24 18:16:51 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HELPERS_H
# define PRINTF_HELPERS_H

# include "ft_printf.h"
# include "stdint.h"
# include "stddef.h"
# include <stdarg.h>

// (ft_printf.c)
int			ft_write(char *str, size_t length, int *bytes_wrote);
int			ft_write_free(char *str, size_t length, int *bytes_wrote);
int			ft_write_flagscheck(char *str, size_t length, int *bytes_wrote, \
								t_flags flags);

// (pf_sometoa.c)
char		*ft_itoa_base_signed(int val, const char *base, bool *sign);
char		*ft_itoa_base_unsigned(unsigned int val, const char *base);
char		*ft_strtoa(char *str, t_flags flags);
char		*ft_ptoa(void *p);
char		*ft_ctoa(char c);

// (pf_set_flags/2.c)
char		*ft_get_flags(char *s, t_flags *flags, int *error);
void		ft_reset_flags(t_flags *flags);

// (pf_print_out.c)
int			ft_write_va_bonus(char *str, t_flags flags, int *bytes_wrote);

// (pf_get_va.c)
char		*ft_write_big_str(char *s, int *bytes_wrote);
int			ft_write_var(va_list ap, t_flags *flags, int *bytes_wrote);

#endif