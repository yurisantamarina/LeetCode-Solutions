class Solution {
public:
    int to_int(string& s) {
        int number = 0;
        bool negative = false;
        for (char c : s) {
            if (c == '-') {
                negative = true;    
            } else {
                number *= 10;
                number += (c - '0');
            }
            
        }
        if (negative) number *= -1;
        return number;
    }
    
    int calPoints(vector<string>& ops) {
        vector<int> st;
        int a = 0, b = 0;
        for (string &s : ops) {
            if (s[0] == '+') {
                a = ((int)st.size() >= 2) ? st[(int)st.size() - 2] : 0;
                b = ((int)st.size() >= 1) ? st[(int)st.size() - 1] : 0;
                st.push_back(a + b);
            } else if (s[0] == 'D') {
                a = ((int)st.size() >= 1) ? st[(int)st.size() - 1] * 2 : 0;
                st.push_back(a);
            } else if (s[0] == 'C') {
                if ((int)st.size() >= 1) st.pop_back(); 
            } else {
                st.push_back(to_int(s));
            }
        }
        
        int answer = 0;
        for (int x : st) {
            answer += x;
        }
        return answer;
    }
};
