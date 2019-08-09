/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:32:13 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/20 20:08:01 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <ctype.h>

void		sh_rewrite(int size, int pos, int len, char *ch)
{
	int		i;

	i = 0;
	while (++i < pos)
		write(1, "\b", 1);
	i = 0;
	while (i++ < len)
		write(1, " ", 1);
	i = 0;
	while (i++ < len)
		write(1, "\b", 1);
	i = 0;
	write(1, ch, size);
	while (i++ < (len - pos))
		write(1, "\b", 1);
}

void		*sh_memin(int pos, char *ch, int *size, int n)
{
	long			i;
	unsigned long	len;
	char			*cp;
	int				nsize;

	if ((cp = (char *)malloc(*size + sh_is_unicode(*((char *)&n)) + 1)) == NULL)
		exit(1);
	i = 0;
	len = 0;
	nsize = sh_is_unicode(*((char *)&n));
	while (i != pos)
	{
		len += sh_is_unicode(*(ch + len));
		++i;
	}
	ft_memcpy(cp, ch, (len));
	ft_memcpy((cp + len), (const void *)&n, nsize);
	ft_memcpy((cp + len + nsize), (ch + len), (*size - len));
	*(cp + *size + nsize) = '\0';
	free(ch);
	return (cp);
}

void		sh_ic(int n, char **ch, t_sh_int *lengths)
{
	char	*tmp;

	if (ft_isalnum((char)n) == 1 || sh_is_unicode((char)n) > 1 || isprint(n))
	{
		if ((tmp = (char *)malloc(sh_is_unicode(*((char *)&n)) + 1)) == NULL)
			exit(1);
		ft_memcpy(tmp, &n, sh_is_unicode((char)n));
		*(tmp + sh_is_unicode(*((char *)&n))) = '\0';
		if ((*lengths).pos == (*lengths).len)
			*ch = ft_strrejoin(*ch, tmp);
		else
			*ch = sh_memin((*lengths).pos, *ch, &((*lengths).size), n);
		++((*lengths).pos);
		++((*lengths).len);
		((*lengths).size) += sh_is_unicode(*((char *)(&n)));
		sh_rewrite(((*lengths).size), ((*lengths).pos), ((*lengths).len), *ch);
		free(tmp);
	}
}

int			sh_size_pos(char *ch, int pos)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (i++ < pos)
		size += sh_is_unicode(*(ch + size));
	return (size);
}
