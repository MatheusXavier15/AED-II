package Unid6;
public class No {
    int element;
    No left;
    No right;

    //primeiro construtor:
    No(int element) {
        this(element, null, null);
    }
    
    //Segundo construtor
    No(int element, No left, No right){
        this.element = element;
        this.left = left;
        this.right = right;
    }
}
