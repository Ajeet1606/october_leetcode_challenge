class Solution(object):
    def largestPerimeter(self, nums):
        i = 0
        nums = sorted(nums)[::-1]
        for i in range(len(nums) - 2):
            if nums[i] < nums[i + 1] + nums[i + 2]:
                return nums[i] + nums[i + 1] + nums[i + 2]
        return 0
