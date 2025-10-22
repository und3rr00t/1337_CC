/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:36:25 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/21 21:48:50 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	while (*lst != NULL)
	{
		del((*lst)->content);
		next = (*lst)->next;
		free(*lst);
		(*lst) = next;
	}
}
