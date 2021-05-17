'''两个有序整数数组 nums1 和 nums2，请将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
假设：
    初始化 nums1 和 nums2 的元素数量分别为 m 和 n
    nums1 的空间大小等于 m + n，有足够的空间保存来自 nums2 的元素。

示例 1： 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        输出：[1,2,2,3,5,6]
示例 2： 输入：nums1 = [1], m = 1, nums2 = [], n = 0
        输出：[1]
'''
<<<<<<< Updated upstream


def merge(nums1, m, nums2, n):
    n1 = 0
    n2 = 0
    list = []
    while n1 < m and n2 < n:
        if nums1[n1] <= nums2[n2]:
            list.append(nums1[n1])
            n1 += 1
        else:
            list.append(nums2[n2])
            n2 += 1
    print(list)


if __name__ == '__main__':
    nums1 = [1, 2, 2, 4, 7, 9]
    m = 6
    nums2 = [3, 5, 8]
    n = 3
    merge(nums1, m, nums2, n)
=======
>>>>>>> Stashed changes
