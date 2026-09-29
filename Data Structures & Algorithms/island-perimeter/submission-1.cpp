template<typename Func>
class FixedPointCombinator {
    Func func;

public:
    explicit FixedPointCombinator(Func &&f) : func(forward<Func>(f)) {
    }

    template<typename... Args>
    decltype(auto) operator()(Args &&... args) const { return func(*this, forward<Args>(args)...); }
};

template<typename Func>
auto make_fixed_point_combinator(Func &&f) -> decltype(FixedPointCombinator<std::decay_t<Func> >(forward<Func>(f))) {
    return FixedPointCombinator<decay_t<Func> >(forward<Func>(f));
}

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        pair head = {0,0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    head = {i,j};
                    break;
                }
            }
        }

        unordered_map<int,unordered_set<int>> mp;

        auto exists = [&](pair<int,int> node) -> bool {
            return mp.count(node.first) && mp[node.first].size() > 0 && mp[node.first].count(node.second);
        };

        int perimeter = 0;

        auto dfs = make_fixed_point_combinator([&](auto self, pair<int,int> node) -> void {
            if (exists(node) || node.first < 0 || node.second < 0 || node.first >= m || node.second >= n) {
                return;
            }
            mp[node.first].insert(node.second);
            node.first --;
            if (node.first < 0 || !grid[node.first][node.second]) {
                perimeter ++;
            } else {
                self(node);
            }
            node.first ++;
            node.first ++;
            if (node.first >= m || !grid[node.first][node.second]) {
                perimeter ++;
            } else {
                self(node);
            }
            node.first --;

            node.second --;
            if (node.second < 0 || !grid[node.first][node.second]) {
                perimeter ++;
            } else {
                self(node);
            }
            node.second ++;
            node.second ++;
            if (node.second >= n || !grid[node.first][node.second]) {
                perimeter ++;
            } else {
                self(node);
            }
            node.second --;
        });
        dfs(head);
        return perimeter;
    }
};