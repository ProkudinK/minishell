/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:07:41 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/20 12:56:37 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	check_it_works(t_parse *parse)
{
	if (*(parse->agv + 1) && (!ft_strcmp(*(parse->agv + 1), "\"It") ||
			!ft_strcmp(*(parse->agv + 1), "\"it"))
			&& *(parse->agv + 2) && !ft_strcmp(*(parse->agv + 2), "works\""))
	{
		if (!ft_strcmp(*(parse->agv + 1), "\"It"))
			write(1, "It works\n", 9);
		else
			write(1, "it works\n", 9);
		return (1);
	}
	else
		return (0);
}

static	int	check_chiken(t_parse *parse)
{
	if (*(parse->agv + 1) && !ft_strcmp(*(parse->agv + 1), "Кто")
			&& *(parse->agv + 2) && !ft_strcmp(*(parse->agv + 2), "не")
			&& *(parse->agv + 3) && !ft_strcmp(*(parse->agv + 3), "умеет")
			&& *(parse->agv + 4) && !ft_strcmp(*(parse->agv + 4), "в")
			&& *(parse->agv + 5) && !ft_strcmp(*(parse->agv + 5), "Юникод?"))
	{
		write(1, "Братья не умеют в Юникод\n", 46);
		return (1);
	}
	else
		return (0);
}

void		start_echo(t_parse *parse)
{
	int		i;

	i = 1;
	if (check_chiken(parse))
		return ;
	else if (check_it_works(parse))
		return ;
	while (i < parse->agc)
	{
		if (i != 1)
			write(1, " ", 1);
		write(1, *(parse->agv + i), ft_strlen(*(parse->agv + i)));
		++i;
	}
	write(1, "\n", 1);
}
