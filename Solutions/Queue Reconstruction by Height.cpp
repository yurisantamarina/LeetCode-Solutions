class Solution {
public:
    vector<int> available;
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        available.resize(people.size(), 1);
        vector<vector<int>> answer(people.size());
        
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        for (int i = 0; i < people.size(); i++) {
            int av = -1;
            for (int j = 0; j < people.size(); j++) {
                av += available[j];
                if (av == people[i][1]) {
                    answer[j] = people[i];
                    available[j] = 0;
                    break;
                }
            }
        }
        return answer;
    }
};
