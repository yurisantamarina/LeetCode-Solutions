class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() == 0)
            return false;
        multiset<int> ms;
        int l = 0;
        ms.insert(nums[l]);
        for(int r = 1; r < (int)nums.size(); r++){
            if(r - l > k)
                ms.erase(ms.find(nums[l++]));
            
            //~ printf("r = %d l = %d\n", r, l);
            
            auto a = ms.upper_bound(nums[r]);
            long long A = 1000000000000000000LL;
            long long B = A;
            if(a != ms.end())
                A = *a;
            
            if(a != ms.begin()){
                a = prev(a);
                B = *a;
            }
            if(abs(A - nums[r]) <= t || abs(B - nums[r]) <= t)
                return true;
            ms.insert(nums[r]);
        }
        return false;
    }
};
