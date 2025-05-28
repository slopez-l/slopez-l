/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:18:44 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 20:02:58 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*range;
	int	len;
	int	i;

	i = 0;
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	range = (int *)malloc(sizeof(int) * len);
	if (!range)
		return (NULL);
	while (i < len)
	{
		range[i++] = end;
		if (end > start)
			end--;
		else
			end++;
	}
	return (range);
}

/*#include <stdio.h>

int	main(void)
{
	int	*numbers;
    int	i = 0;
    int start = 0, end = -3;
    int len = (start > end) ? (start - end + 1) : (end - start + 1);

	numbers = ft_rrange(start, end);
    while (i < len)
        printf("%d, ", numbers[i++]);

    free(numbers);
    return (0);
}

/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc

Escribe la siguiente función:
int *ft_rrange(int start, int end);
Debe asignar (con malloc()) una matriz de números enteros,
llenarla con números consecutivos
valores que comienzan al final y terminan al inicio
(¡incluidos el inicio y el final!), luego
devuelve un puntero al primer valor de la matriz.

Examples:
- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/
