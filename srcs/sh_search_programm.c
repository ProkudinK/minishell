/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_search_programm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:09:30 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/22 21:32:45 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*sh_find_prog(char *str, int len)
{
	int		i;
	t_tree	*temp;

	i = 0;
	temp = g_tree;
	while (str[i] && i <= len && temp)
	{
		if (str[i] == temp->symbol)
		{
			++i;
			if (i < len)
				temp = temp->down;
		}
		else if (temp->left)
			temp = temp->left;
		else
			return (NULL);
	}
	if (i == len && temp && temp->path)
		return (sh_str_path_split(temp->path, str));
	return (NULL);
}
