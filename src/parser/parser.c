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

void	ft_refreshfd(t_minishell *shell)
{
	shell->redir_out = STDOUT_FILENO;
	shell->redir_in = STDIN_FILENO;
}

void	exec_with_loop(t_minishell *shell)
{
	t_minishell	*tmp;
	t_pipescmd	*cmd;

	write_x2list(shell);
	tmp = shell;
	cmd = shell->p_cmd;
	while (tmp->p_cmd)
	{
		ft_refreshfd(tmp);
		if (!ft_openredirects(tmp, tmp->p_cmd->token))
		{
			find_path(tmp, tmp->p_cmd->token);
			tmp->exec->command = ft_split_shell(tmp->p_cmd->token);
			exec(tmp);
			ft_freex2arr(tmp->exec->command);
			free(tmp->exec->path);
		}
		tmp->p_cmd = tmp->p_cmd->next;
	}
	shell->p_cmd = cmd;
}

int	shell_parser(t_minishell *shell)
{
	if (!*shell->line)
		return (TRUE);
	if (lexer(shell))
		return (TRUE);
	if (shell_preparser(shell))
		return (TRUE);
	if (pipeistrue(shell->token))
	{
		shell->flag_pipe = 1;
		exec_with_loop(shell);
	}
	else
	{
		if (ft_openredirects(shell, shell->token))
			return (TRUE);
		if (find_cmd(shell->token))
			return (TRUE);
		find_path(shell, shell->token);
		shell->exec->command = ft_split_shell(shell->token);
		exec(shell);
		free(shell->exec->path);
		ft_freex2arr(shell->exec->command);
	}
	return (FALSE);
}
