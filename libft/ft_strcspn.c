/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:39:57 by wtalea            #+#    #+#             */
/*   Updated: 2019/05/03 17:51:51 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str1, const char *str2)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (*str1)
	{
		j = 0;
		while (*(str2 + j))
			if (*(str1) != *(str2 + j++))
				continue ;
			else
				return (i);
		++i;
		++str1;
	}
	return (i);
}
