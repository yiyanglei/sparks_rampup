
/*
ÿ��һ��
�����������ַ����� �ַ����ǿ���ֻ�������� 1 �� 0�����������ǵĺͣ��ö����Ʊ�ʾ����
ʾ�� 1:
����: a = "11", b = "1"
���: "100"
ʾ�� 2:
����: a = "1010", b = "1011"
���: "10101"
*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

char * addBinary(char * a, char * b)
{
	//�������a��b����Ϊ��
	int numa =0, numb = 0;
	int numa_ten = 0, numb_ten = 0, index = 1;
	while (*a >= '0' && *a <= '1')//aת������Ӧ����
	{
		numa *= 10;
		numa += *a - '0';
		a++;
	}
	while (*b >= '0' && *b <= '1')//bת������Ӧ����
	{
		numb *= 10;
		numb += *b - '0';
		b++;
	}
	while (numa)//aת����10����
	{
		numa_ten+=numa%10*index;
		index *=2;
		numa /= 10;
	}
	index = 1;
	while (numb)//bת����10����
	{
		numb_ten += numb % 10 * index;
		index *= 2;
		numb /= 10;
	}
	char * c = (char *)malloc(sizeof(char)*100);
	int sum_ten = numa_ten + numb_ten;//10���Ƶĺ�
	_itoa(sum_ten, c, 2);  //10������ת����2�����ַ���
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