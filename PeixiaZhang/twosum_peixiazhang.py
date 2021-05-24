"""Two sum function"""

from typing import List


class Solution:
    """Summmary of class here"""

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """Defined for two sum function.
        :param nums: int list
        :param target: int target
        :return: List[int] subscript response
        """

        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]

        return []


if __name__ == '__main__':
    sum = Solution()
    sum.twoSum([3, 2, 4], 6)
