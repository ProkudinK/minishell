/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:19:54 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/18 19:38:22 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		dol_get_name(char **str, int *b)
{
	int		ipid;
	char	num[13];
	char	*temp;

	ipid = getpid();
	ft_itoa_nm(ipid, num);
	if ((temp = lexer_split(*str, ((*str + *b) - *str), num,
					(*str + *b + 2))) == NULL)
		exit(-6);
	free(*str);
	*str = temp;
	*b += ft_strlen(num);
}

static void		find_lex_sym(char **str, int *b, char ***g_env)
{
	char		*temp;

	temp = NULL;
	if (*(*str + *b) == '$' && (*(*str + *b + 1) == '\0'))
		++(*b);
	else if ((*(*str + *b) == '$' && *(*str + *b + 1) == '~') ||
			(*(*str + *b) == '~' && *(*str + *b + 1) == '$'))
		*b += 2;
	else if ((*(*str + *b) == '$' && *(*str + *b + 1) == '$'))
		dol_get_name(str, b);
	else if (*(*str + *b) == '$' && ft_isalpha(*(*str + *b + 1)))
		replace_dol(str, b, g_env);
	else if (*(*str + *b) == '~' && (*(*str + *b + 1) == '+' ||
				(*(*str + *b + 1) == '-')) && ((*(*str + *b + 2) == '\0')
					|| (*(*str + *b + 2) == ' ')))
		replace_tilda_path(str, b, g_env);
	else if (*(*str + *b) == '~')
		replace_tilda(str, b);
}

static	void	dop_lexer(t_parse **parse, int *i, char ***g_env)
{
	int		b;

	b = 0;
	while (*(*(((*parse)->agv + *i)) + b))
	{
		if (*(*(((*parse)->agv + *i)) + b) == '$' ||
				*(*(((*parse)->agv + *i)) + b) == '~')
			find_lex_sym(((((*parse)->agv + *i))), &b, g_env);
		else
			++b;
	}
}

void			start_lexer(t_parse **parse, char ***g_env)
{
	int		i;
	int		j;
	t_parse	*cp;

	cp = *&*parse;
	i = 0;
	j = 0;
	while (cp)
	{
		while (*((*parse)->agv + i))
		{
			dop_lexer(parse, &i, g_env);
			++i;
		}
		cp = cp->next;
	}
	del_quotes(parse);
}
