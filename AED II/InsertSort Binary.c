
#include <stdio.h>
// Funcao baseada na pesquisa binaria para achar a posicao
int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == a[mid])
        return mid + 1;

    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}

// Function to sort an array a[] of size 'n'
void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
    int mov = 0;
    int comp = 0;
    for (i = 1; i < n; ++i)
    {

        j = i - 1;
        printf("\nMov: %d < > %d", selected, a[i]);
        selected = a[i];
        mov++;
        loc = binarySearch(a, selected, 0, j);

        while (j >= loc)
        {
            printf("\nComp: %d |--| %d", j, loc);
            comp++;
            printf("\nMov: %d < > %d", a[j + 1], a[j]);
            mov++;
            a[j + 1] = a[j];
            j--;
        }
        printf("\nMov: %d < > %d", a[j + 1], selected);
        mov++;
        a[j + 1] = selected;
    }
    printf("\n");
    printf("\nComparacoes: %d", comp);
    printf("\nMovimentos: %d", mov);
}

// Driver program to test above function
int main()
{
    int comp = 0;
    int mov = 0;
    int tmp = 0;
    int array[] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};
    int n = sizeof(array) / sizeof(array[0]), i;

    insertionSort(array, n);

    return 0;
}
