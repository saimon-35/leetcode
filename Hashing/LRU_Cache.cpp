class LRUCache {
public:
    class Node{
    public:
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int _key, int _value){
            key = _key;
            value = _value;
        }
    };
    unordered_map<int, Node*>m;
    int capacity;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    void addNode(Node *node){
        Node *temp = head -> next;
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
        temp -> prev = node;
    }
    void deleteNode(Node *node){
        Node *prevv = node -> prev;
        Node *nextt = node -> next;
        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    LRUCache(int _capacity) {
        capacity = _capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(m.count(key)){
            Node *node = m[key];
            int ans = node -> value;
            m.erase(key);
            deleteNode(node);
            addNode(node);
            m[key] = head -> next;
            return ans;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            Node *curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }
        if(m.size() == capacity){
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        Node *newNode = new Node(key, value);
        addNode(newNode);
        m[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
