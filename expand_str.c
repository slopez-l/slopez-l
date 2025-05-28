/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:27:13 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/27 00:28:08 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

void    expand_str(char *str)
{
    int i;

    i = 0;
    while (str[i] && is_space(str[i]))
        i++;
    while (str[i])
    {
        if (is_space(str[i]))
        {
            while (str[i] && is_space(str[i]))
                i++;
            if (str[i])
                write(1, "   ", 3);
        }
        if (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        expand_str(argv[1]);
    write(1, "\n", 1);
    return (0);
}

/*
Escribe un programa que tome una cadena y
la muestre exactamente con tres espacios.
entre cada palabra, sin espacios ni tabulaciones
ni al principio ni al final,seguido de una nueva línea.
Una palabra es una sección de cadena delimitada por
espacios/tabulaciones o por el inicio/final de la cadena.
Si el número de parámetros no es 1, o si no hay palabras, simplemente muestre
una nueva línea.

Examples:
$> ./expand_str "vous   voyez   c'est   facile   d'afficher
   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/
