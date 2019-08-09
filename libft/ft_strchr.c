/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:53:31 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/02 17:10:01 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*(s + i))
	{
		if ((char)c == *(s + i))
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == *(s + i))
		return ((char *)(s + i));
	return (NULL);
}
