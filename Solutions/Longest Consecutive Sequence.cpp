class Solution {
public:
    int FindSequence(int node, unordered_set<int>& nums) {
        if (!nums.count(node)) {
            return 0;
        }
        nums.erase(node);
        int size_component = 1;
        int cur = node - 1;
        while (nums.count(cur) > 0) {
            nums.erase(cur);
            cur--;
            size_component++;
        }
        cur = node + 1;
        while (nums.count(cur) > 0) {
            nums.erase(cur);
            cur++;
            size_component++;
        }
        return size_component;
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_hash_map;
        for (int num : nums) {
            nums_hash_map.insert(num);
        }
        int answer = 0;
        for (int num : nums) {
            answer = max(answer, FindSequence(num, nums_hash_map));
        }
        return answer;
    }
};
