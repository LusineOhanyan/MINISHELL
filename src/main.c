/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:53:24 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 15:58:10 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	g_signal_notifire;

void	init_structs(t_general *g_data)
{
	g_data->pipes = malloc(sizeof(t_pipe)
			* (g_data->pipe_count));
}

void	set_env(t_general *g_data, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		;
	g_data->env = (char **)malloc((i + 1) * sizeof(char *));
	i = -1;
	while (env[++i])
		g_data->env[i] = ft_strdup(env[i]);
	g_data->env[i] = NULL;
}

void	general_init(t_general *g_data)
{
	g_data->head_env = NULL;
	g_data->pipe_count = 0;
	g_data->env = NULL;
	g_data->exp = NULL;
	g_data->line = NULL;
	g_data->exit_status = 0;
	g_data->pipes = NULL;
	g_data->parse_data.pipes = NULL;
}

void	init_prog(t_general	*g_data, char **env, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	general_init(g_data);
	set_env(g_data, env);
	set_env_t_list(g_data, env);
	get_export(g_data);
}

int	main(int argc, char **argv, char **env)
{
	t_general	g_data;

	init_prog(&g_data, env, argc, argv);
	while (free_general(&g_data))
	{
		g_signal_notifire = 0;
		handle_signals(INTERACTIVE_MODE);
		g_data.line = ft_readline("Minishell$ ");
		if (g_data.line == NULL && ft_printf(2, "Exit\n"))
			exit(ft_atoi(get_value_by_key("?", g_data.head_env)));
		if ((g_signal_notifire == 1 && exit_status_setter(&g_data.head_env, 1))
			|| *(g_data.line) == '\0')
			continue ;
		add_history(g_data.line);
		if (has_errors(g_data.line)
			&& exit_status_setter(&g_data.head_env, 258))
			continue ;
		split_by_pipes(&g_data, &g_data.parse_data);
		init_structs(&g_data);
		if (parsing(&g_data) != 0 && exit_status_setter(&g_data.head_env, 1))
			continue ;
		if (g_data.pipes[0].argv && g_data.pipes[0].argv[0])
			exit_status_setter(&g_data.head_env, execute(&g_data));
	}
	return (0);
}
