/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:18:19 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/17 17:27:41 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			es_check(int *esch, int len, char c, int p)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (c == *(((char *)(esch + i)) + p))
			return (c);
		i++;
	}
	return (0);
}

int			sh_escape_check(int *esch, int len)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	*((char *)&i) = 27;
	*(((char *)&i) + 1) = getch();
	if ((check = es_check(esch, len, *(((char *)&i) + 1), 1)) != 0)
		if (es_full_check(i, len, esch) == 1)
			return (i);
	if (!check)
		return (0);
	*(((char *)&i) + 2) = getch();
	if ((check = es_check(esch, len, *(((char *)&i) + 2), 2)) != 0)
		if (es_full_check(i, len, esch) == 1)
			return (i);
	if (!check)
		return (0);
	*(((char *)&i) + 3) = getch();
	if (es_check(esch, len, *(((char *)&i) + 1), 1) != 0)
		if (es_full_check(i, len, esch) == 1)
			return (i);
	return (0);
}

static	int	dop_sh_is_ascii(t_ch *ch)
{
	*(((*ch).c) + 1) = '\0';
	return ((*ch).n);
}

int			sh_getch(void)
{
	t_ch	ch;
	int		len;
	int		i;

	ch.n = 0;
	len = 0;
	i = 1;
	*(ch.c) = getch();
	if (sh_is_ascii(ch) > 0)
	{
		if (sh_is_ascii(ch) == 1)
			return (dop_sh_is_ascii(&ch));
		else
			return (sh_escape());
	}
	else
	{
		if (sh_is_unicode(*(ch.c)) > 1)
		{
			sh_read_unicode(&ch);
			return (ch.n);
		}
	}
	return (ch.n);
}
