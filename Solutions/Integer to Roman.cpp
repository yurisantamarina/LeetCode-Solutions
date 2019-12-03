class Solution {
public:
    vector<pair<int, char>> values{{1000, 'M'}, {500, 'D'}, {100, 'C'}, {50, 'L'}, {10, 'X'}, {5, 'V'}, {1, 'I'}};
    map<char, int> keys{{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    void GetRomanRepresentation(int n, string& s) {
        bool fst = true;
        for (int i = 0; i < values.size(); i++) {
            if (values[i].first <= n) {
                int qtd = n / values[i].first;
                if (qtd > 3) {
                    char x = s.back();
                    if (!fst) {
                        s.pop_back();
                        n += keys[x];
                    }
                    if (i > 1 && values[i - 2].first - values[i].first == qtd * values[i].first + keys[x]) {
                        s += string(1, values[i].second) + string(1, values[i - 2].second);
                    } else if (i > 0 && values[i - 1].first - values[i].first == qtd * values[i].first) {
                        s += string(1, values[i].second) + string(1, values[i - 1].second);
                    }
                    n -= qtd * values[i].first;
                    n -= keys[x];
                } else {
                    n -= qtd * values[i].first;
                    s += string(qtd, values[i].second);
                }
                fst = false;
            }
        }
    }
    string intToRoman(int num) {
        string s = to_string(num);
        int pot10[4] = {1, 10, 100, 1000};
        string roman = "";
        for (int i = 0; i < s.size(); i++) {
            GetRomanRepresentation((s[i] - '0') * pot10[s.size() - i - 1], roman);
        }
        return roman;
    }
};
