/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_for_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:14:15 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 19:14:44 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_check_str2(char *str, char **exp);

void	ft_unset_for_env(t_general *data, char *ptr)
{
	int		j;
	char	**tmp;
	int		k;
	int		l;

	k = 0;
	l = 0;
	j = 0;
	k = ft_check_str2(ptr, data->env);
	if (k >= 0)
	{
		tmp = data->env;
		while (tmp[j])
			j++;
		data->env = malloc(sizeof(char *) * j);
		j = 0;
		ft_check_env(k, data, tmp);
		j = -1;
		while (tmp[++j])
		{
			free(tmp[j]);
			tmp[j] = NULL;
		}
		free(tmp);
	}
}
