package Unid8.HashLista;

public class Celula {
    public int element;
    public Celula next;

    public Celula(int element){
        this.element = element;
        this.next = null;
    }

    public Celula(int element, Celula next){
        this.element = element;
        this.next = next;
    }
}
