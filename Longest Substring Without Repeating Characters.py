class Solution(object):

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = 0
        right = 0
        charSet = set()
        ans = 0
        while right <= len(s) - 1:
            if s[right] not in charSet:
                charSet.add(s[right])
                length = right - left + 1
                if length > ans:
                    ans = length
            else:
                while s[right] in charSet:
                    charSet.remove(s[left])
                    left = left + 1
                charSet.add(s[right])
            right = right + 1
        return ans


s = "pwwkewa"
sol = Solution()
print(sol.lengthOfLongestSubstring(s))
