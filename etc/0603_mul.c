#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 61

int main(void){

	char in1[N] = {}; 		// 선언
	char in2[N] = {};
	char in3[N] = {};

	char in1_j[51] = {};
	char in3_j[51] = {};
	char in1_s[10] = {};
	char in3_s[10] = {};

	int mul_1[N] = {};
	int mul_3[N] = {}; 
	int mul[N] = {};
	char ch_mul[N] = {};

	char mul_j[51] = {}; 
	char mul_s[10] = {}; 
	char mul[N] = {};
	
	int str_in1, str_in2, str_in3, str_plus_s;
	int temp = 0, temp1_d = 0, temp3_d = 0, temp_j = 0, temp_s = 0;
	int first = 0, last = 0;
	int k = 0, p = 0;

start:

	printf("(input) ");		// 값 입력
	scanf("%s", in1);
	str_in1 = strlen(in1);


	/*if (str_in1 == 1);		// ( == 1) 일 경우 변수 선언,  아닐 때 사칙연산,  나머지 상황 정의가 먼저 필요하다
		else {*/
							// 사칙연산 시작
	
	scanf("%s", in2);
	str_in2 = strlen(in2);
	if(str_in2 == 1) {		// ( == 1) 일경우, 사칙연산이다.
	
	
	scanf("%s", in3);

	switch (in2[0]) {
	
	case '*' : {			// 더하기의 경우
	
	for (int i = 0; i <= 49; i++) {		// 정수부, 소수부의 분리1
	if (in1[i] == '.')
	{temp1_d = i+1; break;}
	else in1_j[i] = in1[i];		  }
	if (in1[50] == '.')
	temp1_d = 51;
	
	if( temp1_d != 0){
	for(int i = 0; i <= 8; temp1_d++, i++)
	in1_s[i] = in1[temp1_d];
	}


	for (int i = 0; i <= 49; i++) {		// 정수부, 소수부의 분리2
	if (in3[i] == '.')
	{temp3_d = i+1; break;}
	else in3_j[i] = in3[i];		  }
	if (in3[50] == '.')
	temp3_d = 51;

	if( temp3_d != 0){
	for(int i = 0; i <= 8; temp3_d++, i++)
	in3_s[i] = in3[temp3_d];
	}

	last = strlen(in1_j) - 1;		// 첫번째 정수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = in1_j[last];
	in1_j[last] = in1_j[first];
	in1_j[first] = temp;
	first++, last--;
			 }
	first = 0; last = 0;

	last = strlen(in3_j) - 1;		// 두번째 정수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = in3_j[last];
	in3_j[last] = in3_j[first];
	in3_j[first] = temp;
	first++, last--;
			 }
	first = 0; last = 0;
/*
	for (int i = 0; i <= 49; i++) {		// 문자를 곱셈을위해 수로 바꾸기
	if ( in1_j[i] == 0) ;
	else in1_j[i] -= '0';         }

	if( temp1_d != 0){
	for (int i = 0; i <= 8; i++)  {
	if ( in1_s[i] == 0) ;
	else in1_s[i] -= '0';         }
	}

	for (int i = 0; i <= 49; i++) {
	if ( in3_j[i] == 0) ;
	else in3_j[i] -= '0';         }

	if( temp3_d != 0){
	for (int i = 0; i <= 8; i++)  {
	if ( in3_s[i] == 0) ;
	else in3_s[i] -= '0';         }
	}
*/
	for(int i = 0 ; i < strlen(in1_s) ; i++) // in1_s 소수부 받고 in1_j 정수부 받기
	{
 		mul_1[i] =  in1_s[i]-'0';	
	}
	for(int i = strlen(in1_s) ; i < strlen(in1_s) + strlen(in1_j) ; i++)
	{
		mul_1[i] = in1_j[i]-'0';
	}
	for(int i = 0 ; i < strlen(in3_s) ; i++) // in3_s 소수부 받고 in1_j 정수부 받기
	{
 		mul_3[i] =  in3_s[i]-'0';	
	}
	for(int i = strlen(in3_s) ; i < strlen(in3_s) + strlen(in3_j) ; i++)
	{
		mul_3[i] = in3_j[i]-'0';
	}

	if(strlen(in3) >= strlen(in1)){ // 두번째 입력한 수가 길거나 같을 경우
			for(int i = 0 ; i < strlen(in1)-1 ; i++){
				for( int n = 0; n < strlen(in3)-1; n++)
				{
					mul[m] += (mul_1[i] * mul_3[i]);
					m++;
				}
				m -= strlen(in3)-1;
			}
	}
	else{
		for(int i = 0; i < strlen(in3) - 1; i++){
			for(int n = 0; n < strlen(in1) - 1; n++)
			{
				mul[m] += (mul_3[i] * mul_1[n]);
				m++;
			}
		}
	}
			
	for(int i = 0; i strlen(in1_j) + strlne(in3_j) + strlen(in1_s) + strlen(in3_s) ; i++)
		ch_mul[i] = mul[i] + '0';

	f = strlen(in_1) - temp1_d + strlen(in_3) - temp3_d;
	for(int i = 0 ; i < f ; i++) // in1_s 소수부 받고 in1_j 정수부 받기
	{
 		mul_s[i] =  ch_mul[i] ;	
	}
	for(int i = 0 ; i <  strlen(ch_mul)-f ; i++)
	{
		mul_j[i] = ch_mul[k+1];
	}

	for( int i = 0; i < 
	for (int i = 49; i >= 0; i--)			{		// 수를 문자로 바꾸기
	if (plus_j[i] != 0)
	{temp_j = i; break;}					}
	
	for (int i = 0; i <= temp_j; i++)
	plus_j[i] += '0';
	
	for (int i = 8; i >= 0; i--)			{		// 수를 문자로 바꾸기
	if (plus_s[i] != 0)
	{temp_s = i; break;}					}

	for (int i = 0; i <= temp_s; i++)
	plus_s[i] += '0';
	
	last = strlen(plus_j) - 1;		// 첫번째 정수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = plus_j[last];
	plus_j[last] = plus_j[first];
	plus_j[first] = temp;
	first++; last--;
			 }

	printf("= %s", plus_j);
	if ( p != 0)
	printf(".%s", plus_s);
			   }
	default: ;}}

return 0;}
