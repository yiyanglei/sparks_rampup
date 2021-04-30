
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

int min(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }    
}

char * fun(char *a)
{
    char *c;
    c = (char *)malloc(10 * sizeof(char));
    for (int i = 0; i < strlen(a); i++)
    {
        c[i] = a[strlen(a)-i-1];
    }
    return c;
    free(c);
    
}

char * addBinary(char * a, char * b)
{   
    char *c;
    c = (char *)malloc(10 * sizeof(char));
    int z = 0;
    char m;
    int i, sum;
    int j = min(strlen(a), strlen(b));
    for (i = 0; i < j; i++)
    {
        int x, y;
        x = a[strlen(a)-i-1] - '0';
        y = b[strlen(b)-i-1] - '0';
        sum = x + y + z;
        switch (sum)
        {
            case 3:
                z   = 1;
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
    if (strlen(a) > strlen(b))
    {
        sum = a[i] + z -48;
        switch (sum)
        {
        case 2:
            z   = 1;
            sum = 0;
            m = sum + 48;
            c[i] = m;
            m = z + 48;
            c[i+1] = m;
            break;
        
        case 1:
            m = sum + 48;
            c[i] = m;
        default:
            break;
        }
        
    }
    if (strlen(a) < strlen(b))
    {
        sum = b[i] + z -48;
        switch (sum)
        {
        case 2:
            z   = 1;
            sum = 0;
            m = sum + 48;
            c[i] = m;
            m = z + 48;
            c[i+1] = m;
            break;
        
        case 1:
            m = sum + 48;
            c[i] = m;
        default:
            break;
        }
        
    }
    if (strlen(a) == strlen(b))
    {
        if (z == 1)
        {   
            m = z + 48;
            c[i] = m; 
        }
    } 
    return fun(c);
    free(c);
    
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
    else
    {
        printf("There\'s a error!\n");

    }
}