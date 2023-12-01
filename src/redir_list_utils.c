/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:55:32 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 15:55:35 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_red	*lst_redir_last(t_red *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	lst_redir_add_back(t_red **lst, t_red *new)
{	
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_redir_last(*lst)->next = new;
}

t_red	*lst_redir_new(void *content, int flag_num)
{
	t_red	*node;

	node = (t_red *)malloc(sizeof(t_red));
	if (node)
	{
		node->expand_mode_heredoc = EXPAND_VAR;
		node->flag = flag_num;
		node->pathname = ft_strdup(content);
		node->heredoc_fd[0] = -1;
		node->heredoc_fd[1] = -1;
		node->next = NULL;
		return (node);
	}
	return (NULL);
}
