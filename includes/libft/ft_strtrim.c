/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:40:52 by aozbek            #+#    #+#             */
/*   Updated: 2023/07/12 10:44:38 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	ft_control(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		else
		{
			i++;
		}
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*str;

	i = 0;
	start = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (0);
	while (s1[start] && ft_control(set, s1[start]) == 1)
		start++;
	while (len > start && ft_control(set, s1[len - 1]) == 1)
		len--;
	str = (char *)malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (0);
	while (start < len)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
