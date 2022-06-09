/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 14:57:44 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_builtins(t_minishell *shell, int exec_status)
{
	if (exec_status == 7)
		return (ft_pwd(shell));
	if (exec_status == 6)
		return (ft_env(shell));
	if (exec_status == 5)
		return (ft_echo(shell));
	if (exec_status == 4)
		return (ft_export(shell));
	if (exec_status == 3)
		return (ft_unset(shell));
	if (exec_status == 2)
		return (ft_cd(shell));
	if (exec_status == 1)
		ft_exit(shell);
	return (FALSE);
}

int	search_builtins(t_minishell *shell, int flag)
{
	int	exec_status;

	exec_status = 0;
	if (!shell->exec->command[0])
		return (FALSE);
	if (!ft_strcmp("pwd", shell->exec->command[0]))
		exec_status = 7;
	if (!ft_strcmp("env", shell->exec->command[0]))
		exec_status = 6;
	if (!ft_strcmp("echo", shell->exec->command[0]))
		exec_status = 5;
	if (!ft_strcmp("export", shell->exec->command[0]))
		exec_status = 4;
	if (!ft_strcmp("unset", shell->exec->command[0]))
		exec_status = 3;
	if (!ft_strcmp("cd", shell->exec->command[0]))
		exec_status = 2;
	if (!ft_strcmp("exit", shell->exec->command[0]))
		exec_status = 1;
	if (exec_status != 0 \
		&& ((flag == TRUE && exec_status < 5) \
			|| (flag == FALSE && exec_status >= 5)))
		return (exec_builtins(shell, exec_status));
	return (FALSE);
}
