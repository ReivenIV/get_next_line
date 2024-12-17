/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:01 by rita              #+#    #+#             */
/*   Updated: 2024/12/17 13:16:12 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_raw_line(int fd, char *stash)
{
	char	*buffer_block;
	int		res_open;

	if (stash && check_src(stash, '\n'))
		return (stash);
	buffer_block = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_block)
		return (NULL);
	res_open = 1;
	while (!check_src(stash, '\n') && res_open != 0)
	{
		res_open = read(fd, buffer_block, BUFFER_SIZE);
		if (res_open == -1)
			return (free(buffer_block), NULL);
		if (res_open == 0 && (!stash || stash[0] == '\0'))
			return (free(buffer_block), NULL);
		buffer_block[res_open] = '\0';
		stash = ft_strjoin(stash, buffer_block);
		if (!stash)
			return (stash = NULL, NULL);
	}
	free(buffer_block);
	return (stash);
}

char	*create_new_line(char *raw_line)
{
	size_t	i;
	char	*new_line;

	i = 0;
	while (raw_line[i] != '\n' && raw_line[i] != '\0')
		i++;
	if (raw_line[i] == '\n')
		i++;
	new_line = ft_substr(raw_line, 0, i);
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*update_stash(char *raw_line)
{
	size_t	i;
	size_t	raw_line_len;
	char	*new_stash;

	if (!raw_line)
		return (NULL);
	raw_line_len = ft_strlen(raw_line);
	i = 0;
	while (raw_line[i] != '\n' && raw_line[i] != '\0')
		i++;
	if (raw_line[i] != '\n')
		i++;
	new_stash = ft_substr(raw_line, i + 1, (raw_line_len - i - 1));
	if (new_stash && new_stash[0] == '\0')
	{
		free(new_stash);
		new_stash = NULL;
	}
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*raw_line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	raw_line = get_raw_line(fd, stash[fd]);
	if (!raw_line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	next_line = create_new_line(raw_line);
	stash[fd] = update_stash(raw_line);
	free(raw_line);
	raw_line = NULL;
	return (next_line);
}
