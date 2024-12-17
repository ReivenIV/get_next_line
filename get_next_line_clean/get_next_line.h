/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwebe-ir <fwebe-ir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:04 by rita              #+#    #+#             */
/*   Updated: 2024/12/17 12:47:27 by fwebe-ir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h> //! to erase (just for testing mode)
# include <stdio.h> //! to erase (just for testing mode)

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// if Bsize is bigger than 1M we block it at 1M
# if BUFFER_SIZE > 1000000
#	undef BUFFER_SIZE
#	define BUFFER_SIZE 1000000
# endif


int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *src1, char *src2);
char	*ft_substr(char *src, int start, int len);
int check_src(char *src, char target);

#endif