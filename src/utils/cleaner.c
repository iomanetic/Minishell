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

void	kill_zombie(t_minishell *shell)
{
	t_pipescmd	*cmd;

	cmd = shell->p_cmd;
	while (cmd)
	{
		wait(NULL);
		cmd = cmd->next;
	}
}

void	ft_clean_x2list(t_pipescmd *cmd)
{
	t_pipescmd	*tmp1;
	t_elem		*tmp2;

	while (cmd)
	{
		tmp1 = cmd;
		cmd = cmd->next;
		while (tmp1->token)
		{
			tmp2 = tmp1->token;
			tmp1->token = tmp1->token->next;
			free(tmp2->value);
			free(tmp2);
		}
		free(tmp1);
	}
}

void	ft_freeheredoc(t_heredoc *heredoc)
{
	t_heredoc	*tmp;

	while (heredoc)
	{
		tmp = heredoc;
		heredoc = heredoc->next;
		close(tmp->fd);
		unlink(tmp->name);
		if (tmp->name)
		{
			free(tmp->name);
			tmp->name = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
}

void	after_write_data(t_minishell *shell)
{
	shell->heredoc = NULL;
	shell->line = NULL;
	shell->tmp = NULL;
	shell->p_cmd = NULL;
	shell->token = NULL;
	shell->redir_in = 0;
	shell->redir_out = 1;
}

void	ft_cleaner(t_minishell *shell)
{
	t_elem	*tmp;

	if (shell->flag_pipe)
	{
		ft_clean_x2list(shell->p_cmd);
		shell->flag_pipe = 0;
	}
	if (shell->token)
	{
		tmp = shell->token;
		while (shell->token)
		{
			shell->token = shell->token->next;
			free(tmp->value);
			free(tmp);
			tmp = shell->token;
		}
	}
	if (shell->line)
		free(shell->line);
	if (shell->tmp)
		ft_freeheredoc(shell->tmp);
	after_write_data(shell);
}
