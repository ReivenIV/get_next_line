/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:47 by rita              #+#    #+#             */
/*   Updated: 2024/12/10 12:45:19 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO strlen		DONE
// TODO strchr		DONE
// TODO strjoin
// TODO substr

#include "get_next_line_bonus.h"

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

