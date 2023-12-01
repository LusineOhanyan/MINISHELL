/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:31:28 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/17 15:55:02 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup1(char *s1)
{
	char	*str;
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	j = -1;
	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	while (s1 && s1[i] != '\0')
	{
		if (s1[i] == '+' && s1[i + 1] && s1[i + 1] == '=' && flag == 0)
		{
			flag += 1;
			i++;
		}
		else
		{
			str[++j] = s1[i];
			i++;
		}
	}
	str[j + 1] = '\0';
	return (str);
}

char	*ft_strjoin_modifed(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] && s1[i] == '\"' && s1[i - 1] != '=')
			i++;
		if (s1[i])
			str[j++] = s1[i++];
	}
	ft_help_func(s2, &s1, j, &str);
	return (str);
}

char	*ft_strjoin_for_env(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == '\"' || s1[i] == '\'')
			i++;
		else
		{
			str[j] = s1[i];
			i++;
			j++;
		}
	}
	ft_help_func1(s2, &s1, j, &str);
	return (str);
}
