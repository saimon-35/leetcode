class Node{
    public:
    Node* prev;
    Node* next;
    int val;
    Node(int x){
        val = x;
        prev = nullptr;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size = 0;
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        Node* temp = head;
        for(int i = 0; i < index; i++) temp = temp -> next;
        return temp -> val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            size++;
            return;
        }
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            size++;
            return;
        }
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i = 0; i < index; i++) temp = temp -> next;
        newNode -> next = temp;
        newNode -> prev = temp -> prev;
        temp -> prev -> next = newNode;
        temp -> prev = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        if(index == 0){
            Node* temp = head;
            head = head -> next;
            if(head != nullptr) head -> prev = nullptr;
            else tail = nullptr;
            delete temp;
            size--;
            return;
        }
        if(index == size - 1){
            Node* temp = tail;
            tail  = tail -> prev;
            if(tail != nullptr) tail -> next = nullptr;
            else head = nullptr;
            delete temp;
            size--;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < index; i++) temp = temp -> next;
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        size--;
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
