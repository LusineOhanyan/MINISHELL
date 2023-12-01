/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:42:39 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/17 20:31:58 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_free(char **ptr, char **tmp, int *i)
{
	int	len;

	if (ep_strlen(*ptr) <= ep_strlen(*tmp))
		len = ep_strlen(*tmp);
	else
		len = ep_strlen(*ptr);
	if (ft_strncmp(*ptr, *tmp, len) == 0)
	{
		free(*tmp);
		*tmp = 0;
		free(*ptr);
		*ptr = 0;
		return (*i);
	}
	return (-1);
}

int	ft_check_str2(char *str, char **exp)
{
	int		i;
	char	*ptr;
	char	*tmp;
	int		j;

	i = 0;
	while (str && str[i] && str[i] != '=')
		i++;
	tmp = ft_substr(str, 0, i);
	i = -1;
	while (exp[++i])
	{
		j = 0;
		while (exp[i][j] && exp[i][j] != '=')
			j++;
		ptr = ft_substr(exp[i], 0, j);
		j = ft_free(&ptr, &tmp, &i);
		free(ptr);
		if (j > -1)
		{
			free(tmp);
			return (j);
		}
	}
	return (free(tmp), -1);
}

void	ft_check_exp(int k, t_general *data)
{
	int		j;
	int		l;
	char	**tmp;

	j = 0;
	l = -1;
	if (k >= 0)
	{
		tmp = data->exp;
		while (tmp[j])
			j++;
		data->exp = malloc(sizeof(char *) * j);
		j = 0;
		while (tmp && tmp[j])
		{
			if (j == k)
				j++;
			else
				data->exp[++l] = ft_strdup(tmp[j++]);
		}
		data->exp[l + 1] = NULL;
		ft_free_exp(&tmp, j);
	}
}

static int	is_with_equal(char *ptr, int *ret_val)
{
	if (ft_strrchr(ptr, '=') != 0)
	{
		ft_printf(2, "Minishell: %s: not a valid identifier\n", ptr);
		*ret_val = 1;
		return (1);
	}
	return (0);
}	

int	ft_unset(t_general *data, char **ptr)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		ret_val;

	i = 0;
	k = 0;
	j = 0;
	while (ptr && ptr[i])
	{
		if (!is_with_equal(ptr[i], &ret_val)
			&& ft_errors_for_export(ptr[i], &ret_val) != 1)
		{
			ft_unset_for_env(data, ptr[i]);
			l = 0;
			k = ft_check_str2(ptr[i], data->exp);
			ft_check_exp(k, data);
			del_all_env(data);
			set_env_t_list(data, data->env);
		}
		i++;
	}
	return (ret_val);
}
