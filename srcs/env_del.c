/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:29:40 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/16 19:17:16 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_del_split(int len, char ***g_env)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	if ((new_env = (char **)malloc(sizeof(char *) * (len))) == NULL)
		exit(-5);
	while (i <= (len - 1))
	{
		if (*(*g_env + i))
			(new_env[j++]) = *(*g_env + i);
		++i;
	}
	new_env[j] = NULL;
	free(*g_env);
	*g_env = new_env;
}

void	env_del(char *var, char ***g_env)
{
	char	**res;
	int		len;

	res = search_env(var, g_env);
	len = env_len(g_env);
	if (res)
	{
		free(*res);
		*res = NULL;
		env_del_split(len, g_env);
	}
}
