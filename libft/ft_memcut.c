/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:14:18 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/15 20:17:19 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcut(char **str, int c, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (*((unsigned char *)*str + j) != (unsigned char)c && j < len)
		j++;
	if ((*((unsigned char *)*str + j)) == (char)c)
		j++;
	while (j < len)
	{
		*((unsigned char *)*str + i++) = *(*(unsigned char **)str + j);
		*((unsigned char *)*str + j++) = '\0';
	}
	return (i);
}
