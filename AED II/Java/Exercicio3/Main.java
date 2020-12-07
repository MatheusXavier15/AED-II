import java.util.Scanner;

class Main {
    static class No {

        public String elemento; 
        public No esq, dir; 

        /**
         * Construtor da classe.
         * 
         * @param elemento Conteudo do no.
         */
        public No(String elemento) {
            this(elemento, null, null);
        }

        /**
         * Construtor da classe.
         * 
         * @param elemento Conteudo do no.
         * @param esq      No da esquerda.
         * @param dir      No da direita.
         */
        public No(String elemento, No esq, No dir) {
            this.elemento = elemento;
            this.esq = esq;
            this.dir = dir;
        }
    }

    public static class ArvoreBinaria {

        private No raiz; 

        /**
         * Construtor da classe.
         */
        public ArvoreBinaria() {
            raiz = null;
        }

        private No pesquisa(String value) {
            return pesquisa(value, raiz);
        }

        private No pesquisa(String value, No element) {
            No retorno;
            if (element == null) {
                return null;
            } else if (value.equals(element.elemento)) {
                return element;
            } else {
                retorno = pesquisa(value, element.esq);
                if (retorno == null) {
                    retorno = pesquisa(value, element.dir);
                }
            }
            return retorno;
        }

        public void caminharCentral() {
            System.out.print("");
            caminharCentral(raiz);
            System.out.println("");
        }

        private void caminharCentral(No i) {
            if (i != null) {
                if (
                    (
                      i.elemento.equals("+") ||
                      i.elemento.equals("-") ||
                      i.elemento.equals("/") ||
                      i.elemento.equals("*")) && 
                      !(i.esq.elemento.equals("+") ||
                       i.esq.elemento.equals("-") ||
                        i.esq.elemento.equals("*") ||
                         i.esq.elemento.equals("/")) && 
                         !(i.dir.elemento.equals("+") ||
                          i.dir.elemento.equals("-") ||
                           i.dir.elemento.equals("*") ||
                            i.dir.elemento.equals("/")))
              {
                System.out.print("(");
              }
      
              caminharCentral(i.esq); 
              
              System.out.print(i.elemento);
              caminharCentral(i.dir); 
                if (
                    (
                      i.elemento.equals("+") ||
                      i.elemento.equals("-") ||
                      i.elemento.equals("/") ||
                      i.elemento.equals("*")) && 
                      (!i.esq.elemento.equals("+") 
                      || !i.esq.elemento.equals("-") 
                      || !i.esq.elemento.equals("*") 
                      || !i.esq.elemento.equals("/")) && 
                      (!i.dir.elemento.equals("+") ||
                       !i.dir.elemento.equals("-") ||
                        !i.dir.elemento.equals("*") ||
                         !i.dir.elemento.equals("/")))
                  {
                System.out.print(")");
              }
            
          }
        }
        /**
         * Metodo publico iterativo para inserir elemento.
         * 
         * @param x Elemento a ser inserido.
         * @throws Exception Se o elemento existir.
         */
        public void inserir(String x) throws Exception {
            raiz = new No(x);
        }

        /**
         * Metodo privado recursivo para inserir elemento.
         * 
         * @param x Elemento a ser inserido.
         * @param i No em analise.
         * @return No em analise, alterado ou nao.
         * @throws Exception Se o elemento existir.
         */
        public boolean inserir(String element, String dad, String side) {
            No pai = pesquisa(dad);
            if (pai != null) {
                if (side.equals("D")) {
                    pai.dir = new No(element);
                    return true;
                } else if (side.equals("E")) {
                    pai.esq = new No(element);
                    return true;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) throws Exception {

        ArvoreBinaria Tree = new ArvoreBinaria();

        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        in.nextLine();
        String value;
        String[] array = new String[] {};
        String root = in.nextLine();
        Tree.inserir(root);
        for (int i = 0; i < N - 1; i++) {
            value = in.nextLine();
            array = value.split(" ");
            Tree.inserir(array[0], array[1], array[2]);
        }
        in.close();
        Tree.caminharCentral();
    }
}