class Solution:
    def maxSubArray(self, nums):
        ans = -inf
        cur_sum = 0
        for i in range(len(nums)):
            cur_sum += nums[i]
            if cur_sum > ans:
                ans = cur_sum
            if cur_sum < 0:
                cur_sum = 0
        return ans
