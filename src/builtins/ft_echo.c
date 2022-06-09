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

int	ft_echo(t_minishell *shell)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (shell->exec->command[i + 1] && \
		!ft_strcmp(shell->exec->command[i + 1], "-n"))
	{
		flag = 0;
		i++;
	}
	while (shell->exec->command[++i])
	{
		ft_putstr_fd(shell->exec->command[i], STDOUT_FILENO);
		if (shell->exec->command[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
	shell->exit_status = 0;
	return (TRUE);
}
