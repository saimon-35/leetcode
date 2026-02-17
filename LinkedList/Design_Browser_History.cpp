class Node {
public:
    Node* prev;
    Node* next;
    string url;
    Node(string s) {
        prev = nullptr;
        next = nullptr;
        url = s;
    }
};
class BrowserHistory {
public:
    Node* head;
    Node* tail;
    Node* temp_tail;
    int size = 0;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        tail = head;
        temp_tail = head;
        size++;
    }

    void visit(string url) {
        while (temp_tail != tail) {
            temp_tail = temp_tail->prev;
            delete temp_tail->next;
            size--;
        }
        Node* newNode = new Node(url);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        temp_tail = tail;
        size++;
    }

    string back(int steps) {
        if (tail == head)
            return tail->url;
        while (steps) {
            tail = tail->prev;
            if (tail == head)
                return tail->url;
            steps--;
        }
        return tail->url;
    }

    string forward(int steps) {
        if (temp_tail == tail)
            return tail->url;
        while (steps) {
            tail = tail->next;
            if (tail == temp_tail)
                return tail->url;
            steps--;
        }
        return tail->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
