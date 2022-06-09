/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karimvaliev <karimvaliev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:48:40 by karimvaliev       #+#    #+#             */
/*   Updated: 2021/10/20 13:48:41 by karimvaliev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr_lst;
	t_list	*new_elem;

	if (!lst)
		return (NULL);
	new_elem = ft_lstnew(f(lst->content));
	if (!(new_elem))
	{
		ft_lstclear(&ptr_lst, del);
		return (NULL);
	}
	ptr_lst = new_elem;
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!(new_elem))
		{
			ft_lstclear(&ptr_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&ptr_lst, new_elem);
	}
	return (ptr_lst);
}
