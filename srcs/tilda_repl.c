/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda_repl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:39:06 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/24 16:11:31 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_tilda(char *str)
{
	char			*temp;
	int				i;
	struct passwd	*name;

	temp = NULL;
	i = 0;
	if (*str)
	{
		while (*(str + i) && ft_isalpha(*(str + i)))
			++i;
		if ((temp = malloc(i + 1)) == NULL)
			exit(-5);
		ft_clmemcpy(temp, str, i);
		*(temp + i) = '\0';
	}
	if (temp && *temp)
		name = getpwnam(temp);
	else
		name = getpwuid(getuid());
	if (temp)
		free(temp);
	if (name && name->pw_dir)
		return (name->pw_dir);
	else
		return (NULL);
}

void		replace_tilda(char **str, int *b)
{
	char	*temp;
	char	*repl;
	int		i;

	i = 0;
	repl = search_tilda(*str + *b + 1);
	if (repl)
	{
		if ((temp = lexer_split(*str, (*str - (*str + *b)), repl,
					(*str + *b + 1))) == NULL)
			exit(-6);
		free(*str);
		*str = temp;
		*b += ft_strlen(repl);
	}
	else
	{
		while (*(*str + i) && ft_isalpha(*(*str + i)))
			++*b;
	}
}

void		replace_tilda_path(char **str, int *b, char ***g_env)
{
	char	*temp;
	char	*cp;

	temp = NULL;
	if (*(*str + 1) == '+')
		search_bucks_dop("PWD", &temp, 3, g_env);
	else if (*(*str + 1) == '-')
		search_bucks_dop("OLDPWD", &temp, 6, g_env);
	if (!temp)
		cp = lexer_split(*str, *b, "", (*str + *b + 2));
	else
		cp = lexer_split(*str, *b, temp, (*str + *b + 2));
	free(*str);
	*str = cp;
	free(temp);
}
