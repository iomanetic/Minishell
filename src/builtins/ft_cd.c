/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 17:01:59 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_env(t_minishell *shell, char *old_path, char *new_path)
{
	t_elem	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "OLDPWD"))
			ft_realloc(&tmp->value, old_path);
		else if (!ft_strcmp(tmp->key, "PWD"))
			ft_realloc(&tmp->value, new_path);
		tmp = tmp->next;
	}
}

static int	norm_help(t_minishell *shell, char *new_path)
{
	if (!getcwd(new_path, PATH_MAX))
	{
		shell->exit_status = 1;
		perror("minishell:");
		return (TRUE);
	}
	return (FALSE);
}

int	ft_cd(t_minishell *shell)
{
	char	old_path[PATH_MAX];
	char	new_path[PATH_MAX];

	if (!shell->exec->command[1])
		return (TRUE);
	if (!getcwd(old_path, PATH_MAX))
	{
		shell->exit_status = 1;
		perror("minishell:");
		return (TRUE);
	}
	if (chdir(shell->exec->command[1]) == -1)
	{
		shell->exit_status = 1;
		perror("minishell");
		return (TRUE);
	}
	if (norm_help(shell, new_path))
		return (TRUE);
	change_env(shell, old_path, new_path);
	shell->exit_status = 0;
	return (TRUE);
}
