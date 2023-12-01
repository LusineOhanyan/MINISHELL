/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_for_execve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:58:11 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/21 17:58:30 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_for_execve(char *cmd, t_general *g_data, t_pipe *pipe)
{
	if (cmd[0] == '.' && cmd[1] == '\0')
	{
		ft_printf(2, "minishell: .: filename argument required\n\
.: usage: . filename [arguments]\n");
		exit (2);
	}
	if (!is_dir(pipe->cmd_name)
		&& (!is_path_abs_or_relative(pipe->cmd_name)
			|| !ft_strchr(pipe->cmd_name, '/')))
	{
		if (get_value_by_key("PATH", g_data->head_env))
			set_execv_path(g_data, pipe);
	}
	return (1);
}
