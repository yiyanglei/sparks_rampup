



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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addBinary(char * a, char * b)
{
    //假设参数a和b均不为空
	
		int a_size = strlen(a);
		int b_size = strlen(b);
		int ret_size = max(a_size, b_size) + 1;
		char* ret = (char*) malloc(sizeof(char)* ret_size);
		for (int i = 0; i < ret_size; i++)
		{
			ret[i] = '0';
		}//创建ret并初始化

		char IsCarryBit = '0';
		int i = a_size -1;
		int j = b_size -1;
		int k = ret_size -1;
		while (i >= 0 && j >=0 && k >=1)
		{
			char a_bit = a[i];
			char b_bit = b[j];
			ret[k] = a_bit ^ b_bit ^ IsCarryBit;
			IsCarryBit = (a_bit & b_bit) | (a_bit & IsCarryBit) | (b_bit & IsCarryBit);
			i--;
			j--;
			k--;
		}

		if (IsCarryBit == '1') ret[0] = '1';

		return ret;

}

void main(void)
{
    char * a = "11";
    char * b = "1"; 
    
    char *ret = addBinary(a, b);
    if (ret)
    {
        printf("0b%s + 0b%s = 0b%s", a, b, ret);
        free(ret);
    }
	system("pause");
    return;
}