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
	char plus_j[51] = {};
	char plus_s[10] = {};
	char plus[N] = {};
	
	int str_in1, str_in2, str_in3, str_plus_s;
	int temp = 0, temp1_d = 0, temp3_d = 0, temp_j = 0, temp_s = 0;
	int first = 0, last = 0;
	int k = 0, p = 0, q = 0, daeso = 0;

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
	printf("값1 값2 값3\n");
	printf("%s\n", in1);
	printf("%s\n", in2);
	printf("%s\n", in3);

	switch (in2[0]) {
	
	case '-' : {			// 빼기의 경우
	
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

printf("요기%c", in1_s[0]);
printf("%c", in3_s[0]);
	
	if (temp3_d > temp1_d)				//앞 뒤 수 비교
	daeso = 1;
	else if (temp3_d < temp1_d)
	{daeso = 0; goto dae;}
	else{ 
	for (int i = 0; i <= 49; i++)
	{if (in1_j[i] == in3_j[i]);
	 else if (in1_j[i] > in3_j[i])
	 {daeso = 0; goto dae;}
	 else {daeso = 1; break;}}}
	
	
printf("요기%c", in1_s[0]);
printf("%c", in3_s[0]);
	if (daeso == 0) {
	for (int i = 0; i <= 8; i++) {
	if (in1_s[i] == in3_s[i]);
	 else if (in1_s[i] > in3_s[i])
	 {daeso = 0; break;}
	 else {daeso = 1; break;}}}
dae:

	printf("정수 정수 소수 소수\n");
	printf("%s\n", in1_j);
	printf("%s\n", in3_j);
	printf("%s\n", in1_s);
	printf("%s\n", in3_s);

	last = strlen(in1_j) - 1;		// 첫번째 정수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = in1_j[last];
	in1_j[last] = in1_j[first];
	in1_j[first] = temp;
	first++, last--;
			 }
	first = 0; last = 0;

	printf("정쉬디집\n");
	printf("%s\n", in1_j);
	/*last = strlen(in1_s) - 1;		// 첫번째 소수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = in1_s[jast];
	in1_s[last] = in1_s[first];
	in1_s[first] = temp;
	first++; last++;
			 }*/
	
	last = strlen(in3_j) - 1;		// 두번째 정수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = in3_j[last];
	in3_j[last] = in3_j[first];
	in3_j[first] = temp;
	first++, last--;
			 }
	first = 0; last = 0;
	printf("%s\n", in3_j);

	/*last = strlen(in3_s) - 1;		// 두번째 소수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = in3_s[jast];
	in3_s[last] = in3_s[first];
	in3_s[first] = temp;
	first++; last++;
			 }*/


	for (int i = 0; i <= 49; i++) {		// 문자를 뺄셈을위해 수로 바꾸기
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

	if (daeso == 0) //앞에 수가 큰 경우
	{
	for (int i = 8; i >= 0; i--)			{	// 소수 빼기
	plus_s[i] = in1_s[i] - in3_s[i] - k;
	if ( i != 0)	{
	if (plus_s[i] < 0) 	{
		k = 1; plus_s[i] += 10;}					// 오류 생길 수 있다.
	else k = 0;								}}
	if (plus_s[0] < 0)
		{plus_s[0] += 10; k = 1;}
	else k = 0;
	
	for (int i = 0; i <= 49; i++)			{		// 정수 빼기
	plus_j[i] = in1_j[i] - in3_j[i] - k;
	if (plus_j[i] < 0)	{
		k = 1; plus_j[i] += 10;}
	else k = 0;								}

	}

	else { // 뒤에 수가 큰 경우

	for (int i = 8; i >= 0; i--)			{	// 소수 빼기
	plus_s[i] = in3_s[i] - in1_s[i] - k;
	if ( i != 0)	{
	if (plus_s[i] < 0) 	{
		k = 1; plus_s[i] += 10;}					// 오류 생길 수 있다.
	else k = 0;								}}
	if (plus_s[0] < 0)
		{plus_s[0] += 10; k = 1;}
	else k = 0;
	
	for (int i = 0; i <= 49; i++)			{		// 정수 빼기
	plus_j[i] = in3_j[i] - in1_j[i] - k;
	if (plus_j[i] < 0)	{
		k = 1; plus_j[i] += 10;}
	else k = 0;								}

	}


	for (int i = 49; i >= 0; i--)			{		// 수를 문자로 바꾸기
	if (plus_j[i] != 0)
	{temp_j = i; break;}					}
	
	for (int i = 0; i <= temp_j; i++)
	plus_j[i] += '0';
	
	for (int i = 8; i >= 0; i--)			{		// 수를 문자로 바꾸기
	if (plus_s[i] != 0)
	{temp_s = i; break;}					}

	if(temp_s != 0){
	for (int i = 0; i <= temp_s; i++)
	plus_s[i] += '0';}
	
	if(temp_s == 0){
	if(plus_s[0] != 0){
	for (int i = 0; i <= temp_s; i++)
	plus_s[i] += '0';}}
	
	p = strlen(plus_s);
	
/*
	for (int i = 0; i <= 8; i++)			{
	if (plus_s[i] != '0')
	q = 1; break;						}
	if (q == 0)
	p = 0;
	else p = 1;
*/
	
	last = strlen(plus_j) - 1;		// 첫번째 정수 배열 뒤집기1
	while(1) {
	if(first > last) break;
	temp = plus_j[last];
	plus_j[last] = plus_j[first];
	plus_j[first] = temp;
	first++; last--;
			 }
	printf("%d",daeso);
	printf("= ");
   if (daeso == 1)
   printf("-");	   
	printf("%s", plus_j);
	if ( p != 0)
	printf(".%s", plus_s);
			   }
	default: ;}}

return 0;}
