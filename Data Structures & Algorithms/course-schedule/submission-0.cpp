class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (vector edge: prerequisites) {
            graph[edge[0]].insert(edge[1]);
        }

        vector<int> valid(numCourses, -1);
        unordered_set<int> seen;

        auto dfs = [&](auto&& self, int node) -> bool {
            if (seen.count(node)) {
                valid[node] = 0;
                return false;
            }
            bool check = true;
            seen.insert(node);
            for (int neighbour: graph[node]) {
                if (valid[neighbour] == 1) {
                    continue;
                } else if (valid[neighbour] == 0) {
                    return false;
                }
                check = check && self(self, neighbour);
                if (!check) {
                    return false;
                }
            }
            valid[node] = 1;
            return true;
        };

        for (int node = 0; node < numCourses; node++) {
            seen.clear();
            bool check = dfs(dfs, node);
            if (!check) {
                return false;
            }
        }

        return true;
    }
};
