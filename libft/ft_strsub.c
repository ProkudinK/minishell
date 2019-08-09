/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:58:03 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/04 18:06:14 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		return (NULL);
	i = 0;
	if ((sub = ft_strnew(len)) == NULL)
		return (NULL);
	while ((*(s + start)) && i < len)
		*(sub + i++) = *(s + start++);
	return (sub);
}
