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
#ifndef DEFINES_H
# define DEFINES_H

# ifndef SHELL_MESSAGES
#  define SHELL_MESSAGES

#  define PROMPT "minishell_1.0$> "
#  define E_UQT "minishell: unclosed quetos type `"
#  define E_MA "minishell: malloc failed"
#  define E_US "minishell: undefined symbol `"
#  define E_SE  "minishell: syntax error"
#  define E_CNF "minishell: No such file or directory"
#  define E_PIE "minishell: pipe init error"
#  define E_SAE "minishell: signal accept error"
#  define E_OF "minishell: open file failed"
#  define E_AC "minishell: error check path"
#  define E_DI "minishell: error dup fd"
#  define E_WP "minishell: error wait process"
#  define E_CFD "minishell: error close fd"
#  define E_FI "minishell: error fork init"
#  define E_HE "minishell: heredoc error"
#  define E_WE "minishell: write error"
#  define E_ESE "minishell: export syntx error `"
#  define E_UE "minishell: unset syntx error `"
# endif

# ifndef TOKENS_LIST
#  define TOKENS_LIST

#  define SEP 0
#  define WORD 1
#  define PIPE 2
#  define DOLLAR 3
#  define SING_QUO 4
#  define DOUB_QUO 5
#  define REDIR_OUT 6
#  define REDIR_IN 7
#  define DREDIR_OUT 8
#  define HEREDOC 9
# endif

# ifndef VALUES
#  define VALUES
#  define TERMINATED 130
#  define CMD_NOT_FOUND 127
#  define TMP_PATH	"/tmp/.heredoc"
#  define FALSE 0
#  define TRUE 1
# endif

#endif
