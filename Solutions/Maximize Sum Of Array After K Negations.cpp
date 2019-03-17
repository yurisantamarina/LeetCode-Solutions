class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int> > pq;
        int ans = 0;
        for(int &x : A){
            pq.push(x);
            ans += x;
        }
        while(K > 0){
            int x = pq.top();
            pq.pop();
            ans -= x;
            ans += (-x);
            pq.push(-x);
            K--;
        }
        return ans;
    }
};
