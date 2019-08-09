/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:41:52 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 15:46:07 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	void	sh_auto_auto(char **ch, t_sh_int *lens, char *st, char *dop)
{
	int		len_dop;
	char	*cp;

	cp = NULL;
	len_dop = ft_strlen(dop);
	if (!ft_memcmp(*ch, st, lens->size) && lens->pos == lens->size)
	{
		free(*ch);
		if (!(*ch = ft_memjoin(st, dop, lens->size, len_dop)))
			exit(-5);
		write(1, dop, len_dop);
		lens->pos += len_dop;
		lens->size += len_dop;
		lens->len += len_dop;
	}
}

static	void	sh_pipe_auto(char **ch, t_sh_int *lens, char *str1, char *str2)
{
	if (!ft_memcmp(*ch, str1, lens->size) && lens->size == (int)ft_strlen(str1))
		sh_auto_auto(ch, lens, str1, str2);
}

void			sh_print_auto(char **ch, t_sh_int *lens)
{
	sh_pipe_auto(ch, lens, "ec", "ho ");
	sh_pipe_auto(ch, lens, "ech", "o ");
	sh_pipe_auto(ch, lens, "ema", "cs ");
	sh_pipe_auto(ch, lens, "emac", "s ");
	sh_pipe_auto(ch, lens, "vi", "m ");
	sh_pipe_auto(ch, lens, "ca", "t ");
	sh_pipe_auto(ch, lens, "uns", "etenv ");
	sh_pipe_auto(ch, lens, "unse", "tenv ");
	sh_pipe_auto(ch, lens, "unset", "env ");
	sh_pipe_auto(ch, lens, "unsete", "nv ");
	sh_pipe_auto(ch, lens, "unseten", "v ");
	sh_pipe_auto(ch, lens, "set", "env ");
	sh_pipe_auto(ch, lens, "sete", "nv ");
	sh_pipe_auto(ch, lens, "seten", "v ");
	sh_pipe_auto(ch, lens, "cd", " ");
	sh_pipe_auto(ch, lens, "ex", "it ");
	sh_pipe_auto(ch, lens, "exi", "t ");
	sh_pipe_auto(ch, lens, "ba", "sh ");
}
