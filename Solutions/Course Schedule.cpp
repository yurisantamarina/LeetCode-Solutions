class Solution {
public:
    
    enum State {UNVISITED, IN_STACK, VISITED};
    
    bool IsThereACycle(int course, const vector<vector<int> >& graph, vector<char>& seen) {
        seen[course] = State::IN_STACK;
        
        bool cycle = false;
        for (const int& prerequisite : graph[course]) {
            if (seen[prerequisite] == State::UNVISITED) {
                cycle |= IsThereACycle(prerequisite, graph, seen);
            } else if (seen[prerequisite] == State::IN_STACK) {
                return true;
            }
        }
        
        seen[course] = State::VISITED;
        return cycle;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph((int)numCourses);
        for (const vector<int>& edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        vector<char> seen(numCourses, State::UNVISITED);
        bool cycle = false;
        for (int course = 0; course < numCourses; course++) {
            if (seen[course] == State::UNVISITED) {
                cycle |= IsThereACycle(course, graph, seen);
            }
        }
        
        return cycle ? false : true;
    }
};
