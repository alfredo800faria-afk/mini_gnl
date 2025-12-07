/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srusso-b <srusso-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:06:31 by srusso-b          #+#    #+#             */
/*   Updated: 2025/12/07 18:19:08 by srusso-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t   ft_strlen(const char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] && s[i] != '\n')
        i++;
    if (s[i] == '\n')
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *join;
    int     len;
    int     i;
    int     j;

    i = 0;
    j = -1;
    len = ft_strlen(s1) + ft_strlen(s2);
    join = (char *)malloc((len + 1) * sizeof(char));
    if (!join)
        return (NULL);
    while (s1 && s1[i])
    {
        join[i] = s1[i];
        i++;
    }
    while (s2[++j])
    {
        join[i++] = s2[j];
        if (s2[j] == '\n')
            break ;
    }
    join[i] = '\0';
    free(s1);
    return (join);
}