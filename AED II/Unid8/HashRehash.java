package Unid8;

public class HashRehash{
    int[] Tab_Hash;
    int m;
    int NULL = -1;

    public HashRehash(int m){
        this.m = m;
        this.Tab_Hash = new int[this.m];
        for(int i = 0; i < m; i++){
            Tab_Hash[i]=NULL;
        }
    }

    public int Hash(int element){
        return element % m;
    }

    public int ReHash(int element){
        return ++element % m;
    }

    public void insert (int element){
        if(element != NULL){
            int key = Hash(element);
            
            if(Tab_Hash[key]==NULL){
                Tab_Hash[key] = element;
                return;
            } else{
                key = ReHash(element);

                if(Tab_Hash[key] == NULL){
                    Tab_Hash[key] = element;
                    return;
                }
            }
        }
        return;
    }

    public int find(int element){
        int key = Hash(element);
        if(Tab_Hash[key]==element){
        return key;
        } else{
            key = ReHash(element);
            if(Tab_Hash[key]==element){
                return key;
            }
        }
        return key;
    }

    public void remove(int element){
        int key = Hash(element);
        if (Tab_Hash[key] == element) {
            Tab_Hash[key] = NULL;
        } else {
            for (int i = 0; i < m; i++) {
                key = ReHash(element);
                if (Tab_Hash[key] == element) {
                    Tab_Hash[key] = NULL;
                    return;
                }
            }
        }
    }
}