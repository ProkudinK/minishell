/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <wtalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:17:36 by wtalea            #+#    #+#             */
/*   Updated: 2018/12/15 19:22:16 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strswitch(char *sr1, char *sr2)
{
	char	*cp;

	if ((cp = ft_strjoin(sr1, sr2)) == NULL)
		return (NULL);
	ft_strdel(&sr1);
	ft_strdel(&sr2);
	return (cp);
}
