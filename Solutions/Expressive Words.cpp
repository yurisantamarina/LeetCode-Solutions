class Solution {
public:
    vector<pair<char, int> > unique(string& s) {
        vector<pair<char, int> > freq;
        int cnt = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (i > 0 && s[i] != s[i - 1]) {
                freq.push_back({s[i - 1], cnt});
                cnt = 1;
            } else {
                cnt++;
            }
        }
        freq.push_back({s.back(), cnt});
        return freq;
    }
    
    bool can(vector<pair<char, int> >& freq, vector<pair<char, int> >& at_freq) {
        if ((int)freq.size() != (int)at_freq.size()) return false;
        
        for (int i = 0; i < (int)freq.size(); i++) {
            if (freq[i].first != at_freq[i].first) return false;
            if (freq[i].second < at_freq[i].second) return false;
            if (freq[i].second != at_freq[i].second && freq[i].second < 3) return false; 
        }
        return true;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char, int> > freq = unique(S);
        
        vector<pair<char, int> > at_freq;
        int answer = 0;
        for (string& a : words) {
            at_freq = unique(a);
            if (can(freq, at_freq)) answer++;
        }
        return answer;
    }
};
