class Solution {
public:
    struct P {
        string name;
        int time, amount;
        string city;
        P(string a, int b, int c, string d) {
            name = a;
            time = b;
            amount = c;
            city = d;
        }
    };
    
    P Split(string& s) {
        int i = 0;
        string name = "";
        int amount = 0, time = 0;
        string city = "";
        for (i = 0; s[i] != ','; i++) {
            name += s[i];
        }
        i++;
        for (; s[i] != ','; i++) {
            time *= 10;
            time += (s[i] - '0');
        }
        i++;
        for (; s[i] != ','; i++) {
            amount *= 10;
            amount += (s[i] - '0');
        }
        i++;
        for (; i < s.size(); i++) {
            city += s[i];
        }
        return {name, time, amount, city};
    }
    
    bool ok(P& a, P& b) {
        int c = abs(a.time - b.time);
        if (c > 60) return true;
        if (a.name != b.name) return true;
        return a.city == b.city;
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<P> v;
        for (string& s : transactions) {
            v.push_back(Split(s));
        }
        set<int> ss;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].amount > 1000) {
                ss.insert(i);
                //continue;
            }
            for (int j = i + 1; j < v.size(); j++) {
                if (!ok(v[i], v[j])) {
                    ss.insert(i);
                    ss.insert(j);
                }
            }
        }
        vector<string> ans;
        for (auto i : ss) {
            ans.push_back(transactions[i]);
        }
        return ans;
    }
};
