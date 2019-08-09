/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:00:08 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/12 18:35:21 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **lst)
{
	t_list	*i;
	t_list	*j;

	if (*lst && (*lst)->next)
		i = *lst;
	else
		return ;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (strcmp(i->content, j->content) > 0)
				ft_lstswap(&i, &j);
			j = j->next;
		}
		i = i->next;
	}
}
