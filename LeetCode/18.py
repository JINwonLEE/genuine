class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = set()
        nums.sort()
        l = len(nums)
        for i in range(l - 3):
            for j in range(i + 1, l - 2):
                tmp_target = target - nums[i] - nums[j]
                low = j + 1
                high = l - 1
                while low < high:
                    if nums[low] + nums[high] > tmp_target:
                        high -= 1
                    elif nums[low] + nums[high] < tmp_target:
                        low += 1
                    else:
                        ans.add((nums[i], nums[j], nums[low], nums[high]))
                        low += 1
                        high -= 1
        return  ans
