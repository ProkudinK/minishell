/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:02:18 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/25 14:39:59 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				initialize_cmd(char *env, t_tree **tree)
{
	char			*pwd;
	int				i[2];
	char			envt[ARG_MAX];

	i[0] = 0;
	i[1] = 0;
	check_dot(&pwd, env, (char *)envt);
	while (pwd[i[0]] != '\0' && *envt != '\0')
	{
		if (pwd[i[0]] == ':')
		{
			pwd[i[0]] = '\0';
			open_dir(pwd, tree);
			ft_memdel((void **)&pwd);
			pwd = ft_strdup((envt + ++(i[1])));
			i[0] = 0;
		}
		else
		{
			++(i[1]);
			i[0]++;
		}
	}
	if (pwd)
		free(pwd);
}

void				initialize_env(char **env, char ***min_env, t_tree **tree)
{
	int				i;
	char			dir[PATH_MAX];

	i = 0;
	getcwd(dir, PATH_MAX);
	while (env[i])
		++i;
	(*min_env) = (char**)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (env[++i])
	{
		if (ft_strstr(env[i], "PATH="))
			initialize_cmd(&env[i][5], tree);
		(*min_env)[i] = ft_strdup(env[i]);
	}
	(*min_env)[i] = NULL;
}

char				*read_cmd(void)
{
	char		cmd[_POSIX_ARG_MAX + 1];
	int			i;

	i = read(0, &cmd, _POSIX_ARG_MAX);
	if (i > 1 && cmd[i - 1] == '\n')
		cmd[i - 1] = '\0';
	cmd[i] = '\0';
	return (ft_strdup(cmd));
}

int					search_cmd(char *cmd, t_tree **tree)
{
	if (!(*tree))
		return (-1);
	while ((*tree))
	{
		if (*cmd == (*tree)->symbol)
		{
			if ((*tree)->path != NULL && cmd[1] == '\0')
				return (1);
			return (search_cmd(&cmd[1], &(*tree)->down));
		}
		tree = &(*tree)->left;
	}
	return (-1);
}

void				implement_cmd(char *cmd, char **env, t_tree **tree)
{
	(*env) = NULL;
	if (search_cmd(cmd, tree) < 0)
		printf("not found\n");
	else
		printf("YRA\n");
}
