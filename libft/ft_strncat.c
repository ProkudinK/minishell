/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:01:49 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/07 12:29:21 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	if (n != 0)
	{
		i = 0;
		len = 0;
		len = ft_strlen(s1);
		while (*(s2 + i) && i < n)
		{
			*(s1 + len) = *(s2 + i);
			i++;
			len++;
		}
		*(s1 + len) = '\0';
	}
	return (s1);
}
