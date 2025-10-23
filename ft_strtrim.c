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
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[start] && check_set(s1[start], set))
		start++;
	while (end >= start && check_set(s1[end], set))
		end--;
	len = end - start + 1;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + start, len + 1);
	return (ret);
}
