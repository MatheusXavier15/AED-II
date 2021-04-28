package Unid8.HashLista;

public class Lista {
    private Celula first;
    private Celula end;

    public Lista(){
        first = new Celula(-1);
        end = first;
    }

    public void print_list(Lista list){
        for(Celula i = first.next; i != null; i = i.next){
            System.out.print(i.element + " ");
        }
    }

    public Celula find(int element) throws Exception{
        for(Celula i = first.next; i != null; i = i.next){
            if(i.element == element){
                return i;
            }
        }
        throw new Exception("Elemento não encontrado.");
    }

    public int find_position(int element) throws Exception{
        int position = 0;
        for(Celula i = first.next; i != null; i = i.next){
            if(i.element == element){
                return position;
            }
            position ++;
        }
        throw new Exception("Elemento não encontrado.");
    }

    public void insert(int element){
        Celula tmp = new Celula(element);
        tmp.next = first.next;
        first.next = tmp;
        if(first == end){
            end = tmp;
        }
        tmp = null;
    }

    public void end_insertion(int element){
        Celula tmp = new Celula(element);
        end.next = tmp;
        end=end.next;
        tmp = null;
    }

    public void middle_insertion(int element, int position) throws Exception{
        Celula x;
        int count = 0;

        for(x = first, count = 0; (x.next != null && count<position); x = x.next, count++);

        if(position <0 || position >count + 1){
            throw new Exception("Erro ao inserir na posicao " + position);
        } else if(position == count + 1){
            end_insertion(element);
        } else {
            Celula tmp = new Celula(element);
            tmp.next = x.next;
            x.next = tmp;
            tmp = x = null;
        }
    }

    public void delete()throws Exception{
        if(first == end){
            throw new Exception("ERRO | LISTA VAZIA");
        } else{
            first = first.next;
            return;
        }
    }

    public void end_delete()throws Exception{
        Celula x = null;
        if(first == end){
            throw new Exception("ERRO | LISTA VAZIA");
        } else{
            for(x = first; x.next != end ; x = x.next){
                end = x;
                x = end.next = null;
                return;
            }
        }
    }

    public void middle_delete(int position) throws Exception{
        Celula x;
        int count = 0;
        if(first == end){
            throw new Exception("ERRO | LISTA VAZIA");
        } else{
            for(x = first, count = 0; (x.next != end && count<position) ; x=x.next, count++);
            if(position < 0 || position > count+1){
                throw new Exception("Erro ao remover posicao");
            } else if(position == count + 1){
                end_delete();
                return;
            } else{
                Celula tmp = x.next;
                x.next = tmp.next;
                tmp.next = null;
                x = tmp = null;
            }
        }
    }
}
