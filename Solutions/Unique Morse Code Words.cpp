class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> char_to_morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        string at = "";
        unordered_set<string> different;
        for (string &s : words) {
            at = "";
            for (char &c : s) {
                at += char_to_morse[c - 'a'];
            }
            different.insert(at);
        }
        return (int)different.size();
    }
};
