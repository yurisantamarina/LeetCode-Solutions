class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string popped_string;
        for (char& c : s) {
            if (c == ')') {
                popped_string = "";
                while (st.top() != '(') {
                    popped_string += st.top();
                    st.pop();
                }
                st.pop();
                for (char& popped_char : popped_string) {
                    st.push(popped_char);
                }
            } else {
                st.push(c);
            }
        }
        popped_string = "";
        while (!st.empty()) {
            popped_string += st.top();
            st.pop();
        }
        reverse(popped_string.begin(), popped_string.end());
        return popped_string;
    }
};
