class Solution {
public:
    vector<pair<int, int>> FindAllCombinations(const vector<int>& array) {
        vector<pair<int, int>> all_comb;
        int len = array.size();
        int lim = 1 << len;
        for (int mask = 0; mask < lim; mask++) {
            int sum = 0;
            int count = 0;
            for (int bit = 0; bit < len; bit++) {
                if (mask & (1 << bit)) {
                    sum += array[bit];
                    ++count;
                }
            }
            all_comb.push_back({sum, count});
        }
        return all_comb;
    }
    
    bool CheckEqualAverage(const vector<pair<int, int>>& all_comb_first_half, const vector<pair<int, int>>& all_comb_second_half, int len_first_half, int len_second_half, int total_sum) {
        vector<unordered_set<int>> num_elems_to_sum_second_half(len_second_half + 1);
        for (const pair<int, int>& comb : all_comb_second_half) {
            num_elems_to_sum_second_half[comb.second].insert(comb.first);
        }
        int num_elems = len_first_half + len_second_half;
        for (const pair<int, int>& comb : all_comb_first_half) {
            int num_elems_comb_first_half = comb.second;
            int sum_elems_comb_first_half = comb.first;
            int start_ = num_elems_comb_first_half == 0 ? 1 : 0;
            int end_ = num_elems_comb_first_half == len_first_half ? len_second_half - 1 : len_second_half; 
            for (int num_elems_comb_second_half = start_; num_elems_comb_second_half < end_; num_elems_comb_second_half++) {
                int num_elems_A = num_elems_comb_first_half + num_elems_comb_second_half;
                if ((total_sum * num_elems_A - sum_elems_comb_first_half * num_elems) % num_elems != 0) {
                    continue;
                }
                int sum_elems_comb_second_half = (total_sum * num_elems_A - sum_elems_comb_first_half * num_elems) / num_elems;
                if (num_elems_to_sum_second_half[num_elems_comb_second_half].count(sum_elems_comb_second_half)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool splitArraySameAverage(vector<int>& A) {
        int num_elems = A.size();
        if (num_elems == 1) {
            return false;
        }
        int len_first_half = num_elems / 2;
        
        vector<int> first_half(A.begin(), A.begin() + len_first_half);
        // {sum, count}
        vector<pair<int, int>> all_comb_first_half = FindAllCombinations(first_half);
        
        
        vector<int> second_half(A.begin() + len_first_half, A.end());
        vector<pair<int, int>> all_comb_second_half = FindAllCombinations(second_half);
        
        int total_sum = accumulate(A.begin(), A.end(), 0);
        return CheckEqualAverage(all_comb_first_half, all_comb_second_half, len_first_half, num_elems - len_first_half, total_sum);
    }
};
