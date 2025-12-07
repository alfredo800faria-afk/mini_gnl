/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:03:10 by srusso-b          #+#    #+#             */
/*   Updated: 2025/12/07 18:05:10 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char    *line;
    int     nline;
    int     i;
    int     j;

    if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
        return (NULL);
    line = '\0';
    nline = 0;
    while (!nline && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
    {
        line = ft_strjoin(line, buffer);
        i = 0;
        j = 0;
        while (buffer[i])
        {
            if (nline)
                buffer[j++] = buffer[i];
            if (buffer[i] == '\n')
                nline = 1;
            buffer[i++] = 0;
        }
    }    
    return (line);
}