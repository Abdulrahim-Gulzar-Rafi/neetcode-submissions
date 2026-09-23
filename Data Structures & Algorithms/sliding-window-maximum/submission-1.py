class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        ans = []
        n = len(nums)
        for it in range(n):

            # remove the elements/indexes that are outside the left boundary
            if dq and dq[0] <= it - k:
                dq.popleft()

            # insert biggest at the right
            while dq and nums[it] >= nums[dq[-1]]:
                dq.pop()
            dq.append(it)

            # add to answer
            if it >= k-1:
                 ans.append(nums[dq[0]])

        return ans