/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:07:18 by wtalea            #+#    #+#             */
/*   Updated: 2018/11/30 15:50:06 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*cp;

	i = 0;
	if ((cp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	ft_strcpy(cp, s);
	while (*(cp + i))
	{
		*(cp + i) = (*f)(*(cp + i));
		i++;
	}
	return (cp);
}
