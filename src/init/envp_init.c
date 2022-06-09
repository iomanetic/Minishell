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

int	len_to_sep(const char *env)
{
	int	i;

	i = 0;
	while (env[i] != '=')
		i++;
	return (i);
}

char	*take_value(char *env)
{
	int		i;
	int		k;
	char	*tmp;

	k = 0;
	i = len_to_sep(env) + 1;
	tmp = ft_calloc(ft_strlen(&env[i]) + 1, sizeof(char *));
	if (!tmp)
	{
		ft_error(E_MA, NULL);
		exit(-1);
	}
	while (env[i])
		tmp[k++] = env[i++];
	tmp[k] = '\0';
	return (tmp);
}

char	*take_key(char *env)
{
	char	*tmp;
	int		len;
	int		i;

	i = -1;
	len = len_to_sep(env);
	tmp = ft_calloc(len + 1, sizeof(char *));
	if (!tmp)
	{
		ft_error(E_MA, NULL);
		exit(-1);
	}
	while (++i < len)
		tmp[i] = env[i];
	tmp[i] = '\0';
	return (tmp);
}

void	envp_init(t_minishell *shell, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (envp[len])
		len++;
	shell->envp = (char **) malloc(sizeof(char *) * (len + 1));
	while (envp[i])
	{
		ft_lstadd_back(&shell->env, \
		ft_lstnew((char *)take_key(envp[i]), \
		(char *)take_value(envp[i]), 0));
		shell->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	shell->envp[i] = NULL;
}
