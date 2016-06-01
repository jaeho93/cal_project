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
	int a_1[N] = {};
	int b_1[N] = {};
	int mu[N] = {};
	char change_mu[N] = {};
	int m = 0,first = 0, last = 0, temp = 0, temp1_d = 0, temp3_d =0 ;
	int point = 0;	
	scanf("%s", a);
	scanf("%s", b);
	
	for (int i = 0; i < 60; i++) 		
	{
		if (a[i] == '.'){
			temp1_d = i+1; 
			break;
		}
	}
	printf("temp1_d의 값:%d\n", temp1_d);	

	for (int i = 0; i <= 60; i++)
   	{						
		if (b[i] == '.'){
			temp3_d = i+1;
		   	break;
		}
	}
	printf("temp_3d의값:%d\n", temp3_d);

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

	for (int i = 0; i <= strlen(a)-1; i++)// a배열 숫자로 만들기(아스키 코드 '0' 빼줌)
		a_1[i] = (a[i]-'0'); 

	for (int i = 0; i <= strlen(b)-1; i++)  // b배열도 마찬가지
		b_1[i] = (b[i]-'0');			 

	if(strlen(b) >= strlen(a)){
		for(int i = 0; i < strlen(a); i++){  // 더 짧은수 돌리는 for문
			for(int n = 0; n < strlen(b); n++)		
			{
				mu[m] += (a_1[i] * b_1[n]);	
				m ++;
			}
			m -= (strlen(b)-1);
		}
	}
	else{
		for(int i = 0; i < strlen(b); i++){
			for(int n = 0; n <strlen(a); n++)
			{
				mu[m] += (b_1[i] * a_1[n]);	
				m ++;
			}	
			m -= (strlen(a)-1);
		}
	}

	for(int i = 0; i <= strlen(a)+strlen(b) ; i++){ //mu배열 정리(올림수 고려)
		if(mu[i] >= 10){
			mu[i+1] += (mu[i]) / 10;

			mu[i] = (mu[i]) % 10;
		}
		else 
			mu[i] = (mu[i]) % 10;
	}				

	for (int i = 0; i <= strlen(a)+strlen(b); i++) //mu배열에 아스키코드 값 모두 더하기
		mu[i] += '0';

	for(int i=0; i<strlen(a) + strlen(b) ; i++) // int형 배열의 원소들을 char형 배열로 옮기기
		change_mu[i] = mu[i];

	last = strlen(a)+strlen(b)-1;
	while(1) 					{
		if(first > last) break;
		temp = change_mu[last];
		change_mu[last] = change_mu[first];
		change_mu[first] = temp;
		first++, last--;		}
	first = 0, last = 0;
	for(int i=0; i<strlen(a) + strlen(b) ; i++)
		printf("%c\n", change_mu[i]);

	printf("답\n");
	for(int i=0; i< strlen(change_mu); i++)
	{
		point = strlen(a) - temp1_d + strlen(b) - temp3_d;
		if(point == '.')
		printf("%c", change_mu[i]);
	}

	return 0;
}
