/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:20:14 by srussame          #+#    #+#             */
/*   Updated: 2024/11/05 06:02:20 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	while (lst != NULL && *lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

//#include <stdio.h>
//
//void delete_malloc(void *ptr)
//{
//	if (ptr != 0)
//		free(ptr);
//	ptr = 0;
//}
//
//int main(int ac, char **argv)
//{
//	int		i;
//	t_list	*word_list;
//	t_list	*start_list;
//
//
//	if (ac < 2)
//		return (0);
//	i = 1;
//	word_list = 0;
//	while (i < ac)
//	{
//		ft_lstadd_back(&word_list, ft_lstnew(ft_strdup(argv[i])));
//		i++;
//	}
//	i = 0;
//	start_list = word_list;
//	while (start_list != 0)
//	{
//		printf("word_list[%d] = \"%s\"\n", i, (char *)start_list->content);
//		start_list = start_list->next;
//		i++;
//	}
//
//	printf("\n\nBEGIN DELETE ALL THE LIST");
//
//	ft_lstclear(&word_list, &delete_malloc);
//	return (0);
//}
