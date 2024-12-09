/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:47 by rita              #+#    #+#             */
/*   Updated: 2024/12/11 17:24:37 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Will count the length of a string
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

// if target found will output the string after the target onwards
// ex : "\nHello", '\n' => "Hello"
// ex : "Hello", 'z' => NULL
// char	*ft_strchr(char *src, char target)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i] != '\0')
// 	{
// 		if (src[i] == (unsigned char)target)
// 			return (&src[i]);
// 		i++;
// 	}
// 	if (src[i] == target)
// 		return (&src[i]);
// 	return (NULL);
// }

// Will check if target is in src. Returns:  TRUE/FALSE  1/0
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

// Will check buffers and if !src1 we return """src1[0] = '\0';""" 
// R: first call into GNL will be always empty.
// static char	*fix_join(char *src1, char *src2)
// {
// 	if (!src2)
// 		return (NULL);
// 	if (!src1)
// 	{
// 		src1 = malloc(1 * sizeof(char));
// 		if (!src1)
// 			return (NULL);
// 		src1[0] = "";
// 	}
// 	return (src1);
// }

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

// Will join 2 strings.
char	*ft_strjoin(char *src1, char *src2)
{
	char	*str;
	size_t	i;
	size_t	j;

	// printf("src1 = %s\n",src1);
	// printf("src2 = %s\n",src2);

	if (!src1)
		src1 = ft_strdup("");
	str = malloc((ft_strlen(src1) + ft_strlen(src2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
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
	free(src1);
	return (str);
}

// will output from a "src", "star", "len" one string
// ex: "Hello,\nWorld!", 7, 5 = > "World"
// ex: "Hello, World!", 7, 50 = > "World!"
// ex: "Hello, World!", 70, 5 = > ""
// R : ""if (start >= src_len) return (ft_strdup(""));"" is not in the function 
char	*ft_substr(char *src, int start, int len)
{
	int		i;
	int		src_len;
	char	*str;

	if (src == NULL)
		return (NULL);
	src_len = ft_strlen(src);
	if (start + len > src_len)
		len = src_len - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && src[start + i] != '\0')
	{
		str[i] = src[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
