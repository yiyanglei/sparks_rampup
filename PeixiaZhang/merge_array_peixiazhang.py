"""Merge array and sort function"""
from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int):
        """
        Put array2 at the end of array1, and sort entire array.
        """
        nums1[m:] = nums2
        nums1.sort()
        print("Merge Result:", nums1)

if __name__ == '__main__':
    merge_array = Solution()
    merge_array.merge([1,2,3,0,0,0], 3, [2,5,6], 3)
