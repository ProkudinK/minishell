/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_programm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:28:39 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 19:43:04 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_which(t_parse *parse, char ***g_env)
{
	write(1, "\n", 1);
	if (!ft_strcmp(*parse->agv, "cd"))
		start_cd(parse, g_env);
	else if (!ft_strcmp(*parse->agv, "echo"))
		start_echo(parse);
	else if (!ft_strcmp(*parse->agv, "exit"))
		start_exit(parse);
	else if (!ft_strcmp(*parse->agv, "env"))
		start_env(parse, g_env);
	else if (!ft_strcmp(*parse->agv, "setenv"))
		start_setenv(parse, g_env);
	else if (!ft_strcmp(*parse->agv, "unsetenv"))
		start_unsetenv(parse, g_env);
	else
		return (1);
	return (0);
}

static	int		check_dir(char *str)
{
	struct stat		temp;

	if (!stat(str, &temp))
	{
		if (S_ISDIR(temp.st_mode))
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

static	void	sp_print_er(char *str, int len)
{
	if (!check_dir(str) && !access(str, 0))
	{
		write(2, "minishell: ", 11);
		write(2, str, len);
		write(2, ": is a directory\n", 17);
	}
	else if (!access(str, 0))
	{
		write(2, "minishell: ", 11);
		write(2, str, len);
		write(2, ": Permission denied\n", 20);
	}
	else
	{
		write(2, "minishell: command not found: ", 31);
		write(2, str, len);
		write(2, "\n", 1);
	}
}

static	void	start_programm_execve(char *path, t_parse *parse, char ***g_env)
{
	if (path)
		execve(path, (parse->agv), *g_env);
	else
		execve(*(parse->agv), (parse->agv), *g_env);
	free(path);
}

void			start_programm(t_parse *parse, char ***g_env)
{
	pid_t		pid;
	char		*path;

	path = NULL;
	pid = 0;
	if (sh_which(parse, g_env))
	{
		path = sh_find_prog(*parse->agv, ft_strlen(*parse->agv));
		if (path || (!access(*(parse->agv), 1) && check_dir(*(parse->agv))))
		{
			if ((pid = fork()) < 0)
				exit(-100);
			else if (pid == 0)
				start_programm_execve(path, parse, g_env);
			else
				wait(NULL);
		}
		else
			sp_print_er(*parse->agv, ft_strlen(*parse->agv));
		free(path);
	}
}
