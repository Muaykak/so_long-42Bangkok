/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:07:29 by srussame          #+#    #+#             */
/*   Updated: 2024/08/31 14:07:30 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(1 * sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list[0].content = content;
	new_list[0].next = NULL;
	return (new_list);
}
