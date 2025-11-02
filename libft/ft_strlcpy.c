/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:15:13 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/23 14:05:02 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	i;

	l = ft_strlen((char *)src);
	i = 0;
	if (size == 0)
		return (l);
	while (i < size -1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i <= l)
		dst[i] = '\0';
	return (l);
}
