/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:00:41 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/22 16:57:49 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	ft_strs(char *s, char c)
{
	int	i;
	int	sub;

	i = 0;
	sub = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			sub++;
		}
		i++;
	}
	return (sub);
}
char	*get_word(const char *s, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	       
	i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_strs(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = get_word(s, c);
			if (!res[i])
				return (free_all(res), NULL);
			s += ft_strlen(res[i++]);
		}
	}
	res[i] = NULL;
	return (res);
}
