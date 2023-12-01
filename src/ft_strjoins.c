/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:11:40 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 15:26:35 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

// char	*ft_strjoin_modifed(char *s1, char *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!s1 || !s2)
// 		return (0);
// 	while (s1[i] != '\0')
// 	{
// 		str[j] = s1[i];
// 		i++;
// 		j++;
// 	}
// 	i = 0;
// 	while (s2[i] != '\0')
// 	{
// 		str[j] = s2[i];
// 		i++;
// 		j++;
// 	}
// 	str[j] = '\0';
// 	free(s1);
// 	return (str);
// }

// char	*ft_strjoin1(char *s1, char *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
// 	if (!s1 || !s2)
// 		return (0);
// 	while (s1[i] != '\0')
// 	{
// 		if (s1[i] && s1[i] == '\"' && s1[i - 1] != '=')
// 			i++;
// 		if (s1[i])
// 		{
// 			str[j] = s1[i];
// 			j++;
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	while (s2[i] != '\0')
// 	{
// 		if (s2[i] == '\"')
// 			i++;
// 		else
// 		{
// 			str[j] = s2[i];
// 			i++;
// 			j++;
// 		}
// 	}
// 	str[j] = '\"';
// 	str[j + 1] = '\0';
// 	free(s1);
// 	s1 = NULL;
// 	return (str);
// }

// char	*ft_strjoin_for_env(char *s1, char *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!s1 || !s2)
// 		return (0);
// 	while (s1[i] != '\0')
// 	{
// 		if (s1[i] == '\"' || s1[i] == '\'')
// 			i++;
// 		else
// 		{
// 			str[j] = s1[i];
// 			i++;
// 			j++;
// 		}
// 	}
// 	i = 0;
// 	while (s2[i] != '\0')
// 	{
// 		if (s2[i] == '\"' || s2[i] == '\'')
// 			i++;
// 		else
// 		{
// 			str[j] = s2[i];
// 			i++;
// 			j++;
// 		}
// 	}
// 	str[j] = '\0';
// 	free(s1);
// 	return (str);
// }
