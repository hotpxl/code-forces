class Solution(object):
    def __init__(self):
        self.m = 0

    def updateMax(self, m):
        if self.m < m:
            self.m = m

    def lengthOfLongestSubstring(self, s):
        exist = {}
        j = 0
        for i in range(len(s)):
            if s[i] in exist:
                while s[i] in exist:
                    del exist[s[j]]
                    j += 1
            exist[s[i]] = True
            self.updateMax(i - j + 1)
        return self.m

if __name__ == '__main__':
    a = Solution()
    print(a.lengthOfLongestSubstring('abcabcbb'))
    a = Solution()
    print(a.lengthOfLongestSubstring('bbbbb'))
