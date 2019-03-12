class Solution {
public:
    vector<int> bit;
    void update(int pos){
        for(int i = pos; i < (int)bit.size(); i += i & -i)
            bit[i]++;
    }
    int query(int pos){
        int sum = 0;
        for(int i = pos; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }
    bool isIdealPermutation(vector<int>& A) {
        int global = 0, local = 0;
        int n = (int)A.size();
        bit.resize(n+2, 0);
        for(int i = n - 1; i >= 0; i--){
            global += query(A[i]);
            update(A[i] + 1);
            if(i != n - 1 && A[i] > A[i + 1])
                local++;
        }
        return global == local;
    }
};
