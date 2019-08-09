/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_lr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:57:48 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/17 18:58:17 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_sigint(char **c, t_sh_int *lens)
{
	if (*c)
	{
		bzero((void *)*c, lens->len);
		(*lens).len = 0;
		lens->pos = 0;
		lens->size = 0;
		free(*c);
		*c = NULL;
	}
	write(1, "\nLORD> ", 7);
}

void	sh_sd_left(char *ch, int *pos, int *len)
{
	int		i;

	(*len)--;
	(*pos)--;
	i = *pos;
	while (i < *len)
		write(1, (ch + i++), sh_is_unicode(*(ch + *pos)));
	while (i-- > *pos)
		write(1, "\b", 1);
}

void	sh_sd_right(t_ch *ch, int *pos, int *len)
{
	int		i;

	++(*pos);
	i = *pos;
	write(1, "\33[C", 4);
	while (i < *len)
		write(1, (ch + i++), SIZECH(*((*(ch + *pos)).c)));
	while (i-- > *pos)
		write(1, "\b", 1);
	--(*pos);
}
