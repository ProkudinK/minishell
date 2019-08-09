/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:10:07 by wtalea            #+#    #+#             */
/*   Updated: 2019/06/26 19:01:44 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*lexer_split(char *str1, int len1, char *str2, char *str3)
{
	char	*temp;
	int		len2;
	int		len3;

	len2 = ft_strlen(str2);
	len3 = ft_strlen(str3);
	temp = NULL;
	if ((temp = (char *)malloc(len1 + len2 + len3)) == NULL)
		return (NULL);
	if (len1)
		ft_memcpy(temp, str1, len1);
	if (len2)
		ft_memcpy(temp + len1, str2, len2);
	if (len3)
		ft_memcpy(temp + len1 + len2, str3, len3);
	*(temp + len1 + len2 + len3) = '\0';
	return (temp);
}

char	*sh_str_path_split(char *str1, char *str2)
{
	int		len1;
	int		len2;
	char	*dst;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if ((dst = (char *)malloc(len1 + len2 + 2)) == NULL)
		exit(-5);
	ft_memcpy(dst, str1, len1);
	*(dst + len1) = '/';
	ft_memcpy((dst + len1 + 1), str2, len2);
	*(dst + len1 + len2 + 1) = '\0';
	return (dst);
}
