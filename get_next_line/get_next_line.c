/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:01 by rita              #+#    #+#             */
/*   Updated: 2024/12/10 17:40:35 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_raw_line(int fd, char *remainder)
{
	char	*buffer_block;
	int		res_open;

	//! is these condition necesary ?? 
	if (remainder && check_src(remainder, '\n') == 1);
		return (remainder);
	buffer_block = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_block)
		return (NULL);
	res_open = 1;
	while (check_src(remainder, '\n') == 1 && res_open != 0)
	{
		res_open = read(fd, buffer_block, BUFFER_SIZE);
		if (res_open == -1)
			return (free(remainder), remainder = NULL, free(buffer_block), NULL);
		if (res_open)
	}
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
	// next_line = clean_raw_line(raw_line);
	// remainder = update_remainder(raw_line);
	// return (next_line);
	char test[] = "lorem";
	return (test);
}
