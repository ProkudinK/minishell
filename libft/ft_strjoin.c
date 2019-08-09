/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:10:54 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/28 19:00:52 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	join = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
	{
		if ((join = ft_strnew(ft_strlen(s1))) == NULL)
			return (NULL);
		ft_strcpy(join, s1);
	}
	else if (!s1 && s2)
	{
		if ((join = ft_strnew(ft_strlen(s2))) == NULL)
			return (NULL);
		ft_strcpy(join, s2);
	}
	else if (s1 && s2)
	{
		if ((join = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))) == NULL)
			return (NULL);
		ft_strcpy(join, s1);
		ft_strcat(join, s2);
	}
	return (join);
}
