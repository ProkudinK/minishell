/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:00:03 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/02 16:46:32 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	lendst;

	i = 0;
	len = 0;
	lendst = 0;
	if (size == 0)
		return (lendst + ft_strlen(src));
	while (len < size && *(dst + len) != '\0')
		len++;
	lendst = len;
	while (*(src + i) && (len < size - 1))
		*(dst + len++) = *(src + i++);
	if (lendst < size)
		*(dst + len) = '\0';
	return (lendst + ft_strlen(src));
}
