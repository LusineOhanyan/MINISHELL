/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_varables.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:40:41 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/21 16:07:27 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

size_t	arr_double_len(char	**arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

// TODO this function cuting NULL arguments from argv after dollar replacment

char	**cut_nulls(char **argv, int size)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = ft_calloc(sizeof(char *), (size + 1));
	while (i < size)
	{
		if (argv[i] != NULL)
			result[j++] = argv[i];
		i++;
	}
	i = 0;
	free(argv);
	return (result);
}

// TODO unused func

void	replace_dollar_varables_for_heredoc(t_general *g_data, int i)
{
	t_red	*temp;

	temp = g_data->pipes[i].head_red;
	while (temp)
	{
		if (temp->flag != HEREDOC)
			temp->pathname = process_dollar_sign_and_quotes
				(temp->pathname, g_data);
		else
			temp->pathname = remove_qutoes
				(temp->pathname, &temp->expand_mode_heredoc);
		temp = temp->next;
	}
}

// TODO export a="ls -a" this case dont working

int	replace_dollar_varables(t_general *g_data, int i)
{
	int		j;
	int		index;

	j = 0;
	index = 0;
	if (g_data->pipes[i].argv)
	{
		while (g_data->pipes[i].argv[j])
		{
			g_data->pipes[i].argv[j] = process_dollar_sign_and_quotes
				(g_data->pipes[i].argv[j], g_data);
			if (g_signal_notifire == SPLITE
				&& *g_data->pipes[i].argv[j] == '\0')
			{
				free(g_data->pipes[i].argv[j]);
				g_data->pipes[i].argv[j] = NULL;
				g_signal_notifire = NO_SPLITE;
			}
			j++;
		}
		g_data->pipes[i].argv = cut_nulls(g_data->pipes[i].argv, j);
	}
	replace_dollar_varables_for_heredoc(g_data, i);
	return (0);
}
