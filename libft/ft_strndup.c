/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:20:10 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/15 20:21:56 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char			*cp;

	if ((cp = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strncpy(cp, s1, len);
	return (cp);
}
