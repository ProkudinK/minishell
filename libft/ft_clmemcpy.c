/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clmemcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:21:24 by wtalea            #+#    #+#             */
/*   Updated: 2019/06/26 19:04:44 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_clmemcpy(void *dst, const void *src, long long n)
{
	if (dst == src)
		return (dst);
	while ((n = n - 8) >= 0)
	{
		*((long *)dst) = *((long *)src);
		dst += 8;
		src += 8;
	}
	while ((n = n - 1) >= 0)
	{
		*((char *)dst++) = *((char *)src++);
	}
	return (dst);
}
