// Se i é um valor inteiro e p e q são ponteiros para inteiros, quais seguintes atribuições causam erro de compilação?
// a) p = &i; V
// b) p = *&i; V
// c) p = &*i; X
// d) i = *&*p;V
// e) i = *&p;V
// f) i = &*p;V
// g) p = &*&i;V
// h) q = *&*p;V
// i) q = **&p;V
// j) q = *&p;V
// k) q = &*p;V

#include<stdio.h>
#include<stdlib.h>

int main (){
    int i = 5;
    int *p;
    int *q;
    i = *&p;
}