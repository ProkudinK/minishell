/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:20:16 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 15:13:59 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_unsetenv(t_parse *parse, char ***g_env)
{
	int		i;
	char	**new_env;

	new_env = NULL;
	i = 1;
	if (parse->agc > 1)
	{
		while (*(parse->agv + i))
		{
			env_del(*(parse->agv + i), g_env);
			if (!ft_strcmp(*(parse->agv + i++), "PATH") &&
					(sh_equal_len(*(parse->agv + 1)) == 4))
			{
				del_tree(&g_tree);
				initialize_env(*g_env, &new_env, &g_tree);
				del_double_memdel(g_env);
				*g_env = new_env;
			}
		}
	}
	else
		write(1, "unsetenv: Too few arguments.\n", 29);
}
