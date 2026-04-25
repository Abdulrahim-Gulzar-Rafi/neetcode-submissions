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
    bool validPalindrome(string s) {
        auto search = make_fixed_point_combinator([&](auto self, int i, int j, bool removed) -> bool {
            if (i <= j) {
                if (s[i] != s[j]) {
                    if (removed) {
                        return false;
                    }
                    removed = true;
                    return self(i+1, j, removed) || self(i, j-1, removed);
                }
                return self(i+1, j-1, removed);
            }
            return true;
        });
        return search(0, static_cast<int>(s.size())-1, false);

    }
};