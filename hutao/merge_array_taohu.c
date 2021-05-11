/*两个有序整数数组 nums1 和 nums2，请将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
假设：
    初始化 nums1 和 nums2 的元素数量分别为 m 和 n
    nums1 的空间大小等于 m + n，有足够的空间保存来自 nums2 的元素。

示例 1： 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        输出：[1,2,2,3,5,6]

示例 2：输入：nums1 = [1], m = 1, nums2 = [], n = 0
        输出：[1]
*/

#include<stdio.h>
#include<stdlib.h>

#define NUM1_SIZE   (6u)
#define NUM2_SIZE   (3u)
#define MAX_ARRAY_SIZE (NUM1_SIZE+NUM2_SIZE)

void merge(int* nums1, int m, int* nums2, int n)
{
	int a[] = {NULL};
	if (n == 0 && m == 0) return;
	
	int i = m - 1, j = n - 1, k = m + n - 1;
	while ( i >= 0 && j >= 0 && k >=0 )
	{
		if ( nums1[i] >= nums2[j] )
		{
			nums1[k] = nums1[i];
			i--;
			k--;
		}
		else if ( nums1[i] < nums2[j] )
		{
			nums1[k] = nums2[j];
			j--;
			k--;
		}
	}

	while (j >= 0)
	{
		nums1[k] = nums2[j];
		k--;
		j--;
	}
	
}

void main(void)
{
    int num1[MAX_ARRAY_SIZE] = {1, 2, 2, 4, 7, 9};
    
	int num2[NUM2_SIZE] = { 3, 5, 8 };
	

	
	
	//int num1[MAX_ARRAY_SIZE] = {1, 2, 3};
	//int num2[NUM2_SIZE] = { 3,3,3,4,4,4};  /*test_01:NUM1_SIZE < NUM2_SIZE*/ 

    merge(num1, NUM1_SIZE, num2, NUM2_SIZE);
     
	// merge(num1, NUM1_SIZE, num2, 0);/*test_02: NUM2_SIZE == 0*/ 

	//merge(0, NUM1_SIZE, num2, 0);/*test_03: NUM1_SIZE == 0*/ 

    printf("Merge Result:\n ");
    for (int i=0; i<MAX_ARRAY_SIZE; i++)
    {
        printf("%d ", num1[i]);
    }
    printf("\n\n ");
	system("pause");
}
