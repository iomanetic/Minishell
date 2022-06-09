/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:08 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/19 14:31:09 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*head_list;
	int		i;

	head_list = lst;
	i = 0;
	while (head_list != NULL)
	{
		head_list = head_list -> next;
		i++;
	}
	return (i);
}
