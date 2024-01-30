/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:48:15 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/02 12:24:34 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char *raw)
{
	char	*clean;
	int		len;

	len = 0;
	while (raw[len] && raw[len] != '\n')
		len++;
	clean = ft_substr(raw, 0, len + 1);
	return (clean);
}

char	*get_rest(char *tmp)
{
	int		i;
	char	*s;

	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	s = ft_substr(tmp, i + 1, ft_strlenn(tmp) - i);
	if (!s[0])
	{
		free(s);
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	else
		free(tmp);
	return (s);
}

int	ft_check_n(char *s, int c)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *tmp)
{
	char		*buffer;
	int			nb_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	nb_read = 1;
	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (ft_check_n(tmp, '\n') || nb_read < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	if (!tmp)
		tmp = ft_calloc(1, sizeof(char));
	if (!tmp)
		return (NULL);
	tmp = ft_read(fd, tmp);
	if (!tmp)
		return (NULL);
	line = ft_clean(tmp);
	if (!line[0])
	{
		free(line);
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp = get_rest(tmp);
	return (line);
}
