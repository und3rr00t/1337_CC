/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:23:31 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/17 15:23:33 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;
	size_t i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
