/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:24:43 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/05 19:07:07 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_ftitoa(int len, int i, int n, char *nb)
{
	while (len > i)
	{
		*(nb + len--) = ft_abs((n % 10)) + '0';
		n /= 10;
	}
	return (nb);
}

char			*ft_itoa(int n)
{
	char	*nb;
	int		i;
	int		len;
	int		ncp;

	if (n == 0)
		return (ft_strdup("0"));
	i = -1;
	len = 0;
	ncp = n;
	while (ncp != 0)
	{
		len++;
		ncp /= 10;
	}
	n < 0 ? len++ : (1);
	if ((nb = ft_strnew(len)) == NULL)
		return (NULL);
	if (n < 0)
		*(nb + ++i) = '-';
	len--;
	nb = ft_ftitoa(len, i, n, nb);
	return (nb);
}
