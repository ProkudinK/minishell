/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:12:20 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/02 17:15:32 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	while (*(s + i))
	{
		if ((char)c == *(s + i))
			p = ((char *)(s + i));
		i++;
	}
	if ((char)c == *(s + i))
		return ((char *)(s + i));
	return (p);
}
