/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:32:58 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 13:14:24 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

//    If little is an empty string,
//    big is  returned;  if  little
//    occurs  nowhere  in big, NULL
//    is  returned;   otherwise   a
//    pointer  to the first charac‐
//    ter of the  first  occurrence
//    of little is returned.		(from man page strnstr)
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;

	if (*little == '\0')
		return ((char *) big);
	while (*big && len > 0)
	{
		i = 0;
		while (i < len && big[i] == little[i] && little[i])
		{
			i++;
		}
		if (little[i] == '\0')
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
