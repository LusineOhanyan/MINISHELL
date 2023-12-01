/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:26:14 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 18:13:29 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_env(t_general *data, int fd)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		ft_printf(fd, "%s\n", data->env[i]);
		i++;
	}
	return (0);
}

void	ft_check_env(int k, t_general *data, char **tmp)
{
	int	j;
	int	l;

	j = 0;
	l = 0;
	while (tmp && tmp[j])
	{
		if (j == k)
			j++;
		else
		{
			data->env[l] = ft_strdup(tmp[j]);
			j++;
			l++;
		}
	}
	data->env[l] = NULL;
}
