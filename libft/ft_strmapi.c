/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:30:09 by wtalea            #+#    #+#             */
/*   Updated: 2018/11/30 15:50:21 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cp;

	i = 0;
	if ((cp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	ft_strcpy(cp, s);
	while (*(cp + i))
	{
		*(cp + i) = (*f)(i, *(cp + i));
		i++;
	}
	return (cp);
}
