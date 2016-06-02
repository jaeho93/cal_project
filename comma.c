#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comma1(char n[]);

int main(void){

	char a[61]={}, a_up[51]={}, a_down[11]={}; // a배열을 정수부, 소수부로 나눌 것
	int dot, t, s; // dot는 점의 위치, s는 소수부 위치 기억용

	scanf("%s",a); // a 배열 입력받음

	for(t=0; t < strlen(a); t++){ // a 배열 쪼개기
		if(a[t]=='.'){
			dot = t;
			s = dot + 1;
			break;             // 점의 우치와 소수부위치 기억
		}
		else  a_up[t] = a[t];  // a 배열 정수부
	}

	for(t=0; t < 9; s++, t++)
		a_down[t] = a[s];      // a 배열 소수부

	comma1(a_up);   // a 배열 정수부 , 입력 받기

	printf(".");   // . 출릭

	comma1(a_down); // a배열 소수부 , 입력 받기

	return 0;
}


void comma1(char n[]){
	int t, i;

	i = (strlen(n)-1)%3;     // i는 3자리마다 , 입력 받을 때의 나머지

	for(t=0 ; t < strlen(n) ; t++){
		printf("%d",n[t]-48);    // 숫자 하나씩 출력하기

		if( t == strlen(n)-1 )
			break;               // 마지막 수는 , 출력 X

		if( t%3 == i )
			printf(",");         // , 입력
	}}
