class Solution {
public:
    
    void FindCombinations(int idx, const string& digits, vector<string>& combinations, const vector<vector<char> >& letters, string& curr) {
        if (idx == int{digits.size()}) {
            combinations.push_back(curr);
            return;
        }
        int c = digits[idx] - '1' - 1;
        for (int i = 0; i < int{letters[c].size()}; i++) {
            curr += letters[c][i];
            FindCombinations(idx + 1, digits, combinations, letters, curr);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (int{digits.size()} == 0) {
            return {};
        }
      vector<vector<char> > letters{{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<string> combinations;
        string curr = "";
        FindCombinations(0, digits, combinations, letters, curr);
        return combinations;
    }
};
