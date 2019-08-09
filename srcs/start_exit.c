/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:27:04 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/11 15:12:05 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_exit(t_parse *parse)
{
	if (parse->agc == 1)
	{
		write(1, "exit\n", 5);
		exit(0);
	}
	else
	{
		write(1, "minishell: exit: ", 17);
		write(1, *(parse->agv + 1), ft_strlen(*(parse->agv + 1)));
		write(1, ": numeric argument required\n", 28);
	}
}
