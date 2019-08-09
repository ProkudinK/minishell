/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:32:50 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 20:21:39 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			sh_fun(char **c, t_sh_int *lens, char ***g_env)
{
	if (*c)
	{
		sh_check_enter(*c, g_env);
		ft_bzero((void *)*c, lens->len);
		(*lens).len = 0;
		lens->pos = 0;
		lens->size = 0;
		free(*c);
		*c = NULL;
	}
	else
		write(1, "\n", 1);
	write(1, "LORD\E[37m> ", 11);
}

static	void	checkout_shell(t_ch *tmp, t_sh_int *lens, char **ch,
		char ***g_env)
{
	if (*((*tmp).c) == 4 && (*lens).len == 0)
	{
		exit((write(1, "exit\n", 5)) * 0);
	}
	else if (*((*tmp).c) == 3)
		sh_sigint(ch, &(*lens));
	else if (*((*tmp).c) == '\t')
		sh_print_auto(ch, lens);
	else if (*((*tmp).c) == 27)
		printf_escape(&((*lens).pos), (*lens).len, (*tmp).n);
	else if (*((*tmp).c) == '\n')
		sh_fun(ch, &(*lens), g_env);
	else if (*((*tmp).c) == 127)
		sh_back(ch, &(*lens));
	else
	{
		sh_ic((*tmp).n, ch, &(*lens));
	}
}

int				start_shell(char **ch, char ***g_env)
{
	t_ch		tmp;
	t_sh_int	lens;

	tmp.n = 0;
	lens.pos = 0;
	lens.len = 0;
	lens.size = 0;
	write(1, "\E[31mLORD\E[37m> ", 16);
	while (1)
	{
		tmp.n = 0;
		tmp.n = sh_getch();
		checkout_shell(&tmp, &lens, ch, g_env);
	}
}
