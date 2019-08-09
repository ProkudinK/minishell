/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:24:30 by wtalea            #+#    #+#             */
/*   Updated: 2018/11/30 16:41:18 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*cp;

	if ((cp = ft_strnew(ft_strlen(s1))) == NULL)
		return (NULL);
	ft_strcpy(cp, s1);
	return (cp);
}
