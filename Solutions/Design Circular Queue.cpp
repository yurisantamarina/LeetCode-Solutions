class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        circ_queue.resize(k);
        front_index = 0;
        rear_index = -1;
        len = 0;
        max_len = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear_index = (rear_index + 1) % max_len;
        circ_queue[rear_index] = value;
        len++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front_index = (front_index + 1) % max_len;
        len--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return circ_queue[front_index];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return circ_queue[rear_index];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return len == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return len == max_len;
    }
private:
    vector<int> circ_queue;
    int front_index;
    int rear_index;
    int len;
    int max_len;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
