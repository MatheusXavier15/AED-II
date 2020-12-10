package Unid7;

public class Main{
        
    public static void main (String[] args) throws Exception{
        ArvoreAVL Tree = new ArvoreAVL();
        for(int element = 20; element >= 1; element--){
            Tree.insert(element);
        }
        Tree.printCenter();
    }
    
} 
