"""Remove duplicates function"""

from typing import List


class Solution:
    """..."""

    def removeDuplicates(self, nums: List[int]) -> int:
        """
        :param nums: int list
        :return: List[int] response
        """
        if not nums:
            return 0

        n = len(nums)
        fast = slow = 1
        while fast < n:
            if nums[fast] != nums[fast - 1]:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1

        return slow


if __name__ == '__main__':
    duplicate = Solution()
    print(duplicate.removeDuplicates([1,1,2]))