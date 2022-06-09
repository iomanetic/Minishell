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

int	get_pipesfd(t_pipescmd *p_cmd)
{
	while (p_cmd)
	{
		if (p_cmd->pipe_status != 2)
			if (pipe(p_cmd->fd) < 0)
				return (ft_error(E_PIE, NULL));
		if (p_cmd->pipe_status == 0)
			p_cmd->fd_for_read = STDIN_FILENO;
		else
			p_cmd->fd_for_read = p_cmd->prev->fd[0];
		if (p_cmd->pipe_status == 2)
			p_cmd->fd[1] = STDOUT_FILENO;
		p_cmd = p_cmd->next;
	}
	return (FALSE);
}

void	write_pipestatus(t_pipescmd *p_cmd)
{
	p_cmd->pipe_status = 0;
	p_cmd = p_cmd->next;
	while (p_cmd->next)
	{
		p_cmd->pipe_status = 1;
		p_cmd = p_cmd->next;
	}
	p_cmd->pipe_status = 2;
}

void	write_pipelist(t_minishell *shell, t_elem *token, int action, int type)
{
	t_pipescmd	*prev;
	t_pipescmd	*new_elem;

	if (action == 1)
	{
		new_elem = (t_pipescmd *) malloc(sizeof(t_pipescmd));
		if (type == 1)
		{
			prev = NULL;
			shell->p_cmd = new_elem;
		}
		else
		{
			prev = shell->p_cmd;
			shell->p_cmd->next = new_elem;
			shell->p_cmd = shell->p_cmd->next;
		}
		shell->p_cmd->prev = prev;
		shell->p_cmd->next = NULL;
		shell->p_cmd->token = NULL;
	}
	else
		ft_lstadd_back(&shell->p_cmd->token, ft_lstnew(NULL, \
		ft_strdup((char *)token->value), token->key_t));
}

int	pipeistrue(t_elem *token)
{
	t_elem	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->key_t == PIPE)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

int	write_x2list(t_minishell *shell)
{
	t_elem	*tmp;

	tmp = shell->token;
	write_pipelist(shell, tmp, 1, 1);
	while (tmp)
	{
		if (tmp->key_t == PIPE)
		{
			write_pipelist(shell, tmp, 1, 0);
			tmp = tmp->next;
		}
		else
		{
			write_pipelist(shell, tmp, 0, 0);
			tmp = tmp->next;
		}
	}
	ft_backtohead(&shell->p_cmd);
	write_pipestatus(shell->p_cmd);
	if (get_pipesfd(shell->p_cmd))
		return (TRUE);
	return (FALSE);
}
