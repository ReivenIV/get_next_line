/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:01 by rita              #+#    #+#             */
/*   Updated: 2024/12/11 15:07:35 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_raw_line(int fd, char *remainder)
{
	char	*buffer_block;
	int		res_open;

	//! is these condition necesary ?? 
	if (remainder && check_src(remainder, '\n'))
		return (remainder);
	buffer_block = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_block)
		return (NULL);
	res_open = 1;
	while (!check_src(remainder, '\n') && res_open != 0)
	{
		res_open = read(fd, buffer_block, BUFFER_SIZE);
		if (res_open == -1)
			return (free(remainder), remainder = NULL, free(buffer_block), NULL);
		if (res_open == 0 && !remainder)
			return (free(buffer_block), NULL);
		buffer_block[res_open] = 0; // TODO what these line ?
		remainder = ft_strjoin(remainder, buffer_block);
		if (!remainder)
			return (free(buffer_block), NULL);
	}
	free(buffer_block);
	return (remainder);
}

//! Just for testing 
static char	*ft_strdup(char *str)
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


char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*raw_line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	raw_line = get_raw_line(fd, remainder);
	if (!raw_line)
		return (NULL);
	printf("%s", raw_line);
	// next_line = clean_raw_line(raw_line);
	// remainder = update_remainder(raw_line);
	// return (next_line);
	char *test = ft_strdup("lorem");

	return (test);
}
int	main(void)
{
	char	*raw_line;
	int		i = 1;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	
	raw_line = get_next_line(fd);
	free(raw_line);
	return (0);
}