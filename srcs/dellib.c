/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dellib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:46:32 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 16:44:02 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_double_memdel(char ***dstr)
{
	int		i;

	i = 0;
	while (*(*dstr + i))
		free(*(*dstr + i++));
	free(*dstr);
}

void	del_tree(t_tree **tree)
{
	if (*tree)
	{
		if ((*tree)->left)
			del_tree(&(*tree)->left);
		if ((*tree)->down)
			del_tree(&(*tree)->down);
		if ((*tree)->path)
			ft_memdel((void **)&(*tree)->path);
		if (*tree)
		{
			free(*tree);
			*tree = NULL;
		}
	}
}

void	sh_lstdel(t_parse **alst)
{
	t_parse	*buff;

	if (alst != NULL && *alst != NULL)
	{
		while ((*alst))
		{
			buff = *alst;
			*alst = (*alst)->next;
			free(buff);
			buff = NULL;
		}
		free(*alst);
		*alst = NULL;
	}
}
