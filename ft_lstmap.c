/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnikolov <lnikolov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:55:11 by lnikolov          #+#    #+#             */
/*   Updated: 2023/10/11 15:10:02 by lnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_lst;
	t_list	*prev_lst;
	t_list	*head;

	prev_lst = NULL;
	head = lst;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_lst = ft_lstnew(new_content);
		if (!new_lst)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_lst->content = new_content;
		if (prev_lst != NULL)
			prev_lst->next = new_lst;
		else
			head = new_lst;
		prev_lst = new_lst;
		lst = lst->next;
	}
	return (head);
}
