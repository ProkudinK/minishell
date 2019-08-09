/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:58:19 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 17:01:01 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*cd_get_pwd(char *pwd)
{
	if ((getcwd(pwd, PATH_MAX)) == NULL)
		exit(-1000);
	return (pwd);
}

static void		cd_chdir(char *res, char ***g_env)
{
	char		pwdd[PATH_MAX];
	char		*temp;

	if ((chdir(res)) == -1)
	{
		write(1, "cd: no such file or directory: ", 31);
		write(1, res, ft_strlen(res));
		write(1, "\n", 1);
	}
	else
	{
		temp = search_bucks("PWD", g_env);
		add_env("OLDPWD", temp, g_env);
		free(temp);
		add_env("PWD", cd_get_pwd(pwdd), g_env);
	}
}

static	void	sh_cd_print_error(char *str)
{
	write(2, "cd: string not in pwd: ", 23);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void			start_cd(t_parse *parse, char ***g_env)
{
	char		*res;

	res = NULL;
	if (parse->agc < 3)
	{
		if (parse->agc == 1)
		{
			res = search_bucks("HOME", g_env);
			cd_chdir(res, g_env);
			free(res);
		}
		else
		{
			if (!ft_strcmp(*(parse->agv + 1), "-"))
			{
				res = search_bucks("OLDPWD", g_env);
				cd_chdir(res, g_env);
				free(res);
			}
			else
				cd_chdir(*(parse->agv + 1), g_env);
		}
	}
	else
		sh_cd_print_error(*(parse->agv + 1));
}
