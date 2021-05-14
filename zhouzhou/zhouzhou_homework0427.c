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
    int len_a=strlen(a),len_b=strlen(b);
    int step=0;//进位
	int i=len_a-1,j=len_b-1,k=0;
	char *result=(char *)malloc(20);
	int sum_a,sum_b,sum;
	for(;i>=0 || j>=0 || step;--i,--j)//两个字符串都从最右边对齐往左边相加 
	{
		sum_a=i < 0 ? 0 : a[i]-'0';
		sum_b=j < 0 ? 0 : b[j]-'0';
		sum=(sum_a+sum_b+step)%2;//求余保留当前位的结果
		step=(sum_a+sum_b+step)/2;//除2获得进位的值
		result[k++]=sum+'0';//当前位的值转化为字符 
	}  
	result[k]='\0';//添加结束符，此时得到的字符串顺序为反的 
	strrev(result);//字符串反转，也可使用for循环调换
	return result; 
}

int main(int argc,char ** argv)
{
    char * a = "1011";
    char * b = "0111"; 
    char *ret = addBinary(a, b);
    if (ret)
    {
        printf("0b%s + 0b%s = 0b%s", a, b, ret);
        free(ret);
    }
    return 0;
}