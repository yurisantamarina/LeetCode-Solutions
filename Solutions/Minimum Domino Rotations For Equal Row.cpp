class Solution {
public:
    #define UP 0
    #define DOWN 1
    int test(vector<int>& A, vector<int>& B, int e, bool FLAG){
        int ans = 0;
        int a, b;
        for(int i = 0; i < (int)A.size(); i++){
            a = FLAG ? A[i] : B[i];
            b = FLAG ? B[i] : A[i];
            if(a == e)
                continue;
            else if(b == e){
                ans++;
            }else
                return INT_MAX;
        }
        return ans;
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans = INT_MAX;
        
        ans = min(ans, test(A, B, A[0], UP));
        ans = min(ans, test(A, B, B[0], UP));
        ans = min(ans, test(A, B, A[0], DOWN));
        ans = min(ans, test(A, B, B[0], DOWN));
        
        return ans == INT_MAX ? -1 : ans;
    }
};
