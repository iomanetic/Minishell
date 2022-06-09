/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/19 14:31:05 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_minishell *shell)
{
	t_elem	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		ft_putstr_fd((char *)tmp->key, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putstr_fd((char *)tmp->value, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		tmp = tmp->next;
	}
	shell->exit_status = 0;
	return (TRUE);
}
