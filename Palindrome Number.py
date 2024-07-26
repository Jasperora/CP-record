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

    def isPalindromeByReverse(self, x):
        if x < 0 or (x is not 0 and x % 10 == 0):
            return False
        reverse = 0
        while reverse < x:
            reverse = reverse * 10 + x % 10
            x = x // 10
        return (reverse == x) or (x == reverse // 10)


x = 10
sol = Solution()
print(sol.isPalindromeByReverse(x))
