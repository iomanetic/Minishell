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
#include "includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_minishell	shell;

	(void)argc;
	(void)argv;
	minishell_init(&shell);
	envp_init(&shell, envp);
	while (shell.status)
	{
		if (accept_signals())
			exit (-1);
		shell.line = readline(PROMPT);
		if (!shell.line)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			exit (shell.exit_status);
		}
		add_history(shell.line);
		shell_parser(&shell);
		if (shell.p_cmd)
			kill_zombie(&shell);
		ft_cleaner(&shell);
	}
	return (FALSE);
}
