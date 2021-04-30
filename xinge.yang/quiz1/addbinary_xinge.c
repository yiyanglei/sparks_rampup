
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

#include "addbinary_xinge.h"

__uint32_t cvtDecimal(char * binstring)
{
    __uint32_t index = (__uint32_t)strlen(binstring);
    __uint32_t temp = 0u;
    while(index > 0u)
    {
        index--;
        __uint32_t diff = *(binstring + index) - '0';
        temp += (diff << ((__uint32_t)strlen(binstring) - index - 1));
    }
    return temp;
}

char * cvtBinary(__uint32_t sum)
{
    __uint32_t num_array[50] = {0};
    __uint32_t cnt           = 0u;
    __uint32_t temp          = 0u;
    static char ret[50]      = {0};
    while (sum != 0u)
    {
        cnt ++;
        temp = sum % 2u;
        num_array[cnt - 1] = temp;
        sum /= 2;
    }
    for(__uint32_t idx = 0u; idx < cnt; idx ++)
    {
        ret[idx] = (char)(num_array[cnt - idx - 1] + '0');
    }
    return (char *)(ret);
}

char * addBinary(char * a, char * b)
{
    __uint32_t num_a = 0u;
    __uint32_t num_b = 0u;
    char * ret_val   = NULL;
    num_a = cvtDecimal(a);
    num_b = cvtDecimal(b);
    ret_val = cvtBinary((__uint32_t)(num_a + num_b));
    //假设参数a和b均不为空
    return ret_val;
}

void main(void)
{
    char * a = "1011";
    char * b = "0111"; 
    
    char *ret = addBinary(a, b);
    if (ret)
    {
        printf("0b%s + 0b%s = 0b%s\n", a, b, ret);
        // free(ret);
    }

    return;
}