/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:22:35 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/25 14:39:52 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	check_dot_dob(char **temp)
{
	int		i;

	i = 0;
	if (temp && *temp)
	{
		while ((*temp)[i])
			++i;
		if (i > 1 && (*temp)[i - 1] != ':')
			if ((*temp = ft_strrejoin(*temp, ":")) == NULL)
				exit(-5);
	}
}

void			check_dot(char **pwd, char *env, char *envt)
{
	char	*temp;

	temp = NULL;
	if ((temp = ft_strdup(env)) == NULL)
		exit(-5);
	check_dot_dob(&temp);
	if ((*pwd = ft_strdup(temp)) == NULL)
		exit(-5);
	ft_strcpy(envt, temp);
	free(temp);
}
