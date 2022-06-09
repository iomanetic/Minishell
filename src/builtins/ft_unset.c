/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 17:22:19 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_synt_export(char symb, int flag)
{
	if ((ft_isalnum(symb) || symb == '_') && flag == FALSE)
		return (FALSE);
	if ((ft_isalpha(symb) || symb == '_') && flag == TRUE)
		return (FALSE);
	return (TRUE);
}

int	delete_env(t_minishell *shell, t_elem **key)
{
	t_elem	**tmp;
	t_elem	*head;

	tmp = &shell->env;
	if (*tmp != *key)
	{
		head = shell->env;
		while (*tmp && (*tmp)->next != *key)
			*tmp = (*tmp)->next;
		(*tmp)->next = (*key)->next;
	}
	else
	{
		head = shell->env->next;
		*tmp = (*key)->next;
	}
	free((*key)->value);
	free((*key)->key);
	free(*key);
	shell->env = head;
	return (TRUE);
}

int	unset_env_check(t_minishell *shell, char *key)
{
	t_elem	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (delete_env(shell, &tmp));
		tmp = tmp->next;
	}
	return (FALSE);
}

static int	norm_help(t_minishell *shell)
{
	int	i;

	i = 0;
	if (check_synt_export(shell->exec->command[1][i], TRUE))
	{
		shell->exit_status = 1;
		return (ft_error(E_UE, shell->exec->command[1]));
	}
	while (shell->exec->command[1][i])
	{
		if (check_synt_export(shell->exec->command[1][i], FALSE))
		{
			shell->exit_status = 1;
			return (ft_error(E_UE, shell->exec->command[1]));
		}
		i++;
	}
	return (FALSE);
}

int	ft_unset(t_minishell *shell)
{
	char	*key;

	if (!shell->exec->command[1])
	{
		shell->exit_status = 0;
		return (TRUE);
	}
	if (norm_help(shell))
		return (TRUE);
	key = ft_strdup(shell->exec->command[1]);
	if (!key)
	{
		ft_error(E_MA, NULL);
		exit(-1);
	}
	unset_env_check(shell, key);
	shell->exit_status = 0;
	free(key);
	return (TRUE);
}
