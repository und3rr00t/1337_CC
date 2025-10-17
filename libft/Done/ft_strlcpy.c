/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:15:13 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/17 16:35:28 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
<<<<<<< HEAD
#include <stddef.h>
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
=======

#include "libft.h"

size_t	strlcpy(char *dst, const char *src, size_t size)
>>>>>>> 6c50cc6f7c1567c77d08b20c9d7a4e780de5e32f
{
	size_t	l;

	l = ft_strlen(src);
	size_t i = 0;
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
