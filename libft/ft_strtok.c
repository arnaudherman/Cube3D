/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:05:18 by bat               #+#    #+#             */
/*   Updated: 2023/09/12 16:55:06 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *my_strtok(char *str, const char *delim) 
{
    static char *lastToken = NULL;
    if (str != NULL) 
    {
        lastToken = str;
    } 
    else 
    {
        if (lastToken == NULL) 
        {
            return NULL;
        }
    }
    
    char *tokenStart = lastToken;
    char *tokenEnd;

    // Ignore leading delimiters
    while (*lastToken != '\0' && strchr(delim, *lastToken) != NULL)
    {
        lastToken++;
    }
    
    if (*lastToken == '\0')
    {
        lastToken = NULL; // No more tokens
        return NULL;
    }
    
    tokenEnd = lastToken;

    // Find the end of the token
    while (*tokenEnd != '\0' && strchr(delim, *tokenEnd) == NULL)
    {
        tokenEnd++;
    }

    if (*tokenEnd != '\0') 
    {
        *tokenEnd = '\0'; // Null-terminate the token
        lastToken = tokenEnd + 1;
    }
    else 
    {
        lastToken = NULL; // No more tokens after this one
    }
    
    return tokenStart;
}

/*
int main() {
    char str[] = "This is, a test, string";
    const char delim[] = ", ";
    
    char *token = my_strtok(str, delim);
    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = my_strtok(NULL, delim);
    }

    return 0;
}

char	*ft_strtok(char *str, const char *delim)
{
    uint8_t	hash[256];
    int		i;
    
    NULL_CHECK(!str);
    if (!delim)
        return (ft_strdup(str));
    ft_bzero(&hash, 256);
    i = -1;
    while (delim[++i])
        hash[(int)delim[i]] = 1;
    i = -1;
    while (str[++i])
	{
        if (hash[(int)str[i]])
            return (ft_strndup(str, i));
    }
    return (ft_strdup(str));
}
*/
