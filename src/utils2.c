/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:33:50 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 20:34:11 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_help_func(char *s2, char **s1, int j, char **str)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s2[i] == '\"')
			i++;
		else
			(*str)[j++] = s2[i++];
	}
	(*str)[j] = '\"';
	(*str)[j + 1] = '\0';
	free(*s1);
	(*s1) = NULL;
}

void	ft_help_func1(char *s2, char **s1, int j, char **str)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s2[i] == '\"' || s2[i] == '\'')
			i++;
		else
		{
			(*str)[j] = s2[i];
			i++;
			j++;
		}
	}
	(*str)[j] = '\0';
	free(*s1);
}

char	*ft_sign(char *s1, int *i, int *j, int *flag)
{
	int		plus;
	char	*str;

	plus = 0;
	str = (char *)malloc((ft_strlen(s1) + 3) * sizeof(char));
	while (s1 && s1[*i] != '\0')
	{
		if (s1[*i] == '=' && *flag == 0)
		{
			if (*i != 0 && s1[(*i) - 1] == '+')
				*j -= 1;
			*flag = 1;
			str[(*j)++] = s1[(*i)++];
			str[(*j)++] = '\"';
		}
		else
		{
			if (*i != 0 && s1[(*i) - 1] == '+' && plus == 0)
				(*j)--;
			str[(*j)++] = s1[(*i)++];
			plus = 1;
		}
	}
	return (str);
}

char	*ft_epstrdup(char *s1)
{
	char	*str;
	int		i;
	int		j;
	int		flag;
	int		plus;

	i = 0;
	j = 0;
	flag = 0;
	plus = 0;
	if (!s1)
		return (NULL);
	str = ft_sign(s1, &i, &j, &flag);
	if (flag == 1 && s1[i - 1] != '\"')
	{
		str[j] = '\"';
		str[j + 1] = '\0';
	}
	else
		str[j] = '\0';
	return (str);
}
