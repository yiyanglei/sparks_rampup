/*
 * @Author: jeff
 * @brief: vector implement
 * @Date: 2021-04-14 09:57:12 
 * @Last Modified time: 2021-04-14 10:04:05
 */

#include<stdio.h>
#include<stdlib.h>
 
#define VECTOR_SIZE 16U

typedef struct
{
    int curSize;
    int maxSize;
    int * data;
    
}vector_t;

static void InitVector(vector_t *vector)
{
    vector->curSize =0;
    vector->maxSize =VECTOR_SIZE;
    vector->data=malloc(sizeof(int)*vector->maxSize);
}

static void vector_increase(vector_t *vector)
{
    if(vector->curSize==vector->maxSize)
    {
        vector->maxSize*=2;
        vector-> data= malloc(sizeof(int)*vector->maxSize);
        if(vector->data==NULL)
        {
            printf("Out of memory\n");
        }

    }
    //else printf("no increase\n");
}


void vector_insert(vector_t *vector,int value)
{
    vector_increase(vector);
    vector->data[vector->curSize++] =value;
  //  printf("%d\n",vector->data[vector->curSize]);
}


int get_vector(vector_t *vector, int index)
{
    int ret_val;
    if(index>=vector->curSize||index<0)
    {
        ret_val=0;
        return ret_val;
    }
    return vector->data[index];
}

void set_vector(vector_t *vector, int index, int value)
{
    int ret_val;
    while(index>= vector->curSize)
    {
        vector_increase(vector);
    }
    vector->data[index] =value;
        
}


void vector_delete(vector_t *vector,int index)
{

    for(int i=index+1;i<vector->curSize;i++)
    {
        vector->data[index++]=vector->data[i];

    }
    vector->curSize--;
    
   // free(vector->data[vector->curSize-1]);
    
}

void free_vector(vector_t *vector)
{
    free(vector->data);
}

int main(void)
{
    vector_t vector;
    InitVector(&vector);
    for(int i=0;i<VECTOR_SIZE;i++)
    {
       // printf("%d\n",i);
        vector_insert(&vector,i);
    }
    for(int i=0;i<(vector.curSize);i++)
    {
        printf("%d\n",vector.data[i]);
    }
    vector_delete(&vector,2);
     for(int i=0;i<(vector.curSize);i++)
    {
        printf("%d\n",vector.data[i]);
    }

    return 0;

}