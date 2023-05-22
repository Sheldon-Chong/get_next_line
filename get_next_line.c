/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:05:47 by shechong          #+#    #+#             */
/*   Updated: 2023/05/22 14:34:34 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_and_return(void *var, void *ret)
{
	free(var);
	return (ret);
}

char	*get_current_line(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_line = malloc(i + 2);
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, str, i + 2);
	return (new_line);
}

char	*remove_current_line(char *static_buffer)
{
	int		i;
	char	*new_str;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
		return (free_and_return(static_buffer, NULL));
	new_str = malloc(ft_strlen(static_buffer) - i + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, static_buffer + i + 1, ft_strlen(static_buffer));
	return (free_and_return(static_buffer, new_str));
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*static_buffer;
	char		*buffer;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(static_buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_and_return(buffer, NULL));
		buffer[read_bytes] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	ret = get_current_line(static_buffer);
	static_buffer = remove_current_line(static_buffer);
	return (free_and_return(buffer, ret));
}
