#include <unistd.h>

int ft_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13)); 
}

char **ft_split(char *str)
{
    static char words[4096][4096];
    static char *split[4096];
    int contwords = 0;
	int contchars = 0;
	int i = 0;

    while (str[i] && ft_space(str[i])) 
        cont++;

    while (str[i])
    {
        if (ft_space(str[i]) && contchars > 0)
        {
            words[contwords][contchars] = '\0';
            split[contwords] = words[contwords];
            contwords++;
            contchars = 0;
        }
        else if (!ft_space(str[i]))
            words[contwords][contchars++] = str[i];

        i++;
    }

    if (contchars > 0)
    {
        words[contwords][contchars] = '\0';
        split[contwords] = words[contwords];
        contwords++;
    }

    split[contwords] = NULL;
    return split;
}

