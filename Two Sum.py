class Solution(object):

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        for i in range(len(nums)):
            diff = target - nums[i]
            for j in range(i + 1, len(nums)):
                if nums[j] == diff:
                    return [i, j]


nums = [3, 2, 4]
target = 6
sol = Solution()
print(sol.twoSum(nums, target))
