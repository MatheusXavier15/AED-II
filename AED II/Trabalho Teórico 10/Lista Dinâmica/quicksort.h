#include <string.h>

#include "pessoa.h"

// procedimento para trocar dois elementos do vetor
void swap(Pessoa *i, Pessoa *j) {
  Pessoa temp = *i;
  *i = *j;
  *j = temp;
}

// quicksort recursivo para ordenar em ordem alfabetica pelo nome
void quicksortNome(Pessoa *array, int esq, int dir) {
  int i = esq, j = dir;
  char pivo[100];
  strcpy(pivo, array[(dir + esq) / 2].name);
  while (i <= j) {
    while (strcmp(array[i].name, pivo) < 0) i++;
    while (strcmp(array[j].name, pivo) > 0) j--;
    if (i <= j) {
      swap(array + i, array + j);
      i++;
      j--;
    }
  }
  if (esq < j) quicksortNome(array, esq, j);
  if (i < dir) quicksortNome(array, i, dir);
}

// quicksort recursivo para ordenar em ordem crescente pelo codigo
void quicksortCodigo(Pessoa *array, int esq, int dir) {
  int i = esq, j = dir;
  int pivo = array[(dir + esq) / 2].id;
  while (i <= j) {
    while (array[i].id < pivo) i++;
    while (array[j].id > pivo) j--;
    if (i <= j) {
      swap(array + i, array + j);
      i++;
      j--;
    }
  }
  if (esq < j) quicksortCodigo(array, esq, j);
  if (i < dir) quicksortCodigo(array, i, dir);
}

void quicksort(Pessoa *array, int n, char *opc) {
  if (strcmp(opc, "codigo") == 0) {
    quicksortCodigo(array, 0, n - 1);
  } else {
    quicksortNome(array, 0, n - 1);
  }
  // void quicksortTop(char **array, int first_line, int last_line);
}
