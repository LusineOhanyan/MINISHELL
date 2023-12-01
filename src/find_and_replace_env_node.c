/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_replace_env_node.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:11:29 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 12:53:52 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mini.h"

void	del_node(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	del_all_env(t_general *g_data)
{
	t_env	*prev;
	t_env	*temp;

	temp = g_data->head_env;
	prev = NULL;
	while (temp)
	{
		prev = temp;
		temp = temp->next;
		del_node(prev);
	}
	g_data->head_env = NULL;
}

int	find_and_replace_env_node(t_env *lst, t_env *new)
{
	while (lst)
	{
		if (ft_strcmp(lst->key, new->key) == 0)
		{
			if (ft_strcmp(lst->value, new->value) != 0)
			{
				free(lst->value);
				lst->value = ft_strdup(new->value);
			}
			del_node(new);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}
