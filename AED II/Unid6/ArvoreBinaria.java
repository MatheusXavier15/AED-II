package Unid6;

public class ArvoreBinaria {
    public static No root;

    public ArvoreBinaria() {
        root = null;
    }

    public No getRoot() {
        return root;
    }

    /**
     * Metodo privado recursivo para inserir elemento.
     * 
     * @param x Elemento a ser inserido.
     * @param i No em analise.
     * @return No em analise, alterado ou nao.
     * @throws Exception Se o elemento existir.
     */

    public void insert(int x) throws Exception {
        System.out.println("INSERIR ELEMENTO " + x);
        root = insert(x, root);
    }

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

        return x;
    }

    void insertDad(int x) throws Exception {
        if (root == null) {
            root = new No(x);
        } else if (x < root.element) {
            insertDad(x, root.left, root);
        } else if (x > root.element) {
            insertDad(x, root.right, root);
        } else {
            throw new Exception("Erro na insercao");
        }
    }

    void insertDad(int element, No x, No dad) throws Exception {
        if (x == null) {
            if (element < dad.element) {
                dad.left = new No(element);
            } else {
                dad.right = new No(element);
            }
        } else if (element < x.element) {
            insertDad(element, x.left, dad);
        } else if (element > x.element) {
            insertDad(element, x.right, dad);
        } else {
            throw new Exception("Erro ao inserir.");
        }
    }

    // =========================================================
    // • Número de comparações em uma pesquisa com sucesso:
    // • Melhor Caso: Ө(1)
    // • Pior Caso: Ө(n)
    // • Caso Médio: Ө(lg(n))
    // =========================================================

    public No find(int element) throws Exception {
        return find(element, root);
    }

    public No find(int element, No x) throws Exception {
        if (x == null) {
            return null;
        } else if (element == x.element) {
            return x;
        } else if (element < x.element) {
            find(element, x.left);
        } else if (element > x.element) {
            find(element, x.right);
        }
        return x;
    }

    // ordem crescente-> esq imprime dir
    // ordem decrescente -> dir imprime esq
    public void printCentral(No x) {
        if (x != null) {
            printCentral(x.left);
            System.out.print(x.element + " ");
            printCentral(x.right);
        }
    }

    public void printPre(No x) {
        if (x != null) {
            System.out.print(x.element + " ");
            printPre(x.left);
            printPre(x.right);
        }
    }

    public void printPos(No x) {
        if (x != null) {
            printPos(x.left);
            printPos(x.right);
            System.out.print(x.element + " ");
        }
    }

    // =========================================================
    
    public void TreeSort(ArvoreBinaria Tree, int Array[]) {
    TreeSort(root, Array);
    }

    public void TreeSort(No x, int Array[]) {
        for (int i = 0; i < Array.length; i++) {
            if (x != null) {
                TreeSort(x.left, Array);
                Array[i] = x.element;
                System.out.print(x.element + " ");
                TreeSort(x.right, Array);
            }
        }
    }

    // =========================================================

    public int countPares(ArvoreBinaria Tree) {
        return countPares(root);
    }

    public int countPares(No x) {
        if (x == null) {
            return 0;
        }
        if (x.element % 2 == 0) {
            return 1 + countPares(x.left) + countPares(x.right);
        } else {
            return countPares(x.left) + countPares(x.right);
        }
    }

    // =========================================================

    public boolean verify11Divisor(ArvoreBinaria Tree) {
        return verify11Divisor(root);
    }

    public boolean verify11Divisor(No x) {
        if (x == null) {
            return false;
        }
        if (x.element % 11 == 0) {
            return true;
        } else
            return verify11Divisor(x.left) && verify11Divisor(x.right);
    }

    // =========================================================

    public static boolean verifyTree(ArvoreBinaria TreeX, ArvoreBinaria TreeY) {
        return verifyTree(root, root);
    }

    public static boolean verifyTree(No x, No y) {
        if (x == null && y == null) {
            return true;
        } else if (x == null || y == null) {
            return false;
        }
        return verifyTree(x.left, y.left) && verifyTree(x.right, y.right);
    }

    // =========================================================

    public int soma(ArvoreBinaria Tree) {
        return somaEsq(root) + somaDir(root);
    }

    public int somaEsq(No x) {
        int l = 0;
        if (x != null) {
            l = x.element + somaEsq(x.left);
            return l;
        } else {
            return 0;
        }
    }

    public int somaDir(No x) {
        int r = 0;
        if (x != null) {
            r = x.element + somaDir(x.right);
            return r;
        } else {
            return 0;
        }
    }

    // =========================================================
    // • Número de comparações em uma remoção:
    // • Melhor Caso: Ө(1)
    // • Pior Caso: Ө(n)
    // • Caso Médio: Ө(lg(n))
    // =========================================================

    public void remove(int element) throws Exception {
        root = remove(element, root);
    }

    public No remove(int element, No x) throws Exception {
        if (x == null) {
            throw new Exception("Erro ao remover - nao existe elemento.");
        } else if (element < x.element) {
            x.left = remove(element, x.left);
        } else if (element > x.element) {
            x.right = remove(element, x.right);
        } else if (x.right == null) {
            x = x.left;
        } else if (x.left == null) {
            x = x.right;
        } else {
            x.left = previous(x, x.left);
        }
        return x;
    }

    public No previous(No x, No y) {
        if (y.right != null) {
            y.right = previous(x, y.right);
        } else {
            x.element = y.element;
            y = y.left;
        }
        return y;
    }

    public int high(No i) { // retorna a altura da árvore
        if (i != null) {
            int a1 = 1 + high(i.left);
            int a2 = 1 + high(i.right);
            if (a1 > a2)
                return a1;
            else
                return a2;
        }
        return 0;
    }

    public int high(ArvoreBinaria arv) {
        return high(root) - 1;
    }

    public int ElementHeight(No x) { // retorna a altura do elemento
        int esq, dir;
        if (x == null)
            return -1;
        esq = 1 + ElementHeight(x.left);
        dir = 1 + ElementHeight(x.right);
        if (esq > dir)
            return esq;
        else
            return dir;
    }

    public int um_filho(){ // Java
        return um_filho(root);
    }
    
    public int um_filho(No x){
        int filhos = 0;
        if(x != null){
            if(x.left == null || x.right == null){
                filhos++;
            }
            return um_filho(x.left) + um_filho(x.right);
        }
        return filhos;
    }
}
