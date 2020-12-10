package Unid8;

public class HashReserva {
    int Tab_Hash[];
    int m, m_backup, m_table, backup;
    int NULL = -1;

    public HashReserva(int m_table, int m_backup) {
        this.m_table = m_table;
        this.m_backup = m_backup;
        this.m = m_table + m_backup;
        this.Tab_Hash = new int[this.m];

        for (int i = 0; i < m; i++) {
            Tab_Hash[i] = NULL;
        }

        backup = 0;
    }

    public int Hash(int element) {
        return element % m_table;
    }

    public void insert(int element) {
        if (element != NULL) {
            int key = Hash(element);

            if (Tab_Hash[key] == NULL) {
                Tab_Hash[key] = element;
                return;
            } else if (backup < m_backup) {
                Tab_Hash[backup + m_table] = element;
                backup++;
                return;
            }
        }
    }

    public int find(int element) throws Exception {
        int key = Hash(element);
        if (Tab_Hash[key] == element) {
            return key;
        } else {
            for (int i = 0; i < backup; i++) {
                if (Tab_Hash[m_table + i] == element) {
                    System.out.println("Elemento em reserva!");
                    return m_table + i;
                }
            }
        }
        throw new Exception("Elemento não consta na tabela.");
    }

    public void remove(int element) throws Exception {
        int key = Hash(element);
        int tmp = NULL;
        if (Tab_Hash[key] == element) {
            Tab_Hash[key] = NULL;
            for (int i = 0; i < backup; i++) {
                if (Hash(Tab_Hash[m_table+i]) == key) {
                    tmp = Tab_Hash[m_table+i];
                }
            }
            Tab_Hash[key] = tmp;
        } else {
            for (int i = 0; i < backup; i++) {
                if (Tab_Hash[m_table + i] == element) {
                    Tab_Hash[m_table + i] = NULL;
                    return;
                }
            }
        }
        return;
    }
}
