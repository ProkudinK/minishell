/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:56:01 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/20 19:33:35 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			sh_is_uni_back(char *c)
{
	int		i;

	i = 1;
	if (((*c >> 7) & 1) == 1)
	{
		while (!((*c >> 6) & 1))
		{
			--c;
			++i;
		}
	}
	return (i);
}

int			sh_spos(char *ch, int pos)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i != pos)
	{
		len += sh_is_unicode(*(ch + len));
		++i;
	}
	return (len);
}

void		sh_rewrite_del(int size, int pos, int len, char *ch)
{
	int		i;

	i = 0;
	while (i++ < pos + 1)
		write(1, "\b", 1);
	i = 0;
	while (i++ < len + 1)
		write(1, " ", 1);
	i = 0;
	while (i++ < len + 1)
		write(1, "\b", 1);
	i = 0;
	write(1, ch, size);
	while (i++ < (len - pos))
		write(1, "\b", 1);
}

void		sh_back(char **c, t_sh_int *lens)
{
	char		*cp;
	int			sizepos;

	if (lens->pos > 0)
	{
		sizepos = sh_spos(*c, lens->pos);
		if ((cp = ft_strnew((lens->size -
							sh_is_uni_back(*c + (sizepos - 1))))) == NULL)
			exit(1);
		ft_memcpy(cp, *c, (sizepos - sh_is_uni_back((*c + (sizepos - 1)))));
		ft_memcpy((cp + (sizepos - sh_is_uni_back(*c + (sizepos - 1)))),
				(*c + sizepos), (lens->size - sizepos));
		lens->size -= sh_is_uni_back(*c + (sizepos - 1));
		--lens->pos;
		--lens->len;
		free(*c);
		*c = cp;
		sh_rewrite_del(lens->size, lens->pos, lens->len, *c);
	}
}

void		sh_check_enter(char *c, char ***g_env)
{
	t_parse		*parse;
	t_parse		*cp;

	cp = NULL;
	parse = NULL;
	start_parse(c, &parse);
	if (parse && parse->agv)
	{
		start_lexer(&parse, g_env);
		if (cp)
			;
		cp = *&parse;
		while ((cp))
		{
			start_programm(cp, g_env);
			cp = cp->next;
		}
		if (parse->agv)
			del_double_memdel(&parse->agv);
		sh_lstdel(&parse);
	}
	else
		write(1, "\n", 1);
}
