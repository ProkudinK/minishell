/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:31:17 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/11 12:36:36 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_ftnblen(char const *s, char c)
{
	size_t	i;
	size_t	len;
	int		bol;

	len = 0;
	i = 0;
	bol = 0;
	while (*(s + i))
	{
		if (*(s + i) != c && bol == 0)
		{
			bol = 1;
			len++;
			i++;
			continue;
		}
		if (*(s + i) == c)
			bol = 0;
		i++;
	}
	return (len);
}

static	void	ft_ftgo(size_t *j, size_t *k, const char *s, char c)
{
	while (*(s + *j) == c && *(s + *j))
		*j = *j + 1;
	while (*(s + *j + *k) != c && *(s + *j + *k))
		*k = *k + 1;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**stsp;
	size_t	i;
	size_t	j;
	size_t	nb;
	size_t	k;

	nb = 0;
	i = 0;
	k = 0;
	j = 0;
	nb = ft_ftnblen(s, c);
	if ((stsp = (char **)malloc(sizeof(char *) * nb + 1)) == NULL)
		return (NULL);
	while (i < nb)
	{
		j = j + k;
		k = 0;
		ft_ftgo(&j, &k, s, c);
		if ((*(stsp + i) = ft_strsub(s, j, k)) == NULL)
			return (ft_nullmemdel((void ***)&stsp, i));
		i++;
	}
	*(stsp + i) = NULL;
	return (stsp);
}
