// Usando somente ponteiros, implemente as seguintes funções de cadeias de caracteres:
// a) strlen()
// b) strcmp()
// c) strcat()
// d) strchr()
#include <stdio.h>
//Implementação da função strlen
int new_strlen(char *str)
{
    int total = 0;
    while (*(str + total) != '\0')
    {
        total++;
    }
    return total;
}
//Implementação da função strcmp
int new_strcmp(char *str, char *p)
{
    if (new_strlen(str) == new_strlen(p))
    {
        return 0;
    }
    if (new_strlen(str) > new_strlen(p))
    {
        return 1;
    }
    if (new_strlen(str) < new_strlen(p))
    {
        return -1;
    }
}
//Implementação da função strcat
void new_strcat(char *str, char *p)
{
    int N = new_strlen(str);
    int M = new_strlen(p);
    for (int i = 0; i < M; i++)
    {
        *(str + N + i) = *(p + i);
    }
}
//Implementação da função strchr
char *new_strchr(char *str, char x)
{
    for (int i = 0; i < new_strlen(str); i++)
    {
        if (*(str + i) == x)
        {
            return str + i;
        }
    }
    return (NULL);
}