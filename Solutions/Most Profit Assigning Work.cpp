class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int job_idx = 0;
        int max_profit = 0;
        int answer = 0;
        for (int i = 0; i < worker.size(); i++) {
            while (job_idx < jobs.size() && jobs[job_idx].first <= worker[i]) {
                max_profit = max(max_profit, jobs[job_idx].second);
                job_idx++;
            }
            answer += max_profit;
        }
        return answer;
    }
};
