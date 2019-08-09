/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:21:24 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/07 18:03:30 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*sc;
	unsigned char		*ds;
	size_t				i;

	if (dst == src)
		return (dst);
	i = 0;
	ds = dst;
	sc = src;
	while (i < n)
	{
		*(ds + i) = *(sc + i);
		i++;
	}
	return (dst);
}
