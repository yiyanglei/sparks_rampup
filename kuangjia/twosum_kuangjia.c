#include "stdio.h"
#include "stdlib.h"

struct node{
    int value;
    int index;
    struct node* p_next;
};

struct hash{
    struct node* p_add;
};


void hashFree(struct hash* hash_head, int hash_size)
{
    for(int i=0; i<hash_size; i++)
    {
        if(hash_head[i].p_add)
        {
            struct node* p_node_temp = hash_head[i].p_add;
            while(p_node_temp)
            {
                struct node* p_next_node = p_node_temp->p_next;
                free(p_node_temp);
                p_node_temp = p_next_node;
            }
        }
    }
    free(hash_head);
}

//int* twoSum(int* nums, int numsSize, int target, int* returnSize)
//{
//    for (int i = 0; i < numsSize; ++i) {
//        for (int j = i + 1; j < numsSize; ++j) {
//            if (nums[i] + nums[j] == target) {
//                int* ret = malloc(sizeof(int) * 2);
//                ret[0] = i, ret[1] = j;
//                *returnSize = 2;
//                return ret;
//            }
//        }
//    }
//    *returnSize = 0;
//    return NULL;
//}

int* twoSum(int* nums, int numsSize, int target, int* returnSize )
{

    //建立并初始化哈希表
    struct hash* const hash_table = (struct hash*) malloc(sizeof(struct hash)*numsSize);
    for(int i=0; i< numsSize; i++)
    {
        hash_table[i].p_add = NULL;
    }

    //初始化节点并将之添加到相应哈希表位置
    for(int i=0; i<numsSize; i++)
    {
        //申请节点空间
        struct node* node_temp = (struct node*) malloc(sizeof(struct node));
        //初始化节点
        node_temp->index = i;
        node_temp->value = nums[i];

        //计算节点添加到哈希表什么位置
        int mod = abs(nums[i]) % numsSize;
        //链上节点的添加采用前插法
        node_temp->p_next = hash_table[mod].p_add;
        hash_table[mod].p_add = node_temp;


        //计算所期望值在哈希表的位置
        int expect = abs(target - nums[i]);

        //验证是否符合
        struct node* temp = hash_table[expect%numsSize].p_add;
        while (temp!=NULL)
        {
            if ( (temp->index != i) && (temp->value+nums[i] == target))
            {
                //符合
                int *result = (int *)malloc(sizeof(int) * 2);
                result[0] = temp->index;
                result[1] = i;
                *returnSize = 2;
                hashFree(hash_table, numsSize);
                return result;
            }
            else
            {
                temp = temp->p_next;
            }
        }
    }
    *returnSize = 0;
    return 0;

}

int main(void)
{
    int num[]={6,3,4,2,5};
    int retsize;
    int* ret = twoSum(num, 5, 8, &retsize);
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

