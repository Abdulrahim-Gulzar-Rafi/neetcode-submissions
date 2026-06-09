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
    int splitArray(vector<int>& nums, int k) {
        int left = nums[0], right = 0;
        for (const int& i: nums) {
            if (i > left) {
                left = i;
            }
            right += i;
        }
        int mid = right;
        int res = mid;
        while (left <= right) {
            mid = (left + right) / 2;
            int subarrays = 1, subarray_sum = 0;
            for (const int& i: nums) {
                subarray_sum += i;
                if (subarray_sum > mid) {
                    subarrays ++ ;
                    subarray_sum = i;
                }
            }
            if (subarrays <= k) {
                res = mid;
                right = mid-1;
            } else if (subarrays > k) {
                left = mid + 1;
            }
        }
        int max_subarray = INT_MIN;
        int subarray_sum = 0;
        for (const int& i: nums) {
            subarray_sum += i;
            if (subarray_sum > res) {
                subarray_sum = i;
            }
            max_subarray = max(max_subarray, subarray_sum);
        }
        return max_subarray;
    }
};
