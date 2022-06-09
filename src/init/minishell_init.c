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

void	minishell_init(t_minishell *shell)
{
	shell->exec = (t_execve *) malloc(sizeof(t_execve));
	if (!shell->exec)
	{
		ft_error(E_MA, NULL);
		exit(1);
	}
	shell->status = 1;
	shell->exit_status = 0;
	shell->rebuild_env_status = 0;
	shell->flag_pipe = 0;
	shell->here_count = 0;
	shell->flag_built = 1;
	shell->redir_out = STDOUT_FILENO;
	shell->redir_in = STDIN_FILENO;
	shell->env = NULL;
	shell->token = NULL;
	shell->p_cmd = NULL;
	shell->heredoc = NULL;
	shell->tmp = NULL;
}
