#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//从前向后
void merge(int* nums1, int m, int* nums2, int n){

	int* newA = (int*)malloc(sizeof(int)*(m + n));
	int idx = 0;
	int n1 = 0;
	int n2 = 0;
	//合并
	while (n1 < m && n2 < n){
		if (nums1[n1] <= nums2[n2]){
			newA[idx++] = nums1[n1++];
		}
		else{
			newA[idx++] = nums2[n2++];
		}
	}
	//可能还有没访问完的元素
	if (n1 < m){
		memcpy(newA + idx,nums1 + n1,sizeof (int)*(m-n1));
	}
	if (n2 < n){
		memcpy(newA + idx, nums2 + n2, sizeof (int)*(n - n2));
	}
	memcpy(nums1,newA,sizeof(int)*(m+n));
	free(newA);
}
int main(){
	int nums1[] = { 1, 2, 3 };
	//int size1 = 3;
	int nums2[] = { 2, 5, 6 };
	//int size2 = 3;
	merge(nums1,  3, nums2, 3);

	for (int i = 0; i < 6;i++){
		printf("%d",nums1[i]);
	}
	system("pause");
	return 0;
}
