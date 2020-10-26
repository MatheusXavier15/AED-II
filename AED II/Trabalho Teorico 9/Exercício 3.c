#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
int vetor[] = {1,2,3}, *ptr = vetor;

*ptr++; 
(*ptr)++;

for (int i = 0; i < 3; i++)
{
    printf("%d ",vetor[i]);
}
printf("\n%d",*ptr);

}
