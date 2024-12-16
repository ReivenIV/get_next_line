/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:01 by rita              #+#    #+#             */
/*   Updated: 2024/12/16 15:54:32 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// TODO reduce function to 25 lines.
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
		{
			free(stash);
			stash = NULL;
			free(buffer_block);
			return (NULL);			
		}
		if (res_open == 0 && !stash)
		{
			free(buffer_block);
			return (NULL);
		}
		buffer_block[res_open] = 0; // TODO what these line ?
		stash = ft_strjoin(stash, buffer_block);
		if (!stash)
		{
			free(buffer_block);
			return (NULL);
		}
	}
	free(buffer_block);
	return (stash);
}

// expected output = stash + cleaned_raw_line + \0 
// TODO test function might not work nl maybe need a '\0'.
char	*create_new_line(char *stash, char *raw_line)
{
	size_t	i;
	//size_t	stash_len;
	char	*new_line;
	char	*cleaned_raw_line;

	i = 0;
	//stash_len = ft_strlen(stash);
	while (raw_line[i] != '\n' && raw_line[i] != '\0')
		i++;
	if (raw_line[i] != '\n')
		i++;
	// We clean raw_line
	cleaned_raw_line = ft_substr(raw_line, 0, i);
	if (!cleaned_raw_line)
		return (NULL);
	// We allocate data to new_line
	new_line = ft_strjoin(stash, cleaned_raw_line);
	if (!new_line)
		return (NULL);
	free(cleaned_raw_line);
	return (new_line);
}

char	*update_stash(char *raw_line)
{
	size_t	i;
	size_t	raw_line_len;
	char	*new_stash;
	
	if (!raw_line)
		return (free(raw_line), NULL);
	raw_line_len = ft_strlen(raw_line);
	i = 0;
	while (raw_line[i] != '\n' && raw_line[i] != '\0')
		i++;
	if (raw_line[i] != '\n')
		i++;
	new_stash = ft_substr(raw_line, i, (raw_line_len - i));
	free(raw_line);
	return (new_stash);
}

//* Main function
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*raw_line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	raw_line = get_raw_line(fd, stash);
	if (!raw_line)
		return (NULL);
	next_line = create_new_line(stash, raw_line);
	stash = update_stash(raw_line);
	return (next_line);
}
// int	main(void)
// {
// 	char	*raw_line;
// 	//int		i;
// 	int		fd;
	
// 	//i = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	raw_line = get_next_line(fd);
// 	printf("%s",raw_line);	
// 	free(raw_line);
//     close(fd);
// 	return (0);
// }