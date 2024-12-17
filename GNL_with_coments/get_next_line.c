/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwebe-ir <fwebe-ir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:01 by rita              #+#    #+#             */
/*   Updated: 2024/12/17 12:37:16 by fwebe-ir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// TODO reduce function to 25 lines.
// res_open = -1(problem) || 0(EOF End Of File) || n(amount of bytes readed)
char	*get_raw_line(int fd, char *stash)
{
	char	*buffer_block;
	int		res_open;

	// If in stash there is '\n' return stash
	if (stash && check_src(stash, '\n'))
		return (stash);
	buffer_block = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_block)
		return (NULL);
	res_open = 1;

	// loop till in the buffer you find an '\n' & res open is not 0
	while (!check_src(stash, '\n') && res_open != 0)
	{
		res_open = read(fd, buffer_block, BUFFER_SIZE);
		// if there is an error while opening/reading the file
		if (res_open == -1)
		{
			free(buffer_block);
			return (NULL);
		}
		// if we reached the end of the file
		if (res_open == 0 && (!stash || stash[0] == '\0'))
		{
			free(buffer_block);
			return (NULL);
		}
		// if res_open read caracters and there is no problem  
		buffer_block[res_open] = '\0';
		// we join every buffer_block
		stash = ft_strjoin(stash, buffer_block);
		if (!stash)
		{
			stash = NULL;
			return (NULL);
		}
	}
	// when there is at least one "\n" in the buffer we block the loop
	// we free every buffer_block
	free(buffer_block);
	// We return the stash with all the blocks we have now our raw_line
	return (stash);
}

// the function will receive ex: "Hello, \n test" output: "Hello, ".
// expected output = stash + cleaned_raw_line + \0.
// TODO test function might not work nl maybe need a '\0'.
char	*create_new_line(char *raw_line)
{
	size_t	i;
	char	*new_line;

	i = 0;
	// we counts caracters till end of file or \n
	while (raw_line[i] != '\n' && raw_line[i] != '\0')
		i++;
	// if next caracter is \n we keep it in count
	if (raw_line[i] == '\n')
		i++;
	// We allocate data to new_line
	new_line = ft_substr(raw_line, 0, i);
	if (!new_line)
		return (NULL);
	return (new_line);
}
// Here we update the stash for the next call to GNL
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
	// When we know the size of i and rl_len we update the stash 
	// with data after the "\n"
	new_stash = ft_substr(raw_line, i + 1, (raw_line_len - i - 1));
	if (new_stash && new_stash[0] == '\0')
	{
		free(new_stash);
		new_stash = NULL;
	}
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
	// ex : "Hello, \n test"
	raw_line = get_raw_line(fd, stash);
	if (!raw_line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	// ex: "Hello, \n"
	next_line = create_new_line(raw_line);
	// ex: "" test""
	stash = update_stash(raw_line);
	free(raw_line);
	raw_line = NULL;
	return (next_line);
}

// * Test just to print first line of the file
// * Interesting for the begining of the proyect
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

// * Test to print all the file.  
// int main(void)
// {
//     char *str;
//     int fd = open("read_error.txt", O_RDONLY);
    
//     if (fd < 0)
//         perror("Erreur lors de l'ouverture");
//     while ((str = get_next_line(fd)) != NULL) {
//         printf("%s", str);
//         free(str);
//     }
//     close(fd);
//     return (0);
// }