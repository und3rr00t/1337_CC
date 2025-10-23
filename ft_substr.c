/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:01:07 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/19 19:09:48 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen((char *)s);
	if ((size_t)start >= slen)
		len = 0;
	else if (len > slen - (size_t)start)
		len = slen - (size_t)start;
	sb = (char *)malloc(sizeof(char) * (len + 1));
	if (!sb)
		return (NULL);
	while (i < len)
	{
		sb[i] = s[start + i];
		i++;
	}
	sb[i] = '\0';
	return (sb);
}
