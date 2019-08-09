/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:53:51 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/17 14:25:09 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char		*p;
	size_t		i;

	i = 0;
	if ((p = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	if (size == 0)
		return (p);
	while (i < size)
		p[i++] = '\0';
	return (p);
}
