/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_modified.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:23:55 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/16 23:24:16 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

unsigned long long int	ft_atoi_modifed(const char *str)
{
	int						index;
	int						sign;
	unsigned long long int	value;

	index = 0;
	sign = 1;
	value = 0;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -sign;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		value = value * 10 + str[index] - '0';
		index++;
	}
	return (sign * value);
}
