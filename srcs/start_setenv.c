/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:32:16 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 15:14:12 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_setenv(t_parse *parse, char ***g_env)
{
	char		**new_env;

	new_env = NULL;
	if (parse->agc > 3)
		write(1, "setenv: Too many arguments.\n", 28);
	else if (parse->agc == 2)
		add_env(*(parse->agv + 1), "", g_env);
	else if (parse->agc == 1)
		write(1, "setenv: Too few arguments.\n", 27);
	else
	{
		add_env(*(parse->agv + 1), *(parse->agv + 2), g_env);
		if (!ft_strcmp(*(parse->agv + 1), "PATH") &&
				(sh_equal_len(*(parse->agv + 1)) == 4))
		{
			del_tree(&g_tree);
			initialize_env(*g_env, &new_env, &g_tree);
			del_double_memdel(g_env);
			*g_env = new_env;
		}
	}
}
