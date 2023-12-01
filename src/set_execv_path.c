/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_execv_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:42:54 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/16 23:43:07 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	set_execv_path(t_general *g_data, t_pipe *pipe)
{
	char	**paths;
	int		i;
	char	*fullpath;

	i = -1;
	if (pipe->cmd_name[0] == '\0')
	{
		ft_printf(2, "minishell: %s: command not found\n", pipe->cmd_name);
		exit(127);
	}
	paths = ft_split(get_value_by_key("PATH", g_data->head_env), ':');
	while (paths[++i])
	{
		fullpath = ft_strjoin(paths[i], "/");
		fullpath = ft_strjoin_free_first_arg(fullpath, pipe->cmd_name);
		if (access(fullpath, F_OK) != -1)
		{
			pipe->cmd_name = fullpath;
			free_double_array((void ***)&paths);
			return ;
		}
	}
	ft_printf(2, "minishell: %s: command not found\n", pipe->cmd_name);
	free_double_array((void ***)&paths);
	exit(127);
}

	// if (access(pipe->cmd_name, F_OK) != -1)
	// 	return (free_double_array((void ***)&paths));