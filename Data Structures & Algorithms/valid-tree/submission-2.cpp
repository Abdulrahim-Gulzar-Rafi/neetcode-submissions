class UndirectedUnweightedGraph {
    vector<vector<int>> adjList;
    int nodes;
public:
    UndirectedUnweightedGraph(int n, vector<vector<int>> edges) {
        this->nodes = n;
        this->adjList.resize(n);
        for (auto edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
    }

    vector<int> getNeighours(int node) {
        return adjList[node];
    }

};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> seen;
        // let root = 0
        int root = 0;
        // perform bfs

        UndirectedUnweightedGraph g{n, edges};

        deque<pair<int,int>> dq;
        dq.push_back({0, 0}); // {child, parent}
        while (!dq.empty()) {
            auto [child, parent] = dq.front();
            if (seen.count(child)) {
                return false;
            }
            dq.pop_front();
            seen.insert(child);
            for (int neighbour: g.getNeighours(child)) {
                if (neighbour == parent) {
                    continue; // because we just came from the parent. (a level above)
                }
                dq.push_back({neighbour, child}); // neighbour is the new child, child is the new parent
            }
        }
        for (int i = 0; i < n; i++) {
            if (!seen.count(i)) {
                return false;
            }
        }
        return true;
    }
};
