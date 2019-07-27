class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> intersection;
        
        int i = 0, j = 0;
        while (i < int{nums1.size()} && j < int{nums2.size()}) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                if (int{intersection.size()} == 0 || nums1[i] != intersection.back()) {
                    intersection.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        
        return intersection;
    }
};
