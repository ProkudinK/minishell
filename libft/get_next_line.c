/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 22:19:26 by sbecker           #+#    #+#             */
/*   Updated: 2019/01/11 19:48:29 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoinfree(char *s, char const *s1)
{
	char	*check;
	char	*a;
	size_t	i;

	i = 0;
	if (!s || !s1)
		return (0);
	check = s;
	a = (char*)malloc(ft_strlen(s) + ft_strlen(s1) + 1);
	if (a)
	{
		while (*s)
		{
			a[i++] = *s;
			s++;
		}
		while (*s1)
		{
			a[i++] = *s1;
			s1++;
		}
		a[i] = '\0';
	}
	free(check);
	return (a);
}

size_t			ft_whereisch(char *s, int c)
{
	int i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] == (char)c)
			return (++i);
	return (0);
}

static int		ft_new_line(void **str, char **line)
{
	size_t	i;
	char	*check;

	if (!(i = ft_whereisch(*str, '\n')))
		return (0);
	if ((*line = ft_strsub(*str, 0, --i)))
	{
		check = ft_strsub(*str, (unsigned int)i + 1, ft_strlen(*str) - (i + 1));
		ft_memdel(str);
		*str = check;
		return (1);
	}
	return (-1);
}

static t_list	*find_fd(t_list **f_elem, int fd)
{
	t_list	*tmp;

	if (*f_elem)
	{
		tmp = *f_elem;
		while (tmp)
		{
			if ((int)tmp->content_size == fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = (t_list*)malloc(sizeof(*tmp));
	tmp->content = ft_memalloc(sizeof(char*));
	tmp->content_size = fd;
	if (*f_elem)
		tmp->next = *f_elem;
	else
		tmp->next = 0;
	*f_elem = tmp;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*first_elem;
	t_list			*list;
	int				exit;
	size_t			read_size;

	if (BUFF_SIZE <= 0 || fd < 0 || !line || read(fd, buf, 0) <= -1)
		return (-1);
	list = find_fd(&first_elem, fd);
	while (1)
		if ((exit = ft_new_line(&list->content, line)))
			return (exit == 1 ? 1 : -1);
		else if ((read_size = read(fd, buf, BUFF_SIZE)))
		{
			buf[read_size] = '\0';
			list->content = ft_strjoinfree((char*)list->content, buf);
		}
		else if (list->content && *(char*)list->content)
		{
			*line = ft_strdup((char*)list->content);
			ft_memdel(&list->content);
			return (1);
		}
		else
			return ((*line = ft_strdup("")) ? 0 : -1);
}
