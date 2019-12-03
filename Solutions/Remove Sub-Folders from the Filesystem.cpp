class Solution {
public:
    bool isSubFolder(string& subfolder, string& folder) {
        if (subfolder.size() <= folder.size()) {
            return false;
        }
        for (int i = 0; i < folder.size(); i++) {
            if (folder[i] != subfolder[i]) {
                return false;
            }
        }
        return subfolder[folder.size()] == '/';
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> st;
        for (string& s : folder) {
            if (st.empty()) {
                st.push_back(s);
            } else {
                if (!isSubFolder(s, st[st.size() - 1])) {
                    st.push_back(s);
                }
            }
        }
        
        return st;
    }
};
