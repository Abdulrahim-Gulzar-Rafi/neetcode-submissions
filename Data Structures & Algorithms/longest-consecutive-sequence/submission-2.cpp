
template<typename Func>
class FixedPointCombinator {
    Func func;

public:
    explicit FixedPointCombinator(Func &&f): func(forward<Func>(f)) {
    }

    template<typename... Args>
    decltype(auto) operator()(Args &&... args) const { return func(*this, forward<Args>(args)...); }
};

template<typename Func>
auto make_fixed_point_combinator(Func &&f) -> decltype(FixedPointCombinator<std::decay_t<Func> >(forward<Func>(f))) { return FixedPointCombinator<decay_t<Func> >(forward<Func>(f)); }

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int i: nums) {
            mp[i] = 0;
        }
        int max_subsequence = 0;
        auto perform_dfs = make_fixed_point_combinator([&](auto self, int j) -> int {
            if (mp.count(j)) {
                if (mp[j] == 0) {
                    int front = self(j + 1) + 1;
                    mp[j] = front;
                    return front;
                }
                return mp[j];
            }
            return 0;
        });
        for (int i: nums) {
            if (mp.count(i) && mp[i] == 0) {
                int total = perform_dfs(i);
                max_subsequence = max(max_subsequence, total);
            }
        }
        return max_subsequence;
    }
};
