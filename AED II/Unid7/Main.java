package Unid7;

public class Main{
    public static void main (String[] args) throws Exception{
        int array[] = {6,3,2,4,5,7,1};    
        ArvoreAVL Tree = new ArvoreAVL();
        for(int element = 0; element < 7; element++){
            Tree.insert(array[element]);
        }
        System.out.println(Tree.find(4));
        Tree.printCenter();
    }
    
} 
