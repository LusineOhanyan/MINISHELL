/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:45:39 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/17 18:55:31 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	get_export(t_general *data)
{
	int	i;

	i = 0;
	while (data->env && data->env[i])
	{
		i++;
	}
	data->exp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (data->env && data->env[i])
	{	
		data->exp[i] = ft_epstrdup(data->env[i]);
		i++;
	}
	data->exp[i] = NULL;
	ft_sort_export(data, i);
}

void	ft_sort_export(t_general *data, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (j <= (i - 1))
	{
		if (data->exp[j + 1] && (data->exp[j][0] > data->exp[j + 1][0]))
		{
			tmp = data->exp[j];
			data->exp[j] = data->exp[j + 1];
			data->exp[j + 1] = tmp;
			j = 0;
		}
		else
			j++;
	}
}

int	double_size(char **ptr)
{
	int	k;

	k = 0;
	while (ptr && ptr[k])
		k++;
	return (k);
}

int	ft_export(t_general *data, char **ptr, int fd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ptr && ptr[i])
			i++;
	if (i < 2)
	{
		i = 0;
		while (data->exp[i])
		{
			ft_printf(fd, "declare -x ");
			ft_printf(fd, "%s\n", data->exp[i]);
			i++;
		}
	}
	else
	{
		i = 1;
		return (ft_sort_export(data, double_size(data->exp)),
			ft_exp_func(ptr, data, j, i));
	}
	return (0);
}

void	get_env(t_general *data, char *str)
{
	int		i;
	char	**tmp;

	i = 0;
	if (ft_check_str1(str, data) == 0)
	{
		tmp = data->env;
		while (data->env && data->env[i])
			i++;
		data->env = malloc(sizeof(char *) * (i + 2));
		i = -1;
		while (tmp && tmp[++i])
			data->env[i] = ft_strdup(tmp[i]);
		data->env[i] = ft_strdup1(str);
		data->env[i + 1] = NULL;
		i = -1;
		while (tmp[++i])
			free(tmp[i]);
		free(tmp);
	}
}
