/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_print_escape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:16:43 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 16:52:21 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printf_escape(int *esch, int len, int n)
{
	int		*os;

	os = (int[]){0x445B1B, 0x435B2B, UP, DOWN};
	if (n == LEFT)
		sh_left(esch);
	else if (n == RIGHT)
		sh_right(esch, len);
}

int		sh_escape(void)
{
	int			*esch;
	int			len;
	int			n;

	n = 0;
	len = LEN_ES;
	esch = (int[]){LEFT, RIGHT, UP, DOWN};
	n = sh_escape_check(esch, len);
	return (n);
}
