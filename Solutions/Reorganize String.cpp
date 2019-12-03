class Solution {
public:
    bool FindNextLetter(char lst_letter, unordered_map<char, int>* count, char* next_letter) {
        char letter_with_max_count = '0';
        for (auto i : *count) {
            if (i.first == lst_letter) {
                continue;
            }
            if (letter_with_max_count == '0' || i.second > (*count)[letter_with_max_count]) {
                letter_with_max_count = i.first;
            }
        }
        if (letter_with_max_count == '0') {
            return false;
        }
        *next_letter = letter_with_max_count;
        (*count)[letter_with_max_count]--;
        if ((*count)[letter_with_max_count] == 0) {
            count->erase(letter_with_max_count);
        }
        return true;
    }
    string reorganizeString(string S) {
        unordered_map<char, int> count;
        for (char c : S) {
            count[c]++;
        }
        string reorganized = "";
        char lst_letter = '0';
        char next_letter;
        for (int i = 0; i < S.size(); i++) {
            if (FindNextLetter(lst_letter, &count, &next_letter)) {
                reorganized += next_letter;
                lst_letter = next_letter;
            } else {
                return "";
            }
        }
        return reorganized;
    }
};
