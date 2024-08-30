/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:52:18 by olamrabt          #+#    #+#             */
/*   Updated: 2024/08/30 16:00:39 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_str(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i])
			count++;
		while (str[i] != '\0' && (str[i] != c))
			i++;
	}
	return (count);
}

int	len_str(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_allocated_str(const char *str, char c, t_data *data)
{
	char	*result;
	int		len_string;

	len_string = len_str(str, c);
	result = (char *)safe_alloc(&data->addr, (len_string + 1), sizeof(char));
	if (!result)
		return (NULL);
	result[len_string] = '\0';
	while (len_string--)
		result[len_string] = str[len_string];
	return (result);
}

char	**ft_split(char const *s, char c, t_data *data)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = (char **)safe_alloc(&data->addr, \
		(count_str(s, c) + 1), sizeof(char *));
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			result[i] = ft_allocated_str(s, c, data);
			if (!result[i])
				return (NULL);
			i++;
		}
		while (*s && (*s != c))
			s++;
	}
	result[i] = NULL;
	return (result);
}
