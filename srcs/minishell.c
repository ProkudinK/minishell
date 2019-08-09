/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:52:43 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 16:49:58 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void		null_tree(t_tree **tree, char **cmd)
{
	if (((*tree) = (t_tree*)malloc(sizeof(t_tree))) == NULL)
		exit(-5);
	(*tree)->symbol = (*cmd)[0];
	(*tree)->left = NULL;
	(*tree)->down = NULL;
	(*tree)->path = NULL;
}

static	void		fill_tree_help(char *cmd, char *path, t_tree **tree)
{
	fill_tree(&cmd[1], path, &(*tree)->down);
	if (cmd[1] == '\0')
		if (!(*tree)->path && *path)
			(*tree)->path = ft_strdup(path);
}

void				fill_tree(char *cmd, char *path, t_tree **tree)
{
	if (*cmd == '\0')
		return ;
	while ((*tree))
	{
		if (*cmd == (*tree)->symbol)
		{
			fill_tree_help(cmd, path, tree);
			return ;
		}
		tree = &(*tree)->left;
	}
	if ((*tree) == NULL)
	{
		null_tree(tree, &cmd);
		if (cmd[1] == '\0')
		{
			if (!(*tree)->path && *path)
				(*tree)->path = ft_strdup(path);
			return ;
		}
		tree = &(*tree)->down;
		fill_tree(&cmd[1], path, tree);
	}
}

void				open_dir(char *path, t_tree **tree)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*str;

	dir = opendir(path);
	if (dir)
	{
		while ((entry = readdir(dir)))
		{
			if (entry->d_name[0] == '.')
				if (!entry->d_name[1] || (entry->d_name[1] == '.' &&
							!entry->d_name[2]))
					continue ;
			str = ft_strjoin(path, "/");
			str = ft_strrejoin(str, entry->d_name);
			if (!access(str, 1))
				fill_tree(entry->d_name, path, tree);
			free(str);
		}
		closedir(dir);
	}
}

int					main(int ac, char **av, char **env)
{
	t_tree		*tree;
	char		**new_env;
	char		*cmd;
	char		**g_env;

	if (ac == 0)
		*av = NULL;
	tree = NULL;
	cmd = NULL;
	g_env = NULL;
	g_tree = NULL;
	initialize_env(env, &new_env, &tree);
	g_env = new_env;
	g_tree = tree;
	signal(SIGINT, sh_signal);
	start_shell(&cmd, &g_env);
	if (!cmd)
		free(cmd);
	del_double_memdel(&g_env);
	del_tree(&tree);
	return (0);
}
