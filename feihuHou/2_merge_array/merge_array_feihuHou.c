
/*两个有序整数数组 nums1 和 nums2，请将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
假设：
	初始化 nums1 和 nums2 的元素数量分别为 m 和 n
	nums1 的空间大小等于 m + n，有足够的空间保存来自 nums2 的元素。

示例 1： 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
		输出：[1,2,2,3,5,6]
示例 2： 输入：nums1 = [1], m = 1, nums2 = [], n = 0
		输出：[1]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM1_SIZE   (6u)
#define NUM2_SIZE   (3u)
#define MAX_ARRAY_SIZE (NUM1_SIZE+NUM2_SIZE)

void merge(int* nums1, int m, int* nums2, int n){
	//fill your code here
	int *p_nums1=(int *)malloc(sizeof(int)*m);
	memcpy(p_nums1, nums1, sizeof(int) * m);

	int i = 0, j = 0;
	int cnt = 0;
	while (i < m || j < n) {
		if (i < m && j < n) {
			if (p_nums1[i] < nums2[j]) {
				nums1[cnt] = p_nums1[i];
				i++;
				cnt++;
			}else {
				nums1[cnt] = nums2[j];
				j++;
				cnt++;
			}
		}else {
			if (i == m ) {
				while (j < n) {
					nums1[cnt] = nums2[j];
					j++;
					cnt++;
				}
				break;
			}else if (j == n ) {
				while (i < m) {
					nums1[cnt] = p_nums1[i];
					i++;
					cnt++;
				}
				break;
			}
		}
	}
	free(p_nums1);
	p_nums1 = NULL;
}

int main(void)
{
	int num1[MAX_ARRAY_SIZE] = { 1, 2, 2, 4, 7, 9 };
	int num2[NUM2_SIZE] = { 3, 5, 8 };

	merge(num1, NUM1_SIZE, num2, NUM2_SIZE);

	printf("Merge Result:\n ");
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		printf("%d ", num1[i]);
	}
	printf("\n\n ");
	return 0;
}
