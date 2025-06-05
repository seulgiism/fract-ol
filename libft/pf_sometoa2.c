/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_sometoa2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:40:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/18 00:40:25 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "printf_helpers.h"
#include <stdlib.h>
#include <stdint.h>

static char	*ft_itoa_base_uintptr(uintptr_t val, const char *base);

char	*ft_ptoa(void *p)
{
	char	*str;
	char	*str_0x;

	if (p == NULL)
	{
		str = ft_strdup("(nil)");
		if (!str)
			return (NULL);
		return (str);
	}
	str = ft_itoa_base_uintptr((uintptr_t) p, "0123456789abcdef");
	if (!str)
		return (NULL);
	str_0x = ft_strjoin("0x", str);
	free(str);
	if (!str_0x)
		return (NULL);
	return (str_0x);
}

static char	*ft_itoa_base_uintptr(uintptr_t val, const char *base)
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
