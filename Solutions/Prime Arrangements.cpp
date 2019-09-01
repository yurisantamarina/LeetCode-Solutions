class Solution {
public:
    
    int prime(int n) {
        if (n == 2) return 1;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return 0;
        }
        return 1;
    }
    int numPrimeArrangements(int n) {
        int p = 0;
        for (int i = 2; i<=n; i++) {
            p += prime(i);
        }
        int a = n - p;
        
        long long int f1 = 1;
        long long int mod = 1000000007LL;
        for (int i = 1; i <= p; i++) {
            f1 = (f1 * i) % mod;
        }
        long long int f2 = 1;
        for (int i = 1; i <= a; i++) {
            f2 = (f2 * i) % mod;
        }
        
        return (f1 * f2) % mod;
    }
};
