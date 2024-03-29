/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:29:10 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/12 18:32:14 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
