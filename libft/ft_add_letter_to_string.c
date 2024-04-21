/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_letter_to_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:39:28 by bbessard          #+#    #+#             */
/*   Updated: 2023/04/19 10:12:20 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*add_letter_to_string(char const *s1, char const letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((strlen(s1) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	tab[j++] = letter;
	tab[j] = '\0';
	return (tab);
}

int	main(void)
{
	char	*s1;
	char	letter;
	char	*result;

	s1 = "Hello";
	letter = '!';
	result = add_letter_to_string(s1, letter);
	printf("Result: %s\n", result);
	free(result);
	return (0);
}
