class Solution {
public:
    vector<vector<int> > dp;
    const int INF = 100000000;
    int solve(int idx, int opened, string &s){
        if(idx == (int)s.size())
            return opened == 0 ? 0 : INF;
        if(dp[idx][opened] != -1)
            return dp[idx][opened];
        
        char c = s[idx];
        int ans = (c == '(' || c == ')') + solve(idx + 1, opened, s);
        if(c == '(')
            ans = min(ans, solve(idx + 1, opened + 1, s));
        else if(c == ')' && opened)
            ans = min(ans, solve(idx + 1, opened - 1, s));
        
        return dp[idx][opened] = ans;
    }
    
    void path(int idx, int opened, string &s, vector<string> &a, string &p){
        if(idx == (int)s.size()){
            if(opened == 0)
                a.push_back(p);
            return;
        }
        
        char c = s[idx];
        int ans = solve(idx, opened, s);
        
        if(ans == (c == '(' || c == ')') + solve(idx + 1, opened, s)){
            if(c != '(' && c != ')')
                p += c;
            path(idx + 1, opened, s, a, p);
            if(c != '(' && c != ')')
                p.pop_back();
        }
        
        if(c == '('){
            if(ans == solve(idx + 1, opened + 1, s)){
                p += c;
                path(idx + 1, opened + 1, s, a, p);
                p.pop_back();
            }
            
        }else if(c == ')' && opened){
            if(ans == solve(idx + 1, opened - 1, s)){
                p += c;
                path(idx + 1, opened - 1, s, a, p);
                p.pop_back();
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        dp.resize((int)s.size() + 1);
        for(int i = 0; i < (int)s.size() + 1; i++){
            dp[i].resize((int)s.size() + 1, -1);
        }
        int minimum = solve(0, 0, s);
        
        printf("minimum = %d\n", minimum);
        vector<string> a;
        string p;
        path(0, 0, s, a, p);
        sort(a.begin(), a.end());
        a.resize(distance(a.begin(), unique(a.begin(), a.end())));
        return a;
    }
};
