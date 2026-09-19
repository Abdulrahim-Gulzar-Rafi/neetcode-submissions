class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left, right = 0, 0
        n = len(nums)
        min_len = n + 1
        sum = 0

        while left < n:
            while right < n and sum < target and right - left <= min_len:
                sum += nums[right]
                right += 1

            if sum >= target and right - left + 1 <= min_len:
                min_len = min(min_len, right - left)

            sum -= nums[left]
            left += 1

        return 0 if min_len == n + 1 else min_len
