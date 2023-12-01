/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:33:21 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/17 20:06:15 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_cd(char **ptr, t_general *data)
{
	int		i;
	int		j;
	int		sign;

	i = 0;
	j = 0;
	sign = 0;
	if (ptr[i + 1] == NULL)
	{
		if (get_value_by_key("HOME", data->head_env) == NULL)
			return (ft_printf(2, "minishell: cd: HOME not set\n"), 1);
		else
		{
			chdir(get_value_by_key("HOME", data->head_env));
			return (0);
		}
	}
	else if (chdir(ptr[i + 1]) < 0)
	{
		ft_printf(2, "minishell: cd: %s: %s\n", ptr[i + 1], strerror(errno));
		return (1);
	}
	return (0);
}
