/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:54:03 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 16:45:30 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	del_dub_quotes(char **temp, t_parse **cp, int *i)
{
	if (!(ft_strlen(*((*cp)->agv + *i)) - 2))
		*temp = ft_strnew(1);
	else
	{
		*temp = ft_memdup((*((*cp)->agv + *i) + 1),
				(ft_strlen(*((*cp)->agv + *i)) - 1));
		*(*temp + ft_strlen((*((*cp)->agv + *i))) - 2) = '\0';
	}
	if (!*temp)
		exit(-5);
	free(*((*cp)->agv + *i));
	*((*cp)->agv + *i) = *temp;
}

void			del_quotes(t_parse **parse)
{
	t_parse		*cp;
	int			i;
	char		*temp;

	temp = NULL;
	cp = *&*parse;
	i = 0;
	if (cp->agv)
		while (cp)
		{
			i = 1;
			while (*(cp->agv + i))
			{
				if (**(cp->agv + i) == '\"' || **(cp->agv + i) == '\'')
					if (*(*(cp->agv + i) +
								(ft_strlen(*(cp->agv + i)) - 1)) == '\"')
						del_dub_quotes(&temp, &cp, &i);
				++i;
			}
			cp = cp->next;
		}
}
