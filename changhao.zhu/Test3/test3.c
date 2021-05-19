/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回它们的数组下标。
假设：
    每种输入有且只有一个答案
    数组中同一个元素在答案里不能重复出现
    按任意顺序返回答案

示例 1：
    输入：nums = [2,7,11,15], target = 9
    输出：[0,1]
    解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：
    输入：nums = [3,2,4], target = 6
    输出：[1,2]
示例 3：
    输入：nums = [3,3], target = 6
    输出：[0,1]
*/

#include "stdio.h"
#include "stdlib.h"

//参数说明：nums-数组，numsSize-数组的size，target-目标值，returnSize-返回的数组size
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *a=(int*)malloc(sizeof(int)*2);
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
               a[0]=i,a[1]=j;
               return a ;
            }
        }
   }
   *returnSize=2;
   return 0;
}

int main(void)
{
    int num[]={2,7,13,24};
    int retsize;
    int* ret = twoSum(num, 5, 9, &retsize);
    if(ret)
    {
        printf("Found: %d %d\n", ret[0], ret[1]);
        free(ret);
    }
    else
    {
        printf("not found");
    }

    return 0;
}