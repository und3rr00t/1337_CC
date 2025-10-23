/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:40:13 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/23 13:41:02 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int	i;
	int	ls;
	int	size;

	if (!s1 || !set)
		return (NULL);
	ls = ft_strlen((char *)s1) - 1;
	i = 0;
	while (s1[i] && check_set(s1[i], set))
		i++;
	while (s1[ls] && check_set(s1[ls], set))
		ls--;
	size = ls - i + 1;
	if (size < 0)
		size = 0;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ls = 0;
	while (ls < size)
	{
		ret[ls] = s1[i + ls];
		ls++;
	}
	ret[ls] = 0;
	return (ret);
}
