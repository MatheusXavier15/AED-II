// Faça um método que retorna a altura da árvore. Em seguida, insira vários
// elementos de forma aleatória. Para cada inserção, mostre na tela o número
// de elementos da árvore, o logaritmo (base 2) desse número e a altura

package Unid6.Exerc1;

import Unid6.ArvoreBinaria;
import java.text.DecimalFormat;

public class Main {
    
    public static void main(String[] args) throws Exception {
        int element;
        ArvoreBinaria Tree = new ArvoreBinaria();
        int[] array = { 5, 4, 3, 2, 1, 6, 9, 8, 7, 10 };
        for (int i = 0; i < 10; i++) {
            element = array[i];
            System.out.println("Elemento inserido: " + element);
            Tree.inserir(element);
            // System.out.println("A arvore contém: " + i + " elementos");
            // System.out.println("ln(" + element + ") = " + df.format(log(2, element)));
            // System.out.println("Altura do elemento na árvore: " + Tree.ElementHeight(Tree.find(element)));
        }
        //System.out.println(Tree.soma(Tree));
        System.out.println(Tree.countPares(Tree));
    }
    //Função que retorna o valor do logaritmo
    public static double log(double base, double valor) {
        return Math.log(valor) / Math.log(base);
    }
    
    DecimalFormat df = new DecimalFormat("#.000");
}
