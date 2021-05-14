/*两个有序整数数组 nums1 和 nums2，请将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
假设：
    初始化 nums1 和 nums2 的元素数量分别为 m 和 n
    nums1 的空间大小等于 m + n，有足够的空间保存来自 nums2 的元素。

示例 1： 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        输出：[1,2,2,3,5,6]
示例 2： 输入：nums1 = [1], m = 1, nums2 = [], n = 0
        输出：[1]
*/

#include "stdio.h"

#define NUM1_SIZE   (6u)
#define NUM2_SIZE   (3u)
#define MAX_ARRAY_SIZE (NUM1_SIZE+NUM2_SIZE)

void merge(int* nums1, int m, int* nums2, int n)
{
    //fill your code here
	int i,j=0;
	for(i=m;i<m+n;i++)
	{
		nums1[i]=nums2[j++];
	}
	int temp=0;
	int exchange=0;
	for(i=0;i<m+n-1;i++)
	{
		for(j=m+n-1;j>=i;j--)
		{
			if(nums1[j+1]<nums1[j])
			{
				temp=nums1[j];
				nums1[j]=nums1[j+1];
				nums1[j+1]=temp;
				exchange=1;
			}
		}
		if(exchange!=1)
			break;
	}
}

int main(void)
{
    int num1[MAX_ARRAY_SIZE] = {1, 2, 2, 4, 7, 9};
    int num2[NUM2_SIZE] = { 3, 5, 8};

    merge(num1, NUM1_SIZE, num2, NUM2_SIZE);

    printf("Merge Result:\n ");
    for(int i=0; i<MAX_ARRAY_SIZE; i++)
    {
        printf("%d ", num1[i]);
    }
    printf("\n\n ");
	return 0;
}
