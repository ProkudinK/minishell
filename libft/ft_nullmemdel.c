/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullmemdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:21:39 by wtalea            #+#    #+#             */
/*   Updated: 2019/01/15 21:59:53 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_nullmemdel(void ***mas, int i)
{
	while (i)
	{
		ft_memdel(((*mas) + i));
		i--;
	}
	free(*mas);
	*mas = NULL;
	return (NULL);
}
