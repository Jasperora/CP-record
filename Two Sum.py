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

    def twoPassHashTwoSum(self, nums, target):
        numMap = {}
        for i in range(len(nums)):
            numMap[nums[i]] = i
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in numMap.keys() and numMap[diff] != i:
                return [i, numMap[diff]]
        return []

    def onePassHashTwoSum(self, nums, target):
        numMap = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in numMap.keys():
                return [i, numMap[diff]]
            numMap[nums[i]] = i
        return []


nums = [3, 2, 4]
target = 6
sol = Solution()
print(sol.twoPassHashTwoSum(nums, target))
