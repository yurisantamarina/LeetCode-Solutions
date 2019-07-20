class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> rocks;
        for (int& rock : stones) {
            rocks.push(rock);
        }
        
        while (int{rocks.size()} > 1) {
            int y = rocks.top();
            rocks.pop();
            int x = rocks.top();
            rocks.pop();
            
            if (x != y) {
                rocks.push(y - x);
            }
        }
        
        return int{rocks.size()} == 0 ? 0 : rocks.top();
    }
};
