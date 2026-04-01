class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while nums[i]-1 >= 0 and nums[i]-1 < n:
                swap1 = i
                swap2 = nums[i] - 1
                if swap1 != swap2 and nums[swap1] != nums[swap2]:
                    nums[swap1], nums[swap2] = nums[swap2], nums[swap1]
                else:
                    break
        for i in range(n):
            if i+1 != nums[i]:
                return i + 1
        return nums[-1] + 1
