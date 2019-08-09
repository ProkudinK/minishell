/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:00:44 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/06 14:56:50 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) && *(s2 + i) && i < n)
		i++;
	if (i == n)
		return ((unsigned char)*(s1 + i - 1) - (unsigned char)*(s2 + i - 1));
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
