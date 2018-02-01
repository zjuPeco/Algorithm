class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            tmp = nums[i]
            for j in range(i, -1, -1):
                if 0 == j or nums[j - 1] <= tmp:
                    nums[j] = tmp
                    break
                else:
                    nums[j] = nums[j - 1]