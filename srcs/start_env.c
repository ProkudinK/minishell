/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:16:36 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/18 19:39:16 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_env(t_parse *parse, char ***g_env)
{
	int		i;

	i = 0;
	if (parse)
		;
	while (*(*g_env + i))
	{
		write(1, *(*g_env + i), ft_strlen(*(*g_env + i)));
		write(1, "\n", 1);
		++i;
	}
}
