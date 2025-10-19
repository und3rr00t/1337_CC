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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	i;

	i = 0;
	sb = (char)malloc(sizeof(char) * (len + 1));
	if (!sb)
		return (NULL);
	while (s[start] && len-- > 0)
	{
		sb[i] = s[start + i];
		i++;
	}
	sb[i] = '\0';
	return (sb);
}
