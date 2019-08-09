/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:19:06 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/02 18:03:36 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i))
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j) && *(needle + j))
			j++;
		if (j == ft_strlen(needle) \
		&& *(haystack + i + j - 1) == *(needle + j - 1))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
