class Solution:
    def __merge(self, nums, head, mid, tail):
        tmp = []
        for i in range(head, mid + 1, 1):
            tmp.append(nums[i])
        
        i = head
        j = mid + 1
        for k in range(head, tail + 1, 1):
            if i > mid:
                nums[k] = nums[j]
                j += 1
            elif j > tail:
                nums[k] = tmp[i - head]
                i += 1
            elif tmp[i - head] < nums[j]:
                nums[k] = tmp[i - head]
                i += 1
            else:
                nums[k] = nums[j]
                j += 1
    
    def __mergeSort(self, nums, head, tail):
        if head >= tail:
            return
        
        mid = head + (tail - head) // 2
        self.__mergeSort(nums, head, mid)
        self.__mergeSort(nums, mid + 1, tail)
        self.__merge(nums, head, mid, tail)
    
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        self.__mergeSort(nums, 0, len(nums) - 1)
   
   
if __name__ == '__main__':
    s = Solution()
    nums = [2,0,1,2,1,2,1,0,1,0,1,2,1]
    s.sortColors(nums)
    print (nums)