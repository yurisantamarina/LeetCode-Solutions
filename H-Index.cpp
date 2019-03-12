class Solution {
public:
    int getLessOrEqual(vector<int> &citations, int h){
        return (int)citations.size() - (int)(citations.end() - upper_bound(citations.begin(), citations.end(), h));
    }
    int getGreterOrEqual(vector<int> &citations, int h){
        return (int)citations.size() - (int)(lower_bound(citations.begin(), citations.end(), h) - citations.begin());
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int greaterOrEqual, lessOrEqual;
        int ans = 0;
        for(int h = 1; h <= (int)citations.size(); h++){
            lessOrEqual = getLessOrEqual(citations, h);
            greaterOrEqual = getGreterOrEqual(citations, h);
            //cout << "h = " << h << " less = " << lessOrEqual << " greater = " << greaterOrEqual << endl;
            if(greaterOrEqual >= h){
                ans = h;
            }
        }
        
        return ans;
    }
};
