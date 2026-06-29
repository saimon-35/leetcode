struct Node{
    int key;
    Node *next;
    Node(int k, Node *n){
        key = k;
        next = n;
    }
};
class MyHashSet {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node *data[size] = {};
    MyHashSet() {
        
    }
    int hash(int key){
        return (1LL * mult * key) % size;
    }
    void add(int key) {
        remove(key);
        int h = hash(key);
        Node *node = new Node(key, data[h]);
        data[h] = node;
    }
    
    void remove(int key) {
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
            node = node -> next;
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        Node *node = data[h];
        while(node != NULL){
            if(node -> key == key) return true;
            else node = node -> next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
