class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> prv((int)seats.size(), 0);
        vector<int> nxt((int)seats.size(), 0);
        const int INF = 100000000;
        int ans = 0;
        
        if(seats[0] == 1) prv[0] = 0;
        else prv[0] = -1;
        for(int i = 1; i < (int)seats.size(); i++){
            if(seats[i] == 0){
                prv[i] = prv[i - 1];
            }else{
                prv[i] = i;
            }
        }
        
        
        if(seats[(int)seats.size() - 1] == 1) nxt[(int)seats.size() - 1] = (int)seats.size() - 1;
        else nxt[(int)seats.size() - 1] = -1;
        for(int i = (int)seats.size() - 2; i >= 0; i--){
            if(seats[i] == 0){
                nxt[i] = nxt[i + 1];
            }else{
                nxt[i] = i;
            }
            
            
        }
        
        for(int i = 0; i < (int)seats.size(); i++){
           // cout << nxt[i] << " ";
            if(seats[i] == 0){
                if(prv[i] == -1){
                    ans = max(ans, nxt[i] - i);
                }else if(nxt[i] == -1){
                    ans = max(ans,i - prv[i]);
                }else{
                    ans = max(ans, min(nxt[i] - i, i - prv[i]));
                }
            }
        }
        
        return ans;
    }
};
