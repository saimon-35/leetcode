struct Node{
    int key;
    int val;
    Node *next;
    Node(int k, int v, Node *n){
        key = k;
        val = v;
        next = n;
    }
};

class MyHashMap {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node *data[size] = {};
    int hash(int key){
        return ((1LL * key * mult )% size);
    }
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        Node *node = new Node(key, value, data[h]);
        data[h] = node;
    }
    
    int get(int key) {
        int h = hash(key);
        Node *node = data[h];
        while(node != NULL){
            if(node -> key == key) return node -> val;
            else node = node -> next;
        }
        return -1;
    }
    
    void remove(int key){
        int h = hash(key);
        Node *node = data[h];
        if(node == NULL) return;
        if(node -> key == key){
            data[h] = node -> next;
            delete node;
            return;
        }
        while(node -> next != NULL){
            Node *temp = node -> next;
            if(temp -> key == key){
                node -> next = temp -> next;
                delete temp;
                return;
            }
            else node = node -> next;
        }

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
