/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:05:17 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/22 17:45:37 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_len(char ***g_env)
{
	int		i;
	char	*c;

	i = 0;
	c = NULL;
	while (*(*g_env + i))
		++i;
	return (i);
}

void	cp_env(char **new_env, char ***g_env)
{
	int		i;

	i = 0;
	while (*(*g_env + i))
	{
		(new_env[i]) = *(*g_env + i);
		++i;
	}
}

void	add_env_new(char *var, char *con, int lens[2], char ***g_env)
{
	int		env_l;
	char	**new_env;
	char	*res;

	env_l = env_len(g_env);
	if ((new_env = (char **)malloc(sizeof(char *) * (env_l + 2))) == NULL)
		exit(-5);
	if ((res = (char *)malloc(lens[0] + lens[1] + 2)) == NULL)
		exit(-5);
	ft_memcpy(res, var, lens[0]);
	*(res + lens[0]) = '=';
	ft_memcpy(res + lens[0] + 1, con, lens[1]);
	*(res + lens[1] + lens[0] + 1) = '\0';
	(new_env[env_l]) = res;
	(new_env[env_l + 1]) = NULL;
	cp_env(new_env, g_env);
	free(*g_env);
	*g_env = new_env;
}

char	**search_env(char *var, char ***g_env)
{
	int		i;
	char	*str;
	int		len;

	str = NULL;
	len = 0;
	i = 0;
	while (*(*g_env + i))
	{
		len = ft_strchr(*(*g_env + i), '=') - *(*g_env + i);
		if (!ft_memcmp(var, *(*g_env + i), len))
			return ((*g_env + i));
		++i;
	}
	return (NULL);
}

void	add_env(char *var, char *con, char ***g_env)
{
	char	**res;
	int		lens[2];

	lens[0] = ft_strlen(var);
	lens[1] = ft_strlen(con);
	res = search_env(var, g_env);
	if (res)
	{
		free(*res);
		if ((*res = (char *)malloc(lens[0] + lens[1] + 2)) == NULL)
			exit(-5);
		ft_memcpy(*res, var, lens[0]);
		*(*res + lens[0]) = '=';
		ft_memcpy((*res + lens[0] + 1), con, lens[1]);
		*(*res + lens[0] + lens[1] + 1) = '\0';
	}
	else
		add_env_new(var, con, lens, g_env);
}
