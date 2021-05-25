"""Merge array and sort function"""

from typing import List


class Solution:
    """..."""

    def merge(self, nums1: List[int], m: int, nums2: List[int]) -> List[int]:
        """Define for merge two array and sort function.
        :param nums1: int list array1
        :param m: array1 number
        :param nums2: int list array2
        :return: int list
        """

        nums1[m:] = nums2
        nums1.sort()
        return nums1


if __name__ == '__main__':
    merge_array = Solution()
    print(merge_array.merge([1,2,3,0,0,0], 3, [2,5,6]))
