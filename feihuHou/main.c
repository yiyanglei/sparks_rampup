#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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



int main() {

	const char *a = "1";
	const char *b = "1";
	char *c=addBinary((char *)a,(char *)b);
	printf("%s\n",c);
	free(c);
	c=NULL;
	return 0;
}
