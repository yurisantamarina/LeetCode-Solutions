class Solution {
public:
    
    int CalculateMaxJumpFrom(int index, const vector<int>& arr, int n, vector<int>& max_jump_from, int d) {
        if (max_jump_from[index] != -1) {
            return max_jump_from[index];
        }
        int max_jump = 1;
        int current_index = index + 1;
        int distance_so_far = 1;
        while (current_index < n && distance_so_far <= d) {
            if (arr[index] > arr[current_index]) {
                max_jump = max(max_jump, 1 + CalculateMaxJumpFrom(current_index, arr, n, max_jump_from, d));
            } else {
                break;
            }
            ++distance_so_far;
            ++current_index;
        }
        current_index = index - 1;
        distance_so_far = 1;
        while (current_index >= 0 && distance_so_far <= d) {
            if (arr[index] > arr[current_index]) {
                max_jump = max(max_jump, 1 + CalculateMaxJumpFrom(current_index, arr, n, max_jump_from, d));
            } else {
                break;
            }
            ++distance_so_far;
            --current_index;
        }
        
        return max_jump_from[index] = max_jump;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        vector<int> max_jump_from((int)arr.size(), -1);
        int max_jump = -1;
        for (int i = 0; i < (int)arr.size(); ++i) {
            max_jump = max(max_jump, CalculateMaxJumpFrom(i, arr, (int)arr.size(), max_jump_from, d));
        }
        return max_jump;
    }
};
