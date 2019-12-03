class Solution {
public:
    int GetTrapWaterOneWay(const vector<int>& height, int stop_position) {
        int cur_max_height = 0;
        int cur_sum_between_steps = 0;
        int cur_distance_between_steps = 0;
        cur_max_height = height[0];
        cur_distance_between_steps = 0;
        int trap_water = 0;
        for (int i = 1; i <= stop_position; i++) {
            if (cur_max_height <= height[i]) {
                trap_water += (cur_distance_between_steps * cur_max_height - cur_sum_between_steps);
                cur_distance_between_steps = 0;
                cur_max_height = height[i];
                cur_sum_between_steps = 0;
            } else {
                cur_distance_between_steps++;
                cur_sum_between_steps += height[i];
            }
        }
        return trap_water;
    }
    
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int max_height_index = 0;
        for (int i = 1; i < int{height.size()}; i++) {
            if (height[i] > height[max_height_index]) {
                max_height_index = i;
            }
        }
        int trap_water = GetTrapWaterOneWay(height, max_height_index);
        reverse(height.begin(), height.end());
        max_height_index = int{height.size()} - max_height_index - 1;
        trap_water += GetTrapWaterOneWay(height, max_height_index);
        return trap_water;
    }
};
