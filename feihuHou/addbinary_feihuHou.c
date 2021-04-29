#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


char* addBinary(char* a, char* b) {
	if (NULL == a || NULL == b) {
		return NULL;
	}
	int a_len = strlen(a);
	int b_len = strlen(b);
	int res_len = a_len > b_len ? a_len + 2 : b_len + 2;
	int res_len_temp = res_len - 1;
	char* res = (char *)malloc(res_len);
	if (NULL == res) {
		return NULL;
	}
	memset(res, 0, res_len);
	int carry = 0;
	a_len--;
	b_len--;
	res_len--;
	res[res_len] = '\0';
	res_len--;
	while (a_len >= 0 || b_len >= 0) {
		int sum = carry;
		if (a_len >= 0) {
			sum += a[a_len] - '0';
			a_len--;
		}
		if (b_len >= 0) {
			sum += b[b_len] - '0';
			b_len--;
		}
		res[res_len] =sum%2+ '0';
		carry = sum / 2;
		res_len--;
	}
	if (carry == 0) {
		char* res1 = (char*)malloc(res_len_temp);
		if (NULL == res1) {
			return NULL;
		}
		memset(res1, 0, res_len_temp);
		strcpy(res1 ,res+1);
		free(res);
		res = NULL;
		return res1 ;

	}
	res[0] = '1'; 
	return res;
}

void main(void)
{
    char * a = "1011";
    char * b = "0111"; 
    
    char *ret = addBinary(a, b);
    if (ret)
    {
        printf("0b%s + 0b%s = 0b%s", a, b, ret);
        free(ret);
    }

    return;
}
