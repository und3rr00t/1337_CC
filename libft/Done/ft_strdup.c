/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:12:26 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/23 14:11:39 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*strdup(const char *s)
{
	char	*copy;
	int		i;

	i = 0;
	while (s[i])
		i++;
	copy = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
