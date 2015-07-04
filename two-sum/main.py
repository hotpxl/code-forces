class Solution(object):
    def binarySearch(self, target, array, left, right):
        if left < right:
            mid = (left + right) / 2
            if target <= array[mid]:
                return self.binarySearch(target, array, left, mid)
            else:
                return self.binarySearch(target, array, mid + 1, right)
        else:
            return left

    def linearSearch(self, target, array, reverse=False):
        r = range(len(array))
        if reverse:
            r = reversed(r)
        for i in r:
            if array[i] == target:
                return i

    def twoSum(self, nums, target):
        sortedNums = sorted(nums)
        for i in range(len(sortedNums)):
            m = self.binarySearch(
                target - sortedNums[i], sortedNums, i + 1, len(sortedNums))
            if m < len(sortedNums) and sortedNums[i] + sortedNums[m] == target:
                ret = []
                ret.append(self.linearSearch(
                    sortedNums[i], nums) + 1)
                ret.append(self.linearSearch(
                    sortedNums[m], nums, True) + 1)
                return sorted(ret)

if __name__ == '__main__':
    s = Solution()
    print s.twoSum([0, 4, 3, 0], 0)
