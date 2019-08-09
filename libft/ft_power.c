/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:45:15 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/12 18:49:27 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int	cp;

	if (power == 0)
		return (1);
	cp = power;
	while (power > 1)
	{
		nb = nb * cp;
		power--;
	}
	return (nb);
}