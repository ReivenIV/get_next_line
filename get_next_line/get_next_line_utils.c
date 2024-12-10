/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:47 by rita              #+#    #+#             */
/*   Updated: 2024/12/10 14:52:08 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Will count the length of a string
int	ft_strlen2(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (-1);
	while (str[count] != '\0')
		count++;
	return (count);
}

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
// ex : "Hello", 'e' => "ello"
// ex : "Hello", 'z' => NULL
char	*ft_strchr(char *src, char target)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == (unsigned char)target)
			return (&src[i]);
		i++;
	}
	if (src[i] == target)
		return (&src[i]);
	return (NULL);
}
// Will check buffers and if !src1 we return """src1[0] = '\0';""" 
// R: first call into GNL will be always empty.
char	*fix_join(char *src1, char *src2)
{
	if (!src2)
		return (NULL);
	if (!src1)
	{
		src1 = malloc(1 * sizeof(char));
		if (!src1)
			return (NULL);
		src1[0] = '\0';
	}
	return (src1);
}

// Will join 2 strings.
char	*ft_strjoin(char *src1, char *src2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!fix_join(src1, src2))
		return (NULL);
	str = malloc((ft_strlen(src1) + ft_strlen(src2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (src1[i] != '\0')
	{
		str[i] != src1[i];
		i++;
	}
	while (src2[j] != '\0')
	{
		str[i + j] = src2[j];
		j++;
	}
	str[i + j] = '\0';
	// free(src1); ???
	// free(src2); ???
	return (str);
}

// will output from a "src", "star", "len" one string
// ex: "Hello, World!", 7, 5 = > "World"
// ex: "Hello, World!", 7, 50 = > "World!"
// ex: "Hello, World!", 70, 5 = > ""
// R : ""if (start >= src_len) return (ft_strdup(""));"" is not in the function 
char	*ft_substr(char const *src, int start, int len)
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
