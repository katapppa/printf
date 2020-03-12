/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 01:24:23 by fallard           #+#    #+#             */
/*   Updated: 2019/11/28 16:04:26 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		copy_line(char **line, char **hist)
{
	int		i;
	char	*tmp;
	char	*n;

	i = 0;
	tmp = *hist;
	if ((n = ft_strchr(tmp, '\n')))
	{
		while (tmp[i] != '\n')
			i++;
		*line = ft_strsub(tmp, 0, i);
		*hist = ft_strdup(n + 1);
		free(tmp);
		tmp = NULL;
	}
	else
	{
		*line = ft_strdup(*hist);
		ft_strclr(*hist);
	}
	return (1);
}

int		get_line(const int fd, char **line, char **hist)
{
	char	*tmp;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!*hist)
			*hist = ft_strnew(1);
		tmp = *hist;
		*hist = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (*hist == NULL || *hist[0] == '\0'))
		return (0);
	return (copy_line(line, hist));
}

t_gnl	*new_list(int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->content = NULL;
	new->next = NULL;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*hist;
	t_gnl			*tmp;
	char			*buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || (read(fd, buf, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	if (!hist)
		hist = new_list(fd);
	tmp = hist;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->content));
}
