/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:41:16 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/14 16:53:46 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memtostr(void **mem, size_t len)
{
	char	*tmp;

	if ((tmp = ft_strnew(len)) == NULL)
		return (NULL);
	tmp = ft_memcpy(tmp, *mem, len);
	free(*mem);
	*mem = tmp;
	return (*mem);
}
