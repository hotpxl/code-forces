class Solution(object):
    def isMedian(self, nums1, nums2, i):
        j = (len(nums1) + len(nums2) - 1) / 2 - i
        if len(nums2) == 0:
            if j == 0:
                return 0
            if j < 0:
                return 1
            if 0 < j:
                return -1
        if j < 0:
            return 1
        if len(nums2) < j:
            return -1
        if j == 0:
            if nums1[i] <= nums2[0]:
                return 0
            else:
                return 1
        if j == len(nums2):
            if nums2[-1] <= nums1[i]:
                return 0
            else:
                return -1
        if nums1[i] < nums2[j - 1]:
            return -1
        if nums2[j] < nums1[i]:
            return 1
        return 0

    def findMedianSortedArraysOdd(self, nums1, nums2):
        start = 0
        end = len(nums1) - 1
        while start <= end:
            mid = (start + end) / 2
            r = self.isMedian(nums1, nums2, mid)
            if r == 0:
                return nums1[mid]
            if r == 1:
                end = mid - 1
            else:
                start = mid + 1
        return self.findMedianSortedArraysOdd(nums2, nums1)

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if (len(nums1) + len(nums2)) % 2 == 1:
            return self.findMedianSortedArraysOdd(nums1, nums2)
        else:
            m0 = None if len(nums1) == 0 else nums1[0]
            m1 = None if len(nums2) == 0 else nums2[0]
            if m0 is None and m1 is None:
                return None
            else:
                m = min(m0, m1)
            nums1.insert(0, m)
            median0 = self.findMedianSortedArraysOdd(nums1, nums2)
            nums1 = nums1[1:]
            m0 = None if len(nums1) == 0 else nums1[-1]
            m1 = None if len(nums2) == 0 else nums2[-1]
            if m0 is None and m1 is None:
                return None
            else:
                m = max(m0, m1)
            nums1.append(m)
            median1 = self.findMedianSortedArraysOdd(nums1, nums2)
            return (median0 + median1) / 2.0

