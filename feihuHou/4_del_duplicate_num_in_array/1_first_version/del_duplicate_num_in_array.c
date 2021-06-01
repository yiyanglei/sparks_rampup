/*
一个有序数组 nums ，请 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。
注意:
    不要使用额外的数组空间，必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
    数组有序，从小到大

示例 1：
    输入：nums = [1,1,1,2,2,3]
    输出：5, nums = [1,1,2,2,3]
    解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 不需要考虑数组中超出新长度后面的元素。
示例 2：
    输入：nums = [0,0,1,1,1,1,2,3,3]
    输出：7, nums = [0,0,1,1,2,3,3]
    解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。 不需要考虑数组中超出新长度后面的元素。
*/

#include "stdio.h"
#include "stdlib.h"


int removeDuplicates(int* nums, int numsSize){
	//不要使用额外的数组空间
    int i = 2;
    int index = 0;
    while (i < numsSize) 
    {
        if (nums[i-2] == nums[i - 1] && nums[i - 1]== nums[i]) 
        {  
            for (index = i-1 ; index < numsSize; index++) 
            {
                 nums[index-1] = nums[index];
            }
            numsSize--;    
        }
        else 
        {
            i++;
        } 
    }
    return numsSize;
}

int main(void)
{
    int nums[]={2,2,2,7,13,13,13,13,13,24};
    int numsize = 20;
    int ret = 0;
    
    printf("Process Result is: ");
    ret = removeDuplicates(nums, numsize);
    for(int i=0; i<ret; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
