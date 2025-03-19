/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:23:33 by srussame          #+#    #+#             */
/*   Updated: 2024/08/31 15:23:34 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;

	if (lst == NULL)
		return ;
	if (*lst == NULL && new != NULL)
	{
		*lst = new;
		return ;
	}
	else if (*lst != NULL && new != NULL)
	{
		lstlast = *lst;
		while (lstlast->next != NULL)
			lstlast = lstlast->next;
		lstlast->next = new;
	}
}
