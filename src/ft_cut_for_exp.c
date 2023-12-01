/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_for_exp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:46:39 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/16 23:25:32 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_cut_for_exp(t_general *data, char *tmp, char *str, int sign)
{
	int		j;
	char	*ptr;
	int		i;

	i = 0;
	ptr = 0;
	while (data->exp[i])
	{
		j = 0;
		while (data->exp[i][j] && data->exp[i][j] != '=')
			j++;
		ptr = ft_substr(data->exp[i], 0, j);
		if (ft_strcmp(ptr, tmp) == 0)
		{
			if (str[sign] && str[sign] == '+')
				data->exp[i] = ft_strjoin1(data->exp[i], &str[sign + 2]);
			else if (str[sign] == '=')
				ft_new_malloc(str, data->exp, i, 1);
			free(ptr);
			return (1);
		}
		free(ptr);
		i++;
	}
	return (0);
}
