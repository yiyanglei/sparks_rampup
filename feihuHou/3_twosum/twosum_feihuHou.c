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
#include "./include/typedef.h"
#include "./include/hash.h"

//参数说明：nums-数组，numsSize-数组的size，target-目标值，returnSize-返回的数组size
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Hash_t* p_hash_s = hsah_new(10);
    int *ret=(int *)malloc(sizeof(int)*2);
    Pair_t pair;
    for (int i = 0; i < numsSize; i++) 
    {
        List_t* p_list = get_key_plist(p_hash_s,target - nums[i]);
        if (NULL!=p_list) 
        {
            ret[0]=p_list->pair.value;
            ret[1]=i;
            *returnSize = 2;
            hash_delete(p_hash_s);
            return ret;
        }
        pair.key=nums[i];
        pair.value=i;
        hsah_insert(p_hash_s, &pair);
    }
    hash_delete(p_hash_s);
    free(ret);
    ret=NULL;
    *returnSize = 0;
    return NULL;
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





