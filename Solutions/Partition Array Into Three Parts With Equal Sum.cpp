class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = (int)A.size();
        int sum = 0, found1 = -1, found2 = -1;
        for (int i = n - 1; i >= 0; i--){
            sum += A[i];
        }
        if (sum % 3 != 0) return false;
        int at = 0;
        for (int i = 0; i < n; i++){
            at += A[i];
            if(at == sum / 3) {
                found1 = i;
                break;
            }
        }
        
        at = 0;
        for (int i = n - 1; i >= 0; i--){
            at += A[i];
            if (at == sum / 3) {
                found2 = i;
                break;
            }
        }
        
        if (found1 == -1 || found2 == -1) return false;
        return found1 + 1 < found2;
    }
};
