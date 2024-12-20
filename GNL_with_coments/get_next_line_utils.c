/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwebe-ir <fwebe-ir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:47 by rita              #+#    #+#             */
/*   Updated: 2024/12/17 12:42:32 by fwebe-ir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// * Will count the length of a string
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

// * Will check if target(\n) is in src. Returns:  TRUE/FALSE  1/0
// * will be used to check buffer_blocks.
// ex : "\nHello", '\n' => 1
// ex : "Hello", 'z' => 0
int check_src(char *src, char target)
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

// * will be used to join buffer_blocks in the projects
// Will join 2 strings.
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
	return (free(src1), src1= NULL, str);
}

// * will be used to clean strings before/after the "\n".
// will output from a "src", "star", "len" one string
// ex: "Hello,\nWorld!", 0, 7 = > "Hello,\n"
// ex: "Hello,\nWorld!", 7, 5 = > "World"  
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
