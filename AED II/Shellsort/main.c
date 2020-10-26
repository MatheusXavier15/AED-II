#include <stdlib.h>
#include <stdio.h>
#define n 18

int main()
{
    int comp = 0;
    int mov = 0;
    int array[n] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};
    int h = 1;
    int tmp = 0;
    do
    {
        h = (h * 3) + 1;
    } while (h < n);
    do
    {
        h /= 3;
        for (int cor = 0; cor < h; cor++)
        {
            for (int i = (h + cor); i < n; i += h)
            {
                printf("\nMov: %d < > %d", tmp,array[i]);
                tmp = array[i];
                mov++;
                int j = i - h;
                printf("\nComp: %d |--| %d", j,0);
                comp++;
                while ((j >= 0) && (array[j] > tmp))
                {
                    printf("\nMov: %d < > %d",array[j + h],array[j]);
                    array[j + h] = array[j];
                    mov++;
                    j -= h;
                    if ((j >= 0) && (array[j] > tmp))
                    {
                        printf("\nComp: %d |--| %d", array[j], tmp);
                        comp++;
                    }
                }
                printf("\nMov: %d < > %d", array[j+1],array[tmp]);
                array[j + h] = tmp;
                mov++;
            }
        }
    } while (h != 1);
    printf("\n\nComp: %d",comp);
    printf("\nMov: %d\n", mov);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
