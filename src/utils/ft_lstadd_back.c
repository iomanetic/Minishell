/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:30:29 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/19 14:30:30 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_lstadd_back_heredoc(t_heredoc **lst, t_heredoc *new)
{
	t_heredoc	*ptr;

	if (!lst || !new)
		return (ft_error(E_HE, NULL));
	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (FALSE);
}

void	ft_lstadd_back(t_elem **lst, t_elem *new)
{
	t_elem	*ptr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}
