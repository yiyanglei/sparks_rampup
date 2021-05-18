
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
#include "string.h"



char * fun(char *a)
{
    char *c;
    c = (char *)malloc(10 * sizeof(char));
    for (int i = 0; i < strlen(a); i++)
    {
        c[i] = a[strlen(a)-i-1];
    }
    return c; 
}
char * addBinary(char * a, char * b)
{   

    int z = 0;
    char m;
    int i, sum;
    int j = (strlen(a) > strlen(b)) ? strlen(a) + 1 : strlen(b) + 1;
    char c[j];
    int num_1[20] = {0};
    int num_2[20] = {0};
    for (i = 0; i < j; i++)
    {
        if (i == j-1 && z == 0)
        {
            c[i] = 0;
        }
        if (i < strlen(a))
        {
            num_1[i] = a[strlen(a)-i-1] - '0';
        }
        if (i < strlen(b))
        {
            num_2[i] = b[strlen(b)-i-1] - '0';
        }      
        sum = num_1[i] + num_2[i] + z;
        switch (sum)
        {
            case 3:
                z = 1;
                sum = 1;
                break;
            case 2:
                z   = 1;
                sum = 0;
                break;
            default:
                z   = 0;
                break;
        }
        m = sum + 48;
        c[i] = m;
    }
    return fun(c); 
}

int main(void)
{
    char * a = "1011";
    char * b = "0111"; 
    
    char *ret = addBinary(a, b);
    if (ret)
    {
        printf("0b%s + 0b%s = 0b%s\n", a, b, ret);
        free(ret);
    }
    return 0;
}
