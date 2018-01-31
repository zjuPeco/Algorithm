class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            min_val = nums[i]
            min_idx = i
            for j in range(i + 1, len(nums), 1):
                if nums[j] < nums[min_idx]:
                    min_val = nums[j]
                    min_idx = j
            nums[i], nums[min_idx] = nums[min_idx], nums[i]