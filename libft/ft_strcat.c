/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:59:21 by klouer            #+#    #+#             */
/*   Updated: 2017/11/24 14:35:38 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	len;
	int j;

	j = 0;
	len = ft_strlen(s1);
	while (s2[j])
	{
		s1[len + j] = s2[j];
		j++;
	}
	s1[len + j] = '\0';
	return (s1);
}
