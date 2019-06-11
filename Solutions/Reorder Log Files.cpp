class Solution {
public:
    class Log {
    public:
        string id;
        string words;
        Log() {}
        Log(const string& id_, const string& words_) {
            this->id = string(id_);
            this->words = string(words_);
        }
        bool operator < (const Log& other) const {
            if (words == other.words) {
                return id < other.id;
            }
            return words < other.words;
        }
    };
    
    bool Digit(char c) {
        return c >= '0' && c <= '9';
    }
    
    pair<string, string> SplitLog(const string& log) {
        for (int i = 0; i < (int)log.size(); i++) {
            if (log[i] == ' ') {
                return {log.substr(0, i), log.substr(i + 1)};
            }
        }
            
        return {"", ""};
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<Log> only_letters, only_digits;
        
        for (const string& log : logs) {
            pair<string, string> splitted_log = SplitLog(log);
            Log new_log(splitted_log.first, splitted_log.second);
            if (Digit(splitted_log.second[0])) {
                only_digits.push_back(new_log);
            } else {
                only_letters.push_back(new_log);
            }
        }
        
        sort(only_letters.begin(), only_letters.end());
        
        vector<string> answer;
        
        for (const Log& log : only_letters) {
            answer.push_back(log.id + " " + log.words);
        }
        for (const Log& log : only_digits) {
            answer.push_back(log.id + " " + log.words);
        }
        
        return answer;
    }
};