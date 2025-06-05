/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_sometoa.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:40:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/22 13:19:53 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "printf_helpers.h"
#include <stdlib.h>
#include <stdint.h>

char	*ft_itoa_base_signed(int val, const char *base, bool *sign)
{
	unsigned int	uval;

	if (val < 0)
	{
		uval = ((unsigned int) -(val + 1)) + 1;
		*sign = true;
	}
	else
		uval = (unsigned int) val;
	return (ft_itoa_base_unsigned(uval, base));
}

char	*ft_itoa_base_unsigned(unsigned int val, const char *base)
{
	char	buffer[35];
	char	*str;
	size_t	base_len;

	if (val == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(base);
	str = buffer + (sizeof(buffer) - 1);
	*str = '\0';
	while (val > 0)
	{
		*--str = base[val % base_len];
		val /= base_len;
	}
	return (ft_strdup(str));
}

char	*ft_strtoa(char *str, t_flags flags)
{
	if (str == NULL)
	{
		if (flags.perc_zero == '.'
			&& flags.zeros_width < ((int) ft_strlen("(null)")))
			return (ft_strdup(""));
		return (ft_strdup("(null)"));
	}
	return (ft_strdup(str));
}

char	*ft_ctoa(char c)
{
	char	*s;

	s = malloc(2);
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

// #include <stdio.h>
// int main(void)
// {
// 	bool	sign = false;
// 	char	*s;
// 	// // BINARY 01
// 	// s = ft_itoa_base_signed(0, "01", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(1, "01", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(2, "01", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(10, "01", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(42, "01", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(255, "01", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(-1, "01", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(-42, "01", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	//HEX
// 	// s = ft_itoa_base_signed(0, "0123456789ABCDEF", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(10, "0123456789ABCDEF", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(15, "0123456789ABCDEF", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(16, "0123456789ABCDEF", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(31, "0123456789ABCDEF", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(255, "0123456789ABCDEF", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(-4095, "0123456789ABCDEF", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	// s = ft_itoa_base_signed(-255, "0123456789ABCDEF", &sign);
// 	// printf("%s\nsign: %i\n", s, sign);
// 	// free(s);
// 	//base 10
// 	s = ft_itoa_base_signed(0, "0123456789", &sign);
// 	printf("%s\nsign: %i\n", s, sign);
// 	free(s);
// 	s = ft_itoa_base_signed(10, "0123456789", &sign);
// 	printf("%s\nsign: %i\n", s, sign);
// 	free(s);
// 	s = ft_itoa_base_signed(15, "0123456789", &sign);
// 	printf("%s\nsign: %i\n", s, sign);
// 	free(s);
// 	s = ft_itoa_base_signed(16, "0123456789", &sign);
// 	printf("%s\nsign: %i\n", s, sign);
// 	free(s);
// 	s = ft_itoa_base_signed(31, "0123456789", &sign);
// 	printf("%s\nsign: %i\n", s, sign);
// 	free(s);
// 	s = ft_itoa_base_signed(255, "0123456789", &sign);
// 	printf("%s\nsign: %i\n", s, sign);
// 	free(s);
// 	s = ft_itoa_base_signed(-4095, "0123456789", &sign);
// 	printf("%s\nsign: %i\n", s, sign);
// 	free(s);
// 	s = ft_itoa_base_signed(-255, "0123456789", &sign);
// 	printf("%s\nsign: %i\n", s, sign);
// 	free(s);
// }