/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:21:42 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 18:19:49 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_builtin(char *argv_0)
{
	if (ft_strncmp(argv_0, "echo", 4) == 0
		|| ft_strncmp(argv_0, "pwd", 3) == 0
		|| ft_strncmp(argv_0, "cd", 2) == 0
		|| ft_strncmp(argv_0, "env", 3) == 0
		|| ft_strncmp(argv_0, "export", 6) == 0
		|| ft_strncmp(argv_0, "unset", 5) == 0
		|| ft_strncmp(argv_0, "exit", 4) == 0)
		return (1);
	return (0);
}

int	builtin(t_general *g_data, char **argv, int i)
{
	if (ft_strcmp(*argv, "echo") == 0)
		return (ft_echo(argv + 1, g_data->pipes[i].fd_out));
	else if (ft_strcmp(*argv, "pwd") == 0)
		ft_pwd(g_data->pipes[i].fd_out);
	else if (ft_strcmp(*argv, "cd") == 0)
		return (ft_cd(argv, g_data));
	else if (ft_strcmp(*argv, "env") == 0)
		return (ft_env(g_data, g_data->pipes[i].fd_out));
	else if (ft_strcmp(*argv, "export") == 0)
		return (ft_export(g_data, (argv), g_data->pipes[i].fd_out));
	else if (ft_strcmp(*argv, "unset") == 0)
		return (ft_unset(g_data, (argv)));
	else if (ft_strcmp(*argv, "exit") == 0)
		return (ft_exit(argv, g_data->head_env));
	return (0);
}

void	ft_malloc_for_env(t_general *g_data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	g_data->env = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	while (env[i])
	{
		g_data->env[i] = ft_strdup(env[i]);
		i++;
	}	
	g_data->env[i] = NULL;
}
