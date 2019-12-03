class Node {
public:
    short val;
    Node* prv;
    Node* nxt;
    Node(short val_) {
        val = val_;
        prv = nxt = nullptr;
    }
};

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        head = tail = nullptr;
        sz = 0;
        cap = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        Node* to_insert = new Node(value);
        if (isEmpty()) {
            head = tail = to_insert;
        } else {
            to_insert->nxt = head;
            head->prv = to_insert;
            head = to_insert;
        }
        sz++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        Node* to_insert = new Node(value);
        if (isEmpty()) {
            head = tail = to_insert;
        } else {
            to_insert->prv = tail;
            tail->nxt = to_insert;
            tail = to_insert;
        }
        sz++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        sz--;
        Node* to_delete = head;
        head = head->nxt;
        if (isEmpty()) {
            head = tail = nullptr;
        } else {
            head->prv = nullptr;
        }
        delete to_delete;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        sz--;
        Node* to_delete = tail;
        tail = tail->prv;
        if (isEmpty()) {
            head = tail = nullptr;
        } else {
            tail->nxt = nullptr;
        }
        delete to_delete;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return head->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return tail->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return sz == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return sz == cap;
    }
private:
    Node* head;
    Node* tail;
    short sz;
    short cap;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
