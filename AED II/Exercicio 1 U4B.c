#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 18;
    int comp = 0;
    int mov = 0;
    int tmp = 0;
    int array[] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};
    for (int i = 1; i < n; i++)
    {
        printf("\nMov: %d < > %d", tmp,array[i]);
        tmp = array[i];
        mov++;
        int j = i - 1;
        printf("\nComp: %d |--| %d",j,0);
        comp++;
        while ((j >= 0) && (array[j] > tmp))
        {
            printf("\nMov: %d < > %d", array[j+1],array[j]);
            array[j + 1] = array[j];
            mov++;
            j--;
            if ((j >= 0) && (array[j] > tmp))
            {
                printf("\nComp: %d |--| %d",array[j],tmp);
                comp++;
            }
        }
        printf("\nMov: %d < > %d", array[j+1],array[tmp]);
        array[j + 1] = tmp;
        mov++;
    }
    printf("\n\nMovimentos: %d", mov);
    printf("\nComparacoes: %d", comp);
    return 0;
}
