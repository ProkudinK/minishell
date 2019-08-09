/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:13:18 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/06 17:21:44 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buff;

	if (alst != NULL && *alst != NULL)
	{
		while ((*alst))
		{
			buff = *alst;
			*alst = (*alst)->next;
			ft_lstdelone(&buff, del);
		}
		ft_lstdelone(alst, del);
	}
}
