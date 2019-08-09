/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lib_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:14:10 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/17 17:21:03 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		sh_is_ascii(t_ch ch)
{
	if (*(ch.c) == 27)
		return (2);
	else if (((*(ch.c) >> 7) & 1) == 0)
		return (1);
	else
		return (0);
}

int		sh_is_comm(t_ch ch)
{
	if (*(ch.c) == 27)
	{
		*(ch.c + 1) = getch();
		if (*(ch.c + 1) == 91)
			*(ch.c + 2) = getch();
		return (ch.n);
	}
	return (0);
}

int		sh_is_unicode(char c)
{
	if (((c >> 8) & 1) == 1)
		if (((c >> 6) & 1) == 1)
		{
			if (((c >> 5 & 1)) == 0)
				return (2);
			else if (((c >> 4) & 1) == 0)
				return (3);
			else if (((c >> 3) & 1) == 0)
				return (4);
		}
	return (1);
}

void	sh_read_unicode(t_ch *ch)
{
	if (sh_is_unicode(*((*ch).c)) >= 2)
		*(((*ch).c) + 1) = getch();
	if (sh_is_unicode(*((*ch).c)) >= 3)
		*(((*ch).c) + 2) = getch();
	if (sh_is_unicode(*((*ch).c)) == 4)
		*(((*ch).c) + 3) = getch();
}

int		es_full_check(int n, int len, int *esch)
{
	int i;

	i = 0;
	while (i < len)
		if (n == *(esch + i++))
			return (1);
	return (0);
}
