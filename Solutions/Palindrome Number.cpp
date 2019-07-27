class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long int original = static_cast<long long int>(x);
        long long int reverse = 0LL;
        while (x > 0) {
            reverse *= 10LL;
            reverse += (x % 10LL);
            x /= 10LL;
        }
        
        return original == reverse;
    }
};
