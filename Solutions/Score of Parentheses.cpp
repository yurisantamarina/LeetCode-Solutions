class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<pair<char, int> > p;
        int sum = 0;
        for(char &c : S){
            if(c == '('){
                p.push({c, 0});
            }else{
                sum = 0;
                while(!p.empty() && p.top().first != '('){
                    sum += p.top().second;
                    p.pop();
                }
                p.pop();
                p.push({c, sum * 2 + (sum == 0)});
            }
        }
        sum = 0;
        while(!p.empty()){
            sum += p.top().second;
            p.pop();
        }
        return sum;
    }
};
