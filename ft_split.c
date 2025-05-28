/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:40:28 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 18:42:48 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_space(str[i]))
			i++;
	}
	return (count);
}

char	*ft_word_dup(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count_words(str) + 1));
	if (!split)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		start = i;
		while (str[i] && !is_space(str[i]))
			i++;
		if (start != i)
			split[j++] = ft_word_dup(str, start, i);
	}
	split[j] = NULL;
	return (split);
}

/*#include <stdio.h>
int main(void)
{
    char **split;
    int i = 0;

    split = ft_split("Cada palabra una línea");
    while (split[i])
    {
        printf("%s\n", split[i]);
        free(split[i]);
        i++;
    }
    free(split);
    return (0);
}

/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc

Escribe una función que tome una cadena, la divida en palabras y
 las devuelva como
una matriz de cadenas terminada en NULL.
Una "palabra" se define como parte de una cadena delimitada por
espacios/tabulaciones/nueva
líneas, o por el inicio/final de la cadena.
Su función debe declararse de la siguiente manera:
char **ft_split(char *str);
*/
