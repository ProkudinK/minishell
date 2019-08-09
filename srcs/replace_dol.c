/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:45:32 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 15:50:16 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_dol(char **str, int *b, char ***g_env)
{
	char	*temp;
	char	*repl;
	char	**res;

	res = NULL;
	temp = NULL;
	repl = NULL;
	repl = search_bucks(*str + *b + 1, g_env);
	res = search_env((*str + *b + 1), g_env);
	if (res && repl)
		*b = ft_strchr(*res, '=') - *res;
	else
		*b = ft_strlen(*str);
	if ((temp = lexer_split(*str, ((*str) - *str), repl,
					(*str + *b + 1))) == NULL)
		exit(-6);
	free(*str);
	if (repl)
		free(repl);
	if (res)
		free(*res);
	*str = temp;
	*b = ft_strlen(repl);
}
