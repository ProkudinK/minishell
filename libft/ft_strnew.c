/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:29:04 by wtalea            #+#    #+#             */
/*   Updated: 2018/11/30 18:25:46 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	ch;

	ch = 0;
	if (size == ch - 1)
		return (NULL);
	if ((s = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	return (s);
}
