/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:11:12 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/12 19:24:22 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	nb;
	size_t			i;
	int				minus;

	nb = 0;
	i = 0;
	minus = 1;
	while (ft_isspace((int)*(str + i)))
		i++;
	if (*(str + i) == '-')
		minus = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && ft_isdigit(*(str + i)))
	{
		if ((nb > 922337203685477580 || (nb == 922337203685477580
		&& (str[i] - '0') > 7)) && minus == 1)
			return (-1);
		else if ((nb > 922337203685477580 || (nb == 922337203685477580
		&& (str[i] - '0') > 8)) && minus == -1)
			return (0);
		nb = 10 * nb + (*(str + i++) - '0');
	}
	return ((int)(nb * minus));
}
