/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:26:40 by wtalea            #+#    #+#             */
/*   Updated: 2019/05/03 17:57:31 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*search_strtok(char *str, const char *delim, char **old)
{
	char	*end;

	if (str == NULL)
		str = *old;
	if (*str == '\0')
	{
		str = *old;
		return (NULL);
	}
	str += strspn(str, delim);
	if (*str == '\0')
	{
		*old = str;
		return (NULL);
	}
	end = str + ft_strcspn(str, delim);
	if (*end == '\0')
	{
		*old = end;
		return (str);
	}
	*end = '\0';
	*old = end + 1;
	return (str);
}

char			*ft_strtok(char *str, const char *sep)
{
	static char *old;

	return (search_strtok(str, sep, &old));
}
