class Solution {
public:
    
    bool can(long long t, vector<int>& piles, int H){
        long long days = 0;
        for(int &x : piles){
            days += x / t;
            if(x % t != 0)
                days++;
        }
        return days <= H;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        long long lo = 1, hi = 100000000000000LL, mid, K;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(can(mid, piles, H)){
                K = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return K;
    }
};
