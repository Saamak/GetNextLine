/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:49:13 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/02 11:49:27 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_clean(char *raw);
int		ft_strlenn(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_n(char *s, int c);
char	*get_next_line(int fd);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char *s, int start, int len);

#endif
