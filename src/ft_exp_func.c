/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:27:40 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/17 19:00:30 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	*ft_free_exp(char ***tmp, int j)
{
	j = 0;
	while ((*tmp)[j])
	{
		free((*tmp)[j]);
		j++;
	}
	free(*tmp);
	return (NULL);
}

int	ft_exp_func(char **ptr, t_general *data, int j, int i)
{
	char	**tmp;
	int		ret_val;

	ret_val = 0;
	while (ptr && ptr[i])
	{
		if (ft_errors_for_export(ptr[i], &ret_val) != 1)
		{
			if (ft_strchr(ptr[i], '=') != NULL)
				get_env(data, ptr[i]);
			if (ft_check_str(ptr[i], data) == 0)
			{
				tmp = data->exp;
				j = double_size(tmp);
				data->exp = malloc(sizeof(char *) * (j + 2));
				j = -1;
				while (tmp[++j])
					data->exp[j] = ft_strdup(tmp[j]);
				data->exp[j] = ft_epstrdup(ptr[i]);
				data->exp[j + 1] = ft_free_exp(&tmp, j);
			}
		}
		i++;
	}
	return (set_env_t_list(data, data->env), ret_val);
}
