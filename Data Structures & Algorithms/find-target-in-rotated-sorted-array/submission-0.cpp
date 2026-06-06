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
        auto perform_binary_search = make_y_combinator([](auto self, vector<int> arr, int left, int right, int target, int n) -> int {
            if (left <= right) {
                int mid = (left + right) / 2;
                return (arr[mid] == target)
                    ? mid
                    : (arr[left] < arr[right])
                        ? (target < arr[mid]) ? self(arr, left, mid - 1, target, n) : self(arr, mid + 1, right, target, n)
                        : (arr[mid] < arr[right])
                            ? ((target < arr[mid]) ? self(arr, left, mid - 1, target, n) : (target <= arr[right]) ? self(arr, mid + 1, right, target, n) :self(arr, left, mid - 1, target, n) )
                            : (target < arr[mid])
                                ? (target >= arr[left]) ? self(arr, left, mid - 1, target, n) : self(arr, mid + 1, right, target, n)
                                : self(arr, mid + 1, right, target, n);
            }
            return -1;
        });
        int n = static_cast<int>(nums.size());
        return perform_binary_search(nums, 0, n - 1, target, n);

    }
};