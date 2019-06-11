class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = (int)g.size() - 1;
        int answer = 0;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            while (index >= 0 && g[index] > s[i]) {
                index--;
            }
            if (index >= 0) { // assign s[i] to children with g[i]
                answer++;
                index--;
            }
        }
        return answer;
    }
};
