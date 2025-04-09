/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:45:12 by srussame          #+#    #+#             */
/*   Updated: 2025/03/29 10:45:25 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* move the target list from the old list to new list */
void	ft_move_to_newlist(t_list	**old, t_list *target, t_list **new,
			void (*lstadd)(t_list **, t_list *))
{
	t_list	*run;

	if (old == NULL || *old == NULL || target == NULL || new == NULL)
		return ;
	run = *old;
	if (run == target)
	{
		*old = target->next;
		target->next = NULL;
		lstadd(new, target);
		return ;
	}
	while (run != NULL && run->next != target)
		run = run->next;
	if (run == NULL)
		return ;
	run->next = target->next;
	target->next = NULL;
	lstadd(new, target);
	return ;
}

// print the string to standard error
ssize_t	ft_strerr(char *str)
{
	size_t	str_l;

	if (str == NULL)
		return (0);
	str_l = ft_strlen(str);
	return (write(STDERR_FILENO, str, str_l));
}
