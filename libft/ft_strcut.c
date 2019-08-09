/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:39:12 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/26 19:00:21 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(char **str, int c)
{
	size_t		len;
	size_t		j;
	size_t		i;
	char		*tmp;
	char		*cp;

	if (!str || !c)
		return (NULL);
	len = ft_strlen(*str);
	i = 0;
	j = 0;
	while (*(*str + j) != (char)c && j < len)
		j++;
	if ((tmp = ft_strndup(*str, j)) == NULL)
		return (NULL);
	if ((*(*str + j)) == (char)c)
		j++;
	len = ft_strlen((*str + j));
	if ((cp = ft_strnew(len)) == NULL)
		return (NULL);
	while (i < len)
		*(cp + i++) = *(*(char **)str + j++);
	free(*str);
	*str = cp;
	return (tmp);
}
