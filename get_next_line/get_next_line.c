/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:01 by rita              #+#    #+#             */
/*   Updated: 2024/12/11 16:46:11 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_raw_line(int fd, char *remainder)
{
	char	*buffer_block;
	int		res_open;

	if (remainder && check_src(remainder, '\n'))
		return (remainder);
	buffer_block = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_block)
		return (NULL);
	res_open = 1;
	while (!check_src(remainder, '\n') && res_open != 0)
	{

		res_open = read(fd, buffer_block, BUFFER_SIZE);
	//// printf("\n%s\n", buffer_block);
		if (res_open == -1)
		{
			free(remainder);
			remainder = NULL;
			free(buffer_block);
			return (NULL);			
		}
		if (res_open == 0 && !remainder)
		{
			free(buffer_block);
			return (NULL);
		}
		buffer_block[res_open] = 0; // TODO what these line ?
		remainder = ft_strjoin(remainder, buffer_block);
		if (!remainder)
		{
			free(buffer_block);
			return (NULL);
		}
	}
	free(buffer_block);
	//// printf("\n%s", remainder);
	return (remainder);
}




char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*raw_line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	raw_line = get_raw_line(fd, remainder);
	if (!raw_line)
		return (NULL);
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
    close(fd);
	return (0);
}