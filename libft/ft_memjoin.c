/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:50:02 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/20 18:05:51 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memjoin(void const *s1, void const *s2, int len1, int len2)
{
	char	*join;

	join = NULL;
	if (!s1 && !s2)
		return (NULL);
	if ((s1 && !s2) && (len1 && !len2))
	{
		if ((join = (char *)malloc(len1)) == NULL)
			return (NULL);
		ft_memcpy(join, s1, len1);
	}
	else if ((!s1 && s2) && len2 && !len1)
	{
		if ((join = (char *)malloc(len2)) == NULL)
			return (NULL);
		ft_memcpy(join, s2, len2);
	}
	else if (s1 && s2 && len1 && len2)
	{
		if ((join = ft_strnew(len1 + len2)) == NULL)
			return (NULL);
		ft_memcpy(join, s1, len1);
		ft_memcpy(join + len1, s2, len2);
	}
	return (join);
}
