template<typename Func>
class YCombinator {
    Func func;

public:
    explicit YCombinator(Func &&f): func(forward<Func>(f)) {
    }

    template<typename... Args>
    decltype(auto) operator()(Args &&... args) const {
        return func(*this, forward<Args>(args)...);
    }
};

template<typename Func>
auto make_y_combinator(Func &&f) {
    return YCombinator<decay_t<Func> >(forward<Func>(f));
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto binary_search = make_y_combinator([](auto self, vector<int> nums, int left, int right, int target) -> int {
            if (left > right) return -1;
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) return self(nums, mid + 1, right, target);
            else return self(nums, left, mid -1, target);
        });
        return binary_search(nums, 0, nums.size() -1, target);

    }
};