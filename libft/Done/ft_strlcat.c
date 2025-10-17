/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:14:58 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/17 15:15:00 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ld;
	size_t ls;
	size_t i;

	i = 0;
	ld = ft_strlen(dst);
	ls = ft_strlen(char);
	/*while (dst[ld] && ld < size)
		ld++;
	while (src[ls])
		ls++;*/
	if (size == 0)
		return (ls);
	if (ld >= size)
		return (ls + size);
	while (src[i] && (ld + i) < size - 1)
	{
		dst[ld + i] = src[i];
		i++;
	}
	if (ld + i < size)
		dst[ld + i] = '\0';
	return (ls + ld);
}
