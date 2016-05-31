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
	/*기본 개념 
	1. 처음에 a배열 b배열을 통해 문자열을 받음
  	2. a배열 b배열 안에있는 원소들을 일괄적으로 '0'을 빼줌으로써 숫자로 만들어줌
	3. mu배열에 숫자로 결과를 저장한다.
	4. change_mu배열에 mu배열의 원소들을 문자로 다시 저장한다
	5. change_mu배열의 원소를 정수부와 소수부로 나눈 뒤 .을 붙여 문자열로 출력한다.	

	여기서 change_mu를 사용한 이유
	만약 change_mu 배열을 만들지않고 mu배열만 사용했을경우
	ex) 89 * 79 의 경우 중간에 계산을 하면 mu[1]자리에 135가 입력된다
		135는 아스키 코드표의 최댓값인 126을 넘어가기때문에 오류발생
		따라서, mu 배열을 int형으로 바꾼 뒤, 다시 char형 배열인 change_mu에 넣어준다.
	  */
	char a[N] = {};
	char b[N] = {}; 
	int mu[N] = {};
	char change_mu[N] = {};
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
	a[i] -= '0';							// <오류>만약 문자 0을 받을경우 0 - '0' 이 돼서 null이 출력됨. 
	for (int i = 0; i <= strlen(b)-1; i++)  // b배열도 마찬가지
	b[i] -= '0';			 

	for (int i = 0; i <= strlen(a)-1; i++){
		if(a[i]==0){
			printf("%d",0);
			continue;
		}
	printf("%d\n", a[i]);
	}
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
	for(int i = 0; i <= m+2 ; i++){ //mu배열 정리(올림수 고려)
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

	for(int i =0; i<strlen(a)+strlen(b); i++)
		printf("%d",mu[i]);
	for (int i = 0; i <= strlen(a)+strlen(b); i++) //mu배열에 아스키코드 값 모두 더하기
	mu[i] += '0';

	printf("\n");

	for(int i =0; i<strlen(a)+strlen(b); i++)
		printf("%d",mu[i]);

	printf("\n");

	for(int i=0; i<strlen(a) + strlen(b) ; i++) // int형 배열의 원소들을 char형 배열로 옮기기
		change_mu[i] = mu[i];

	for(int i=0; i<strlen(a) + strlen(b) ; i++)
		printf("%c\n", change_mu[i]);

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
	printf("%s", change_mu);
	

	return 0;
}
