
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
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = selected;
    }
}

// Driver program to test above function
int main()
{
    int comp = 0;
    int mov = 0;
    int tmp = 0;
    int array[] = {3, 7, 10, 14, 16};
    int n = sizeof(array) / sizeof(array[0]), i;
    insertionSort(array, n);
    
    return 0;
}
