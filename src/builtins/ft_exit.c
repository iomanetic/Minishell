/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 16:31:13 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_minishell *shell)
{
	int			i;

	i = 0;
	if (!shell->exec->command[1])
		exit(shell->exit_status);
	else
	{
		if (shell->exec->command[1][i] == '-')
			i++;
		while (shell->exec->command[1][i])
		{
			if (!ft_isdigit(shell->exec->command[1][i]))
			{
				ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
				ft_putstr_fd(shell->exec->command[1], STDERR_FILENO);
				ft_putstr_fd(" numeric argument required\n", STDERR_FILENO);
				exit(255);
			}
			i++;
		}
	}
	exit(ft_atoi(shell->exec->command[1]) % 256);
}
