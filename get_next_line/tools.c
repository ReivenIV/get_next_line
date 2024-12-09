/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:47 by rita              #+#    #+#             */
/*   Updated: 2024/12/09 17:22:56 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO strlen		DONE
// TODO strchr
// TODO strjoin
// TODO substr

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
}
