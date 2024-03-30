class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m1, m2 = 0, 0
        i, j = 0, 0
        l1, l2 = len(nums1), len(nums2)
        med = (l1 + l2) // 2
        for ind in range(med+1):
            m1 = m2
            if i != l1 and j != l2:
                if nums1[i] >= nums2[j]:
                    m2 = nums2[j]
                    j += 1
                else:
                    m2 = nums1[i]
                    i += 1
            elif i < l1:
                m2 = nums1[i]
                i += 1
            elif j < l2:
                m2 = nums2[j]
                j += 1
        if (l1 + l2) % 2 == 0:
            mnum = (m1 + m2) / 2.0
        else:
            mnum = m2
        return mnum

