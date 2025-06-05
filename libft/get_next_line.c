/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:36:52 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/16 18:56:26 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char		*ft_stash_init(t_stash *stash);
char		*ft_stash_append(t_stash *stash, const char *buff);
char		*ft_buff_read(char *buff, int fd);
char		*ft_clean_exit(t_stash *stash);
char		*ft_stash_get_line(t_stash *stash);
int			ft_needs_fill(t_stash *t_stash);
char		*ft_stash_fill(int fd, t_stash *stash);

char	*get_next_line(int fd)
{
	static t_stash	stash_arr[OPEN_MAX] = {0};
	char			*ret_line;

	if (BUFF_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!ft_stash_init(&stash_arr[fd]))
		return (NULL);
	if (&stash_arr[fd].stash == &stash_arr[fd].stash_strt_ptr
		|| ft_needs_fill(&stash_arr[fd]))
	{
		if (!ft_stash_fill(fd, &stash_arr[fd]))
			return (ft_clean_exit(&stash_arr[fd]));
	}
	ret_line = ft_stash_get_line(&stash_arr[fd]);
	return (ret_line);
}

char	*ft_stash_fill(int fd, t_stash *stash)
{
	char	*buff;

	buff = malloc(BUFF_SIZE + 1);
	if (!buff)
		return (ft_clean_exit(stash));
	while (ft_needs_fill(stash))
	{
		if (!ft_buff_read(buff, fd))
			break ;
		if (buff[0] == '\0')
			break ;
		if (!ft_stash_append(stash, buff))
			return (free(buff), NULL);
	}
	free(buff);
	return (stash->stash);
}

char	*ft_buff_read(char *buff, int fd)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buff, BUFF_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buff[bytes_read] = '\0';
	return (buff);
}

int	ft_needs_fill(t_stash *t_stash)
{
	size_t	i;

	i = 0;
	while (t_stash->stash[i] != '\n' && t_stash->stash[i] != '\0')
		i++;
	if (t_stash->stash[i] == '\0')
		return (1);
	return (0);
}

char	*ft_stash_get_line(t_stash *stash)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while (stash->stash[len] != '\n' && stash->stash[len] != '\0')
		len++;
	if (stash->stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		ft_clean_exit(stash);
	i = 0;
	while (i < len)
	{
		line[i] = stash->stash[i];
		i++;
	}
	line[i] = '\0';
	if (line[0] == '\0')
		return (free(line), ft_clean_exit(stash));
	else
		stash->stash += i;
	return (line);
}
