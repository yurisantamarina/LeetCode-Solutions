class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mean = 0.0f, median = 0.0f;
        int minimum = 256, maximum = -1, mode = 0, qtd_elem = 0;
        long long int sum = 0LL;
        
        for (int i = 0; i < int{count.size()}; i++) {
            if (count[i] > 0) {
                if (minimum == 256) {
                    minimum = i;
                }
                maximum = i;
            }
            
            if (count[i] > count[mode]) {
                mode = i;
            }
            
            qtd_elem += count[i];
            
            sum += static_cast<long long int>(count[i]) * i;
        }
        
        mean = static_cast<double>(sum) / static_cast<double>(qtd_elem);
        
        int curr_qtd_elem = qtd_elem / 2;
        if (qtd_elem & 1) {
            curr_qtd_elem++;
        }

        for (int i = 0; i < int{count.size()}; i++) {
            if (curr_qtd_elem - count[i] < 0) {
                median = i;
                break;
            } else if (curr_qtd_elem - count[i] == 0) {
                if (qtd_elem % 2 == 0) {
                    for (int j = i + 1; j < int{count.size()}; j++) {
                        if (count[j] > 0) {
                            median = static_cast<double>(i + j) / 2.0f;
                            break;
                        }
                    }
                } else {
                    median = i;
                }
                break;
            } else {
                curr_qtd_elem -= count[i];
            }
        }
        
        return {minimum, maximum, mean, median, mode};
    }
};
