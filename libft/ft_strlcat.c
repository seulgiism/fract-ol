/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 13:16:07 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// 	The  strlcat()  function  ap‐
//  pends   the    NUL-terminated
//  string src to the end of dst.
//  It will append at most size -
//  strlen(dst)  -  1 bytes, NUL-
//  terminating the result. (from man page strlcat)
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	rem;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
	{
		dst_len++;
	}
	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (dst_len == size)
		return (src_len + dst_len);
	dst += dst_len;
	rem = size - dst_len - 1;
	while (rem-- > 0 && *src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
