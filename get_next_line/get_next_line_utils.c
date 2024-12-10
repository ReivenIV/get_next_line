/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:47 by rita              #+#    #+#             */
/*   Updated: 2024/12/10 14:16:23 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO strlen		DONE
// TODO strchr		DONE
// TODO strjoin		DONE
// TODO substr		DONE

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

// Will join 2 strings.
char	*ft_strjoin(char const *src1, char const *src2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!src1)
		src1 = "";
	if (!src2)
		src2 = "";
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
	while (src2[i] != '\0')
	{
		str[i + j] = src2[j];
		j++;
	}
	str[i + j] = '\0';
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
