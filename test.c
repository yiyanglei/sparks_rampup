
/*
每周一题
    两个二进制字符串（ 字符串非空且只包含数字 1 和 0），返回它们的和（用二进制表示）。
示例 1:
    输入: a = "11", b = "1"
    输出: "100"
示例 2:
    输入: a = "1010", b = "1011"
    输出: "10101"
*/
#include "stdio.h"
#include "stdlib.h"

char * addBinary(char * a, char * b)
{
    //假设参数a和b均不为空

    char size_a = 0, size_b = 0;
    char width = 0, cut = 0;
    char *plong = NULL;
    char *pshort = NULL;
    while(*a != '\0')
    {
        size_a++;
        a++;
    }
    while(*b != '\0')
    {
        size_b++;
        b++;
    }
    a -= size_a;
    b -= size_b;
    if(size_a >= size_b)
    {
        width = size_a;
        cut = size_a-size_b;
        plong = a;
        pshort = b;
    }
    else
    {
        width = size_b;
        cut = size_b-size_a;
        plong = b;
        pshort = a;
    }

    char* sum = (char*) malloc(sizeof(char)*(width+2));
    sum[0] = '\0';
    //  printf("%d, %d, %d \n", size_a, size_b,cut);
    char carrybit = '0';  //进位
    char index = width-1;

    while(index>=0)
    {
        //     printf("%d coming:",index);
        if(index-cut >= 0)
        {
            if (carrybit == '0')
            {
                if (plong[index] != pshort[index-cut])
                {
                    sum[index+1]= '1';
                    carrybit = '0';
                }
                else if (plong[index] == '0')
                {
                    sum[index+1]= '0';
                    carrybit = '0';
                }
                else if (plong[index] == '1')
                {
                    sum[index+1]= '0';
                    carrybit = '1';
                }
                //   printf("%c,%c,%c \n", plong[index],pshort[index-cut],sum[index+1]);
            }
            else
            {
                if (plong[index] != pshort[index-cut])
                {
                    sum[index+1]= '0';
                    carrybit = '1';
                }
                else if (plong[index] == '0')
                {
                    sum[index+1]= '1';
                    carrybit = '0';
                }
                else if (plong[index] == '1')
                {
                    sum[index+1]= '1';
                    carrybit = '1';
                }
                //      printf("%c \n", sum[index+1]);
            }
        }
        else
        {
            if (carrybit == '1')
            {
                if( plong[index] == '1')
                {
                    sum[index+1]= '0';
                    carrybit = '1';
                }
                else
                {
                    sum[index+1]= '1';
                    carrybit = '0';
                }
            }
            else
            {
                if(plong[index] == '1')
                {
                    sum[index+1]= '1';
                    carrybit = '0';
                }
                else
                {
                    sum[index+1]= '0';
                    carrybit = '0';
                }

            }
//           printf("%c \n", sum[index+1]);
        }
        index--;
    }
    if (carrybit == '1')
        sum[0]= '1';

    sum[width+1] = '\0';
    if(sum[0] == '0' || sum[0] == '1')
    {
//        for(int j=0;j<width+1;j++)
//        printf("%c",sum[j]);
        return &sum[0];
    }
    else
    {
//        for(int j=1;j<width+1;j++)
//        printf("%c",sum[j]);
        return &sum[1];
    }


}

void main(void)
{
    char * a = "001101";
    char * b = "01101";


    char *ret = addBinary(a, b);
    if (ret)
    {
        printf("0b%s + 0b%s = 0b%s", a, b, ret);
        free(ret);
    }

    return;
}
