
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
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

char * addBinary(char * a, char * b)
{
	//假设参数a和b均不为空
	int numa =0, numb = 0;
	int numa_ten = 0, numb_ten = 0, index = 1;
	while (*a >= '0' && *a <= '1')//a转换成相应数字
	{
		numa *= 10;
		numa += *a - '0';
		a++;
	}
	while (*b >= '0' && *b <= '1')//b转换成相应数字
	{
		numb *= 10;
		numb += *b - '0';
		b++;
	}
	while (numa)//a转换成10进制
	{
		numa_ten+=numa%10*index;
		index *=2;
		numa /= 10;
	}
	index = 1;

	while (numb)//b转换成10进制
	{
		numb_ten += numb % 10 * index;
		index *= 2;
		numb /= 10;
	}
	char * c = (char *)malloc(sizeof(char)*100);
	int sum_ten = numa_ten + numb_ten;//10进制的和
	_itoa(sum_ten, c, 2);  //10进制数转换成2进制字符串
	return c;
}

void main(void)
{
	char * a = "1100101";
	char * b = "001101111";

	char *ret = addBinary(a, b);
	if (ret)
	{
		printf("0b%s + 0b%s = 0b%s", a, b, ret);
		free(ret);
	}
	system("pause");
	return;
}
