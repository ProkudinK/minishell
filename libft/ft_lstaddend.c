/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:53:57 by wtalea            #+#    #+#             */
/*   Updated: 2019/02/08 17:06:13 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *lnew)
{
	t_list *tmp;

	if (alst && *alst && lnew)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = lnew;
	}
}
