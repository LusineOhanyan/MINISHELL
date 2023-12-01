/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_for_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:23:10 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/11 19:11:31 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_cut_for_env(t_general *data, char *tmp, char *str, int sign)
{
	int		j;
	char	*ptr;
	int		i;

	i = 0;
	ptr = 0;
	while (data->env[i])
	{
		j = 0;
		while (data->env[i][j] && data->env[i][j] != '=')
			j++;
		ptr = ft_substr(data->env[i], 0, j);
		if (ft_strcmp(ptr, tmp) == 0)
		{
			if (str[sign] && str[sign] == '+')
				data->env[i] = ft_strjoin_for_env(data->env[i], &str[sign + 2]);
			else if (str[sign] == '=')
				ft_new_malloc1(str, data->env, i, 1);
			free(ptr);
			return (1);
		}
		free(ptr);
		i++;
	}
	return (0);
}
