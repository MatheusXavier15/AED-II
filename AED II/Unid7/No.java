package Unid7;

public class No {
    int element;
    No left;
    No right;
    int level;

    /**
     * Construtor da classe.
     * 
     * @param element Conteudo do no.
     */
    public No(int element) {
        this(element, null, null, 1);
    }

    /**
     * Construtor da classe.
     * 
     * @param element Conteudo do no.
     * @param left    No da esquerda.
     * @param right   No da direita.
     */
    public No(int element, No left, No right, int level) {
        this.element = element;
        this.left = left;
        this.right = right;
        this.level = level;
    }

    /**
     * Retorna o número de níveis a partir de um vértice
     * 
     * @param No nó que se deseja o nível.
     */
    public int getLevel(No x) {
        if (x == null) {
            return 0;
        } else {
            return x.level;
        }
    }

    /**
     * Cálculo do número de níveis a partir de um vértice
     */
    public void setLevel() {
        this.level = 1 + Math.max(getLevel(left), getLevel(right));
    }
}
