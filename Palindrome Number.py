class Solution(object):

    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s = str(x)
        left = 0
        right = len(s) - 1
        middle = len(s) // 2
        while left < middle:
            if s[left] != s[right]:
                return False
            left = left + 1
            right = right - 1
        return True


x = 121
sol = Solution()
print(sol.isPalindrome(x))
