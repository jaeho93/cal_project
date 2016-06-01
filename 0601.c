#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define N 61

int main(void) {

/*
	char in1[N] = {}; 		// 선언
	char in2[N] = {};
	char in3[N] = {};
	char in1_j[51] = {};
	char in3_j[51] = {};
	char in1_s[10] = {};
	char in3_s[10] = {};
	char mul_j[51] = {};
	char mul[10] = {};
	char mul[N] = {};
*/
	char a[N] = {};
	char b[N] = {}; 
	char mu[N] = {};
	int m = 0,first = 0, last = 0, temp = 0;


	scanf("%s", a);
	scanf("%s", b);

	printf("처음수 \n");
	printf("%s\n", a);
	printf("%s\n", b);


	last = strlen(a) - 1;
	while(1) 					{
		if(first > last) break;
		temp = a[last];
		a[last] = a[first];
		a[first] = temp;
		first++, last--;		}
	first = 0, last = 0;

	last = strlen(b) - 1;
	while(1) 					{
		if(first > last) break;
		temp = b[last];
		b[last] = b[first];
		b[first] = temp;
		first++, last--;		}
	first = 0, last = 0;

	printf("뒤집은 수 \n");
	printf("%s\n", a);
	printf("%s\n", b);

	for (int i = 0; i <= strlen(a)-1; i++) // a배열 숫자로 만들기(아스키 코드 '0' 빼줌)
	a[i] -= '0';			 
	for (int i = 0; i <= strlen(b)-1; i++)  // b배열도 마찬가지
	b[i] -= '0';			 

	for (int i = 0; i <= strlen(a)-1; i++)
	printf("%d\n", a[i]);
	for (int i = 0; i <= strlen(b)-1; i++)
	printf("%d다음에 곱\n", b[i]);

	if(strlen(b) >= strlen(a)){
		for(int i = 0; i < strlen(a); i++){  // 더 짧은수 돌리는 for문
			for(int n = 0; n < strlen(b); n++,m++)		
			{
				mu[m] += (a[i] * b[n]);	
				printf("a[i]의 값:%d\n", a[i]);
				printf("b[n]의 값:%d\n", b[n]);
				printf("mu[m]의 값:%d\n", mu[m]);

			}
			
			m -= (strlen(b)-1);
		}
	}
	
	for (int i = 0; i <= strlen(a)+strlen(b); i++)
	printf("전까지 곱%d\n", mu[i]);
	
	int carry =0;
	for(int i = 0; i <= m+2 ; i++){
		if(mu[i] >= 10){
			carry = mu[i] / 10;
			mu[i+1] += (mu[i]) / 10;

			mu[i] = (mu[i]) % 10;
		}
		else 
		{
			mu[i] = (mu[i]) % 10;
			carry=0;
		}

	}				

	for (int i = 0; i <= strlen(a)+strlen(b); i++)
	mu[i] += '0';

	last = strlen(a)+strlen(b);
	while(1) 					{
		if(first > last) break;
		temp = mu[last];
		mu[last] = mu[first];
		mu[first] = temp;
		first++, last--;		}
	first = 0, last = 0;

	printf("답\n");
	printf("%s", mu);
	

	return 0;
}
