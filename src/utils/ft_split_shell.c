/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 17:28:41 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_word(t_elem *token)
{
	t_elem	*tmp;
	int		i;

	i = 0;
	tmp = token;
	while (tmp)
	{
		if (!ft_istoken(tmp->key_t))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

char	*return_str(t_elem **tmp)
{
	char	*join;
	char	*f_free;

	join = ft_strdup("");
	f_free = join;
	while (*tmp && ft_istoken((*tmp)->key_t))
		*tmp = (*tmp)->next;
	if (!(*tmp))
	{
		free(join);
		return (NULL);
	}
	while (*tmp && !ft_istoken((*tmp)->key_t))
	{
		join = ft_strjoin(join, (char *)(*tmp)->value);
		free(f_free);
		f_free = join;
		*tmp = (*tmp)->next;
	}
	return (join);
}

char	**ft_split_shell(t_elem *token)
{
	char	**arr;
	t_elem	*tmp;
	int		i;

	arr = (char **) malloc(sizeof(char *) * (count_word(token) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	tmp = token;
	while (tmp)
	{
		arr[i] = return_str(&tmp);
		if (!arr[i])
			return (arr);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
