/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:08:42 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/11 15:55:25 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_lst_new(t_list **flst, t_list **buff, t_list **tmp)
{
	*flst = *tmp;
	*buff = *tmp;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flst;
	t_list	*buff;
	t_list	*tmp;

	flst = NULL;
	if (lst)
	{
		while (lst)
		{
			if ((tmp = ((*f)(lst))) == NULL)
			{
				ft_lstdel(&flst, &ft_ftlstdel);
				return (NULL);
			}
			if (flst == NULL)
				ft_lst_new(&flst, &buff, &tmp);
			else
			{
				buff->next = tmp;
				buff = buff->next;
			}
			lst = lst->next;
		}
	}
	return (flst);
}
