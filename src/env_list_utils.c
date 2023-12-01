/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:37:54 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 00:19:02 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mini.h"

t_env	*lst_env_last(t_env *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	lst_env_add(t_env **lst, t_env *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (find_and_replace_env_node(*lst, new) == 0)
	{
		lst_env_last(*lst)->next = new;
	}
}

t_env	*lst_env_new(void *key, void *value)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	if (node)
	{
		node->key = ft_strdup(key);
		node->value = ft_strdup(value);
		node->next = NULL;
		return (node);
	}
	return (NULL);
}
