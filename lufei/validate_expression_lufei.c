/*
���룺һ���ַ���Ϊ��ѧ���������ʽ��������ܺ��ж���С���ţ���
1+2*3-4/2
10+((8+2)*3-(4+5))
9*(1+(23-9/(1+1+1)))-4
��������ʽ�������÷��Ƿ�淶����ԣ����򷵻�1�����򷵻�0
�� 1+)(2+3)��1+(2/3-4))

ע��:
1.ֻ������ŵĹ淶������Ҫ������ֺ��������
2.�������Ŀ�����cmake/makefile������

ʾ����
1+2*3-4/2    ����1
9*(1+(23-9/(1+1+1)))-4  ����1
1+(2/3-4))  ����0
1��2-3�� ����1(ֻ������ţ������������Ч��)
*/

#include "stdio.h"
#include "stdlib.h"

int validate_expression(const char * exp)
{
	int i = 0, numleft = 0, numright = 0;
	for (i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
			numleft++;
		if (exp[i] == ')')
		{
			numright++;
			if (numleft < numright)
				return 0;
		}
	}
	return 1;
}

int main(void)
{
	char exp[] = "1��2-3��"; //"9*(1+(23-9/(1+1+1)))-4";//"1 + 2 * 3 - 4 / 2";//"1+(2*4-3))";

	if (validate_expression(exp) != 0)
	{
		printf("expression %s is valid\n", exp);
	}
	else
	{
		printf("expression %s is invalid\n", exp);
	}

	return 0;
}