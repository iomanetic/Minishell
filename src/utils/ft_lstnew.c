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

char	*return_filename(t_minishell *shell)
{
	char	*name;
	char	*numb;

	numb = ft_itoa(shell->here_count);
	name = ft_strjoin(TMP_PATH, numb);
	shell->here_count++;
	free(numb);
	return (name);
}

t_heredoc	*ft_newheredoc(char *name)
{
	t_heredoc	*new_elem;

	new_elem = (t_heredoc *) malloc(sizeof(t_heredoc));
	new_elem->name = name;
	new_elem->fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (new_elem->fd == -1)
		return (NULL);
	new_elem->next = NULL;
	return (new_elem);
}

t_elem	*ft_lstnew(void *key, void *value, int key_t)
{
	t_elem	*node;

	node = (t_elem *) malloc(sizeof(t_elem));
	if (node == NULL)
		return (NULL);
	node->key = key;
	node->value = value;
	node->key_t = key_t;
	node->next = NULL;
	return (node);
}
