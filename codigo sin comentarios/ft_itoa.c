#include <stdlib.h>

static int  ft_nbrlen(int n)
{
    int len = (n <= 0);

    while (n)
        n /= 10, len++;
    return (len);
}

char    *ft_itoa(int n)
{
    char    *str;
    int     len = ft_nbrlen(n);
    long    nb = n;

    str = (char *)malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (nb < 0)
        str[0] = '-', nb = -nb;
    while (--len >= (str[0] == '-'))
        str[len] = '0' + (nb % 10), nb /= 10;
    return (str);
}

