class Solution {
public:
    
    class Dsu {
    private:
        vector<int> parent;
    public:
        Dsu() {
            parent.resize(26);
            for (int i = 0; i < 26; i++) {
                parent[i] = i;
            }
        }
        
        int Find(int var) {
            return parent[var] = parent[var] == var ? var : Find(parent[var]);
        }
        
        void Join(int var1, int var2) {
            var1 = Find(var1);
            var2 = Find(var2);
            parent[var1] = var2;
        }
        
        bool Same(int var1, int var2) {
            return Find(var1) == Find(var2);
        }
        
    };
    
    bool equationsPossible(vector<string>& equations) {
        Dsu dsu;
        for (const string& equation : equations) {
            if (equation[1] == '=') {
                dsu.Join(equation[0] - 'a', equation[3] - 'a');
            }
        }
        
        for (const string& equation : equations) {
            if (equation[1] == '!' && dsu.Same(equation[0] - 'a', equation[3] - 'a')) {
                return false;
            }
        }
        
        return true;
    }
};
