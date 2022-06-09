/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 17:04:04 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	write_export_lines(t_minishell *shell)
{
	t_elem	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd((char *)tmp->key, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putstr_fd((char *)tmp->value, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		tmp = tmp->next;
	}
}

int	check_env(t_minishell *shell, char *key, char *value)
{
	t_elem	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (!strcmp(tmp->key, key))
		{
			ft_realloc(&tmp->value, value);
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

static int	norm_help(t_minishell *shell, int i, int tmp)
{
	char	*key;
	char	*value;

	if (!shell->exec->command[1][i] && !shell->exec->command[2])
	{
		shell->exit_status = 0;
		return (TRUE);
	}
	else if (!shell->exec->command[1][i])
		return (ft_error(E_ESE, shell->exec->command[1]));
	while (shell->exec->command[1][i])
		i++;
	key = ft_substr(shell->exec->command[1], 0, tmp);
	value = ft_substr(shell->exec->command[1], tmp + 1, i);
	if (check_env(shell, key, value))
	{
		free(value);
		free(key);
		return (TRUE);
	}
	ft_lstadd_back(&shell->env, ft_lstnew(key, value, 0));
	return (TRUE);
}

int	add_newenv(t_minishell *shell)
{
	int		i;
	int		tmp;

	i = 0;
	if (check_synt_export(shell->exec->command[1][i], FALSE))
		return (ft_error(E_ESE, shell->exec->command[1]));
	while (shell->exec->command[1][i] && shell->exec->command[1][i] != '=')
	{
		if (check_synt_export(shell->exec->command[1][i], TRUE))
		{
			shell->exit_status = 1;
			return (ft_error(E_ESE, shell->exec->command[1]));
		}
		i++;
	}
	tmp = i;
	norm_help(shell, i, tmp);
	return (FALSE);
}

int	ft_export(t_minishell *shell)
{
	if (!shell->exec->command[1])
		write_export_lines(shell);
	else
		add_newenv(shell);
	return (TRUE);
}
