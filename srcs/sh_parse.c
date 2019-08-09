/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:52:39 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/20 19:41:23 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				size_argv(char *str)
{
	int			i;

	i = 0;
	while (*str)
	{
		while (ft_isspace(*str) && *str)
			++str;
		if (*str)
		{
			while (!ft_isspace(*str) && *str)
				++str;
			++i;
		}
	}
	return (i);
}

void			have_agv(char *str, t_parse *parse)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*str)
	{
		i = 0;
		while (ft_isspace(*str) && *str)
			++str;
		if (*str)
		{
			while ((!ft_isspace(*(str + i))) && *(str + i))
				++i;
			if ((*(parse->agv + j) = malloc(i + 1)) == NULL)
				exit(-5);
			ft_memcpy(*((parse->agv) + j), str, i);
			*(*((parse->agv) + j++) + i) = '\0';
			str += i;
		}
	}
}

void			create_parse(char **str, t_parse **parse)
{
	int		i;
	t_parse	*temp;

	i = 0;
	temp = NULL;
	while (*(str + i++))
	{
		if ((temp = malloc(sizeof(t_parse))) == NULL)
			exit(-5);
		temp->agv = NULL;
		temp->agc = 0;
		temp->next = NULL;
		if (*parse)
			temp->next = *parse;
		(*parse) = temp;
	}
}

static	void	parse_dop(char ***prog, int *i, t_parse **parse)
{
	if (((*parse)->agv = (char **)malloc(sizeof(char *)
					* ((*parse)->agc + 1))) == NULL)
		exit(-5);
	have_agv(*(*prog + (*i)++), *parse);
	*((*parse)->agv + (*parse)->agc) = NULL;
	*parse = (*parse)->next;
}

void			start_parse(char *str, t_parse **parse)
{
	char		**prog;
	int			i;
	t_parse		*cp;

	cp = NULL;
	prog = NULL;
	i = 0;
	if ((prog = ft_strsplit(str, ';')) == NULL)
		exit(-5);
	create_parse(prog, parse);
	cp = *parse;
	while (*(prog + i))
	{
		(*parse)->agc = size_argv(*(prog + i));
		if ((*parse)->agc == 0)
		{
			++i;
			continue;
		}
		parse_dop(&prog, &i, parse);
	}
	*parse = cp;
	del_double_memdel(&prog);
}
