/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:57:49 by shechong          #+#    #+#             */
/*   Updated: 2023/05/22 16:21:59 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_get_line(char *str);
char	*ft_new_str(char *str);
char	*ft_read_str(int fd, char *left_str);
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dest, char *src, size_t dest_size);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
