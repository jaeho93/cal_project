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
	char last_mul[N] = {};

	int str_in1, str_in2, str_in3, str_plus_s;
	int temp = 0, temp1_d = 0, temp3_d = 0, temp_j = 0, temp_s = 0;
	int first = 0, last = 0;
	int f = 0 ,m = 0,k = 0, p = 0;
	int x , y;

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

	
	x = strlen(in1_j) + strlen(in1_s);
	y = strlen(in3_j) + strlen(in3_s);


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

	last = strlen(in1_s) - 1;		// 첫번째 정수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = in1_s[last];
	in1_s[last] = in1_s[first];
	in1_s[first] = temp;
	first++, last--;
			 }
	first = 0; last = 0;

	last = strlen(in3_s) - 1;		// 두번째 정수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = in3_s[last];
	in3_s[last] = in3_s[first];
	in3_s[first] = temp;
	first++, last--;
			 }
	first = 0; last = 0;

	for(int i = 0 ; i < strlen(in1_s) ; i++) // in1_s 소수부 받고 in1_j 정수부 받기
		mul_1[i] = in1_s[i]-'0';	
	for(int i = strlen(in1_s), t = 0 ; i < strlen(in1_s) + strlen(in1_j) ;){ // 변수 t 설정(정수부 넣기 위해서)
		mul_1[i] = in1_j[t]-'0';
		t++,i++;}

	for(int i = 0 ; i < strlen(in3_s) ; i++) // in3_s 소수부 받고 in1_j 정수부 받기
 		mul_3[i] = in3_s[i]-'0';	
	for(int i = strlen(in3_s), t = 0 ; i < strlen(in3_s) + strlen(in3_j) ; ){
		mul_3[i] = in3_j[t]-'0';
		t++,i++;}

	
	if(strlen(in3) >= strlen(in1)){
		for(int i = 0; i < x; i++){  // 더 짧은수 돌리는 for문
			for(int n = 0; n < y; n++)		
			{mul[m] += (mul_1[i] * mul_3[n]);	
			m++;}

			m -= y-1;}}
	else{
		for(int i = 0; i < y ; i++){
			for(int n = 0; n < x ; n++)
			{mul[m] += (mul_3[i] * mul_1[n]);
			m++;}

			m -= x-1;}}

	for(int i = 0 ; i < x ; i++)
		printf("mul_1의값 %d ", mul_1[i]);
	printf("\n");
	for(int i = 0 ; i < y ; i++)
		printf("mul_3의값 %d ", mul_3[i]);
	printf("\n");	
	for(int i = 0 ; i < x+y-1 ; i++)
		printf("mul[%d]의값 %d ", i,mul[i]);
	printf("\n");	

	
	for(int i = 0 ; i < x+y; i++){
			if(mul[i] >= 10){
				mul[i+1] += (mul[i]) / 10;
				mul[i] = (mul[i]) % 10;
			}
			else
				mul[i] = (mul[i]) % 10;
	}
	
	printf("\n");
	for(int i=0; i< y; i++)
		printf("%d", mul[i]);

	for (int i = 0; i <= 49; i++) {		// 소수점(temp1_d) 재조정
	if (in1[i] == '.')
	{temp1_d = i+1; break;}}
	for (int i = 0; i <= 49; i++) {		
	if (in3[i] == '.')
	{temp3_d = i+1; break;}}

	printf("\n");
	printf("temp1_d : %d , temp3_d : %d\n", temp1_d,temp3_d);
	printf("값:%d\n", (strlen(in1) + strlen(in3) - temp1_d -temp3_d));

	for(int i = 0, c = 0; i < y + 1 ; i++,c++){
		if(i == strlen(in1) + strlen(in3 ) - temp1_d - temp3_d){
		last_mul[i] = '.'; 
		i++;}	

		else{
		last_mul[i] = mul[c] + '0';
		}}


	for(int i=0; i< strlen(in1) + strlen(in3) + 1 ; i++)
		printf("%c", last_mul[i]);

	last = strlen(last_mul) - 1;		// 첫번째 정수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = last_mul[last];
	last_mul[last] = last_mul[first];
	last_mul[first] = temp;
	first++; last--;
			 }

	printf("\n");
	printf("= %s", last_mul);
			   }
	default: ;}}

return 0;}
