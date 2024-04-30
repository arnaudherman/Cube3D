/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:18:43 by bbessard          #+#    #+#             */
/*   Updated: 2022/11/21 18:37:14 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Cette fonction alloue un bloc de mémoire en initialisant tous ces octets 
à la valeur 0. Bien que relativement proche de la fonction malloc, 
deux aspects les différencient :

L'initialisation : calloc met tous les octets du bloc à la valeur 0 alors 
que malloc ne modifie pas la zone de mémoire.

Les paramètres d'appels : calloc requière deux paramètres (le nombre 
d'éléments consécutifs à allouer et la taille d'un élément) alors que 
malloc attend la taille totale du bloc à allouer.
https://koor.fr/C/cstdlib/calloc.wp
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	else
		ft_bzero(result, count * size);
	return (result);
}
