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

int	norm_help(t_minishell *shell, pid_t pid)
{
	if (shell->flag_pipe)
	{
		if (closepipes(shell, shell->p_cmd, pid))
			return (TRUE);
	}
	else
		waitpid(pid, &shell->exit_status, 0);
	ft_exit_status(shell);
	return (FALSE);
}

int	exec(t_minishell *shell)
{
	pid_t	pid;

	signal(SIGINT, SIG_IGN);
	if (something_exec(shell, TRUE))
		return (TRUE);
	pid = fork();
	if (pid < 0)
		return (ft_error(E_FI, NULL));
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		dup2(shell->redir_out, STDOUT_FILENO);
		dup2(shell->redir_in, STDIN_FILENO);
		something_exec(shell, FALSE);
		if (find_cmd(shell->token))
			exit(0);
		if (execve(shell->exec->path, shell->exec->command, shell->envp) == -1)
		{
			perror("minishell");
			exit(CMD_NOT_FOUND);
		}
	}
	if (norm_help(shell, pid))
		return (TRUE);
	return (FALSE);
}
