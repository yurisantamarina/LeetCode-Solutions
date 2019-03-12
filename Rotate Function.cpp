class Solution {
public:
    
    long long int get(int l, int r, vector<long long int>& v){
        if(l > r) return 0LL;
        return v[r] - (l ? v[l - 1] : 0);
    }
    
    long long int calc(int start, vector<long long int>& mult, vector<long long int>& sum){
        int n = (int)mult.size();
        return get(start, n - 1, mult) - start * get(start, n - 1, sum) + get(0, start - 1, mult) + (n - start) * get(0, start - 1, sum);
    }
    
    int maxRotateFunction(vector<int>& A) {
        int n = (int)A.size();
        vector<long long int> mult(n, 0), sum(n, 0);
        for(int i = 0; i < n; i++){
            mult[i] = i * A[i];
            sum[i] = A[i];
            if(i > 0){
                mult[i] += mult[i - 1];
                sum[i] += sum[i - 1];
            }
        }
        
        long long int ans = LLONG_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, calc(i, mult, sum));
        }
        return ans;
    }
};
