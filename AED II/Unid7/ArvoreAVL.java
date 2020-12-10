package Unid7;

public class ArvoreAVL {
    private No root;

    /**
     * Construtor da classe.
     */
    public ArvoreAVL() {
        root = null;
    }

    /**
     * Método que devolve a raíz.
     */
    public No getRoot() {
        return root;
    }

    /**
     * Metodo publico iterativo para pesquisar elemento.
     * 
     * @param x Elemento que sera procurado.
     * @return <code>true</code> se o elemento existir, <code>false</code> em caso
     *         contrario.
     */
    public boolean find(int x) {
        return find(x, root);
    }

    /**
     * Metodo privado recursivo para pesquisar elemento.
     * 
     * @param x Elemento que sera procurado.
     * @param y No em analise.
     * @return <code>true</code> se o elemento existir, <code>false</code> em caso
     *         contrario.
     */
    public boolean find(int x, No y) {
        boolean answer = true;
        if (y == null) {
            answer = false;
        } else if (x == y.element) {
            answer = true;
        } else if (x < y.element) {
            answer = find(x, y.left);
        } else if (x > y.element) {
            answer = find(x, y.right);
        }
        return answer;
    }

    /**
     * Metodo publico iterativo para exibir elementos.
     */
    public void printCenter() {
        System.out.print("[ ");
        printCenter(root);
        System.out.println("]");
    }

    /**
     * Metodo privado recursivo para exibir elementos.
     * 
     * @param i No em analise.
     */
    private void printCenter(No y) {
        if (y != null) {
            printCenter(y.left); // Elementos da esquerda.
            System.out.print(y.element + " "); // Conteudo do no.
            printCenter(y.right); // Elementos da direita.
        }
    }

    /**
     * Metodo publico iterativo para inserir elemento.
     * 
     * @param x Elemento a ser inserido.
     * @throws Exception Se o elemento existir.
     */
    public void insert(int x) throws Exception {
        System.out.println("INSERIR ELEMENTO " + x);
        root = insert(x, root);
    }

    /**
     * Metodo privado recursivo para inserir elemento.
     * 
     * @param element Elemento a ser inserido.
     * @param x       No em analise.
     * @return No em analise, alterado ou nao.
     * @throws Exception Se o elemento existir.
     */
    private No insert(int element, No x) throws Exception {
        if (x == null) {
            x = new No(element);

        } else if (element < x.element) {
            x.left = insert(element, x.left);

        } else if (element > x.element) {
            x.right = insert(element, x.right);

        } else {
            throw new Exception("Erro ao inserir!");
        }

        return balance(x);
    }

    /**
     * Metodo privado iterativo para balancear a árvore.
     * 
     * @param x No em analise.
     * @return No em analise, balanceado ou nao.
     * @throws Exception Se o elemento existir.
     */
    private No balance(No x) throws Exception {
        if (x != null) {
            int factor = x.getLevel(x.right) - x.getLevel(x.left);
            if (Math.abs(factor) <= 1) {
                x.setLevel();
            } else if (factor == 2) {
                int rightFactor = x.getLevel(x.right.right) - x.getLevel(x.right.left);
                if (rightFactor == -1) {
                    x.right = rightRotate(x.right);
                }
                x = leftRotate(x);
            } else if (factor == -2) {
                int leftFactor = x.getLevel(x.left.right) - x.getLevel(x.left.left);
                if (leftFactor == 1) {
                    x.left = leftRotate(x.left);
                }
                x = rightRotate(x);
            } else {
                throw new Exception("Erro fator de balanceamento (" + factor + ") invalido!");
            }
        }
        return x;
    }

    /**
     * Metodo privado iterativo para rotacionar a direira a árvore.
     * 
     * @param x No em analise.
     * @return No em analise rotacionado.
     */
    private No rightRotate(No x) {
        No left = x.left;
        No leftRight = left.right;
        left.right = x;
        x.left = leftRight;

        x.setLevel();
        left.setLevel();
        return left;
    }

    /**
     * Metodo privado iterativo para rotacionar a esquerda a árvore.
     * 
     * @param x No em analise.
     * @return No em analise rotacionado.
     */
    private No leftRotate(No x) {
        No right = x.right;
        No rightLeft = right.left;
        right.left = x;
        x.right = rightLeft;

        x.setLevel();
        right.setLevel();
        return right;
    }

}