class Solution {
public:
    int toInt(string& s){
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
        
        return negative ? -number : number;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a = 0, b = 0;
        for (string& s : tokens) {
            if ((int)s.size() == 1 && (s[0] < '0' || s[0] > '9')) {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                
                if (s[0] == '+') a = a + b;
                if (s[0] == '-') a = a - b;
                if (s[0] == '*') a = a * b;
                if (s[0] == '/') a = a / b;
                
                st.push(a);
            } else {
                st.push(toInt(s));
            }
        }
        return st.top();
    }
};
