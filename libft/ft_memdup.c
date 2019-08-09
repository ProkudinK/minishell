/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:00:48 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/13 18:03:27 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memdup(const char *s, int len)
{
	char		*cp;

	if ((cp = malloc(len)) == NULL)
		return (0);
	ft_memcpy(cp, s, len);
	return (cp);
}
