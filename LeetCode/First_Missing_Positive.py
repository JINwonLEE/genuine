class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 0 < nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                tmp = nums[i]
                nums[i] = nums[tmp - 1]
                nums[tmp - 1] = tmp

        ans = n + 1
        for i in range(n):
            if nums[i] != i + 1:
                ans = i + 1
                break                    
                
        return ans
