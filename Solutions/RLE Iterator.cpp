class RLEIterator {
public:
    vector<int> arr;
    int pos_arr;
    RLEIterator(vector<int>& A) {
        arr = A;
        pos_arr = 0;
    }
    
    int next(int n) {
        while (pos_arr < int{arr.size()} && n > arr[pos_arr]) {
            n -= arr[pos_arr];
            pos_arr += 2;
        }
        if (pos_arr < int{arr.size()}) {
            arr[pos_arr] -= n;
            return arr[pos_arr + 1];
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
