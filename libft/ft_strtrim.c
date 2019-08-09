/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:37:40 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/04 20:28:50 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cp;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (ft_istab(*(s + i)))
		i++;
	len = ft_strlen(s) - 1;
	while (ft_istab(*(s + len)) && len > i)
		len--;
	if (len <= i)
	{
		if ((cp = ft_memalloc(1)) == NULL)
			return (NULL);
		return (cp);
	}
	if ((cp = ft_strsub(s, i, (len - i + 1))) == NULL)
		return (NULL);
	return (cp);
}
