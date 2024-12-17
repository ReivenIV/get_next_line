/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:47 by rita              #+#    #+#             */
/*   Updated: 2024/12/17 13:13:13 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (-1);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		str_len;
	char	*dup;

	i = 0;
	str_len = ft_strlen(str);
	dup = (char *)malloc(str_len * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	while (i < str_len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	check_src(char *src, char target)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
	{
		if (src[i] == target)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *src1, char *src2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!src1)
		src1 = ft_strdup("");
	str = malloc((ft_strlen(src1) + ft_strlen(src2) + 1) * sizeof(char));
	if (str == NULL)
		return (free(src1), src1 = NULL, NULL);
	i = 0;
	while (src1[i] != '\0')
	{
		str[i] = src1[i];
		i++;
	}
	j = 0;
	while (src2[j] != '\0')
	{
		str[i + j] = src2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(src1), src1 = NULL, str);
}

char	*ft_substr(char *src, int start, int len)
{
	int		i;
	int		src_len;
	char	*cleaned_str;

	if (src == NULL)
		return (NULL);
	src_len = ft_strlen(src);
	if (start > src_len)
		return (NULL);
	cleaned_str = malloc((len + 1) * sizeof(char));
	if (cleaned_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && src[start + i] != '\0')
	{
		cleaned_str[i] = src[start + i];
		i++;
	}
	cleaned_str[i] = '\0';
	return (cleaned_str);
}
