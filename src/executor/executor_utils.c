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

int	something_exec(t_minishell *shell, int flag)
{
	if (shell->flag_pipe && flag == FALSE)
		for_pipes(shell, flag);
	if (flag == FALSE && search_builtins(shell, flag))
		exit (shell->exit_status);
	else if (flag == TRUE && search_builtins(shell, flag))
		return (TRUE);
	return (FALSE);
}

int	closepipes(t_minishell *shell, t_pipescmd *cmd, pid_t pid)
{
	if (cmd->pipe_status == 0)
		if (close(cmd->fd[1]) == -1)
			return (ft_error(E_CFD, NULL));
	if (cmd->pipe_status == 1)
	{
		if (close(cmd->fd[1]) == -1)
			return (ft_error(E_CFD, NULL));
		if (close(cmd->fd_for_read) == -1)
			return (ft_error(E_CFD, NULL));
	}
	if (cmd->pipe_status == 2)
		if (close(cmd->fd_for_read) == -1)
			return (ft_error(E_CFD, NULL));
	if (!cmd->next)
		if (waitpid(pid, &shell->exit_status, 0) == -1)
			return (ft_error(E_WP, NULL));
	return (FALSE);
}

void	for_pipes(t_minishell *shell, int flag)
{
	if (find_cmd(shell->p_cmd->token))
		exit(0);
	if (shell->p_cmd->pipe_status != 2)
		if (dup2(shell->p_cmd->fd[1], shell->redir_out) == -1)
			exit (-1);
	if (dup2(shell->p_cmd->fd_for_read, shell->redir_in) == -1)
		exit (-1);
	if (shell->p_cmd->pipe_status != 2 && flag == FALSE)
		close(shell->p_cmd->fd[0]);
}

void	ft_exit_status(t_minishell *shell)
{
	int	exit_status;

	if (WIFEXITED(shell->exit_status))
	{
		exit_status = WEXITSTATUS(shell->exit_status);
		shell->exit_status = exit_status;
	}
	else if (WIFSIGNALED(shell->exit_status))
	{
		exit_status = 128 + WTERMSIG(shell->exit_status);
		shell->exit_status = exit_status;
	}
}

int	find_cmd(t_elem *tmp)
{
	while (tmp)
	{
		if (!ft_istoken(tmp->key_t))
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
