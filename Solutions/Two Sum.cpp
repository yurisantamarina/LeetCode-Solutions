class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int, int> > cpy;
        
        for(int i = 0; i < (int)nums.size(); i++)
                cpy.push_back({nums[i], i});
    
        int l = 0, r = (int)cpy.size() - 1;
        sort(cpy.begin(), cpy.end());
        while(l < r){
            if(cpy[l].first + cpy[r].first == target){
                ans.push_back(cpy[l].second);
                ans.push_back(cpy[r].second);
                return ans;
            }
            
            if(cpy[l].first + cpy[r].first > target){
                r--;
            }else{
                l++;
            }
        }
    }
};
