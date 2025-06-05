/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 13:14:06 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//    The  strchr()  and  strrchr()
//    functions return a pointer to
//    the matched character or NULL
//    if  the  character   is   not
//    found.   The terminating null
//    byte is  considered  part  of
//    the  string,  so that if c is
//    specified  as   '\0',   these
//    functions return a pointer to
//    the terminator.				(from man page strrchr)
char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*last_ptr;
	const unsigned char	*us;
	unsigned char		uc;

	us = (const unsigned char *) s;
	uc = (unsigned char) c;
	last_ptr = NULL;
	while (*us)
	{
		if (*us == uc)
			last_ptr = us;
		us++;
	}
	if (uc == '\0')
		return ((char *) us);
	return ((char *) last_ptr);
}
