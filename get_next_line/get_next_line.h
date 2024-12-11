/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:04 by rita              #+#    #+#             */
/*   Updated: 2024/12/11 15:08:03 by rita             ###   ########.fr       */
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
#  define BUFFER_SIZE 10
# endif

int		ft_strlen(char *str);
char	*get_next_line(int fd);
//void get_next_line(int fd);

char	*ft_strjoin(char *src1, char *src2);
char	*ft_substr(char *src, int start, int len);
// char	*ft_strchr(char *src, char target);

// will output 1/0 if target is found or not
int check_src(char *src, char target);

#endif