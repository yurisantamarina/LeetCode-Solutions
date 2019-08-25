class DinnerPlates {
public:
    vector<stack<int> > p;
    vector<int> sz;
    int cap;
    set<int> zero, not_full, full;
    DinnerPlates(int capacity) {
        cap = capacity;
        sz.resize(100010, 0);
        p.resize(100010, stack<int>());
        for (int i = 0; i < 100002; i++) {
            zero.insert(i);
        }
    }
    
    void push(int val) {
        int fst;
        if (not_full.size() == 0) {
            fst = *zero.begin();
            zero.erase(zero.begin());
        } else {
            fst = *not_full.begin();
            not_full.erase(not_full.begin());
        }
        sz[fst]++;
        if (sz[fst] == cap) {
            full.insert(fst);
        } else {
            not_full.insert(fst);
        }
        p[fst].push(val);
    }
    
    int pop() {
        if (not_full.size() == 0 && full.size() == 0) {
            return -1;
        }
        int a = not_full.size() > 0 ? *(--(not_full.end())) : -1;
        int b = full.size() > 0 ? *(--(full.end())) : -1;
        int index = max(a, b);
        return popAtStack(index);
    }
    
    int popAtStack(int index) {
        if (sz[index] == 0) return -1;
        int ans = p[index].top();
        p[index].pop();
        sz[index]--;
        if (sz[index] == cap - 1) {
            full.erase(index);
        } else {
            not_full.erase(index);
        }
        if (sz[index] == 0) zero.insert(index);
        else not_full.insert(index);
        return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
