/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:06:34 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/22 20:07:05 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int	i;
	int	tl;
	int	l;

	i = 0;
	tl = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (tl + 1));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	l = i;
	i = 0;
	while (s2[i])
	{
		s[l + i] = s2[i];
		i++;
	}
	s[tl] = 0;
	return (s);
}
