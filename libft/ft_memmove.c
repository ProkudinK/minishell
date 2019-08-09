/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:51:13 by wtalea            #+#    #+#             */
/*   Updated: 2018/11/30 14:48:15 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		while (len--)
			*((unsigned char *)dst + len) = \
			*((unsigned const char *)src + len);
	}
	else
	{
		while (i < len)
		{
			*((unsigned char *)dst + i) = \
			*((unsigned const char *)src + i);
			i++;
		}
	}
	return (dst);
}
