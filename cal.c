#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 60

void plus(char a_up[], char a_down[], char b_up[], char b_down[]);
void minus(char a_up[], char a_down[], char b_up[], char b_down[]);
void multiple(char a_up[], char a_down[], char b_up[], char b_down[]);
void devide(char a_up[], char a_down[], char b_up[], char b_down[]);

int main(void){

	char a[61], b[61], sign[2];
	char a_up[51]={}, a_down[10]={};
	char b_up[51]={}, b_down[10]={};
	char clear[N] = "clear";
	char end[N] = "end";
	char VAR[N] = "VAR";
	char var[10] = {};
	char var_var[10][60] = {};
	int input_a=0, input_b=0; //점의 위치 기억하는 변수
	int i=0, cnt_a=0, cnt_b=0, k=0, t=0;
	int temp=0;

	for(i=0; i<61; i++){ // 배열 입력받는 과정
		a[i] = getchar();
		if(a[i] == ' '){
			cnt_a=i;
			break;}
	}

	for(i=0; i<61; i++){ // 배열 입력받는 과정
		sign[i] = getchar();
		if(sign[i] == ' ')
			break;	
	}
	for(i=0; i<61; i++){ // 배열 입력받는 과정
		b[i] = getchar();
		if(b[i] == '\n'){
			cnt_b=i;
			break;}
	}

	for(int m=0; m < cnt_a ; m++){
		if(a[m] == '.'){
			input_a = m; //a배열 점의 위치 기억
			break;
		}
		else
			a_up[m] = a[m]; //점을 만나지 못하면 정수 배열에 계속 입력

	}
	printf("input_a의값:%d\n",input_a);

	for(int n=0; n < cnt_b ; n++){
		if(b[n] == '.'){
			input_b = n; //b배열 점의 위치 기억
			break;
		}
		else
			b_up[n] = b[n]; //점을 만나지 못하면 정수 배열에 계속 입력
	}

	printf("input_b의값:%d\n",input_b);

	if(input_a != 0){	
		for(int q = input_a + 1; q < cnt_a ; q++){
			a_down[k] = a[q];  //변수 k는 처음 부분에서 미리 선언해줌
			k++;
		}
	}
	if(input_b != 0){
		for(int q = input_b + 1; q < cnt_b ; q++){
			b_down[t] = b[q];  //변수 t는 처음 부분에서 미리 선언해줌
			t++;
		}
	}

	int first=0, last=0; // 정수부(a_up, b_up) 배열 뒤집는 과정
	last = strlen(a_up) - 1;
	while(1){
		if(first > last)
			break;
		temp = a_up[last];
		a_up[last] = a_up[first];
		a_up[first] = temp;
		first++, last--;
	}
	printf("%s\n", a_up);
	first=0, last=0;

	last = strlen(b_up) - 1;
	while(1){
		if(first > last)
			break;
		temp = b_up[last];
		b_up[last] = b_up[first];
		b_up[first] = temp;
		first++, last--;
	}
	printf("%s\n", b_up);

	switch(sign[0]){
		case '+' : plus(a_up, a_down, b_up, b_down);
				   break;
		case '-' : minus(a_up, a_down, b_up, b_down);
				   break;
		case '*' : multiple(a_up, a_down, b_up, b_down);
				   break;
		case '/' : devide(a_up, a_down, b_up, b_down);
				   break;
	}

	return 0;
}

void plus(char a_up[], char a_down[], char b_up[], char b_down[]){

	char plus_up[51] = {}, plus_down[10]={};

	if(strlen(a_down) >= strlen(b_down)){
		for(int i=strlen(a_down)-1; i>=0; i--){
			if(b_down[i] == 0)
				plus_down[i] += a_down[i] -48;
			else{
				plus_down[i] += ((a_down[i] - 48) + (b_down[i] - 48));
				if(plus_down[i] >= 10){
					if(i==0){
						plus_up[0] += 1; // 정수에 1 증가
						plus_down[i] -= 10;
					}
					else{
						plus_down[i-1] += 1;
						plus_down[i] -= 10;
					}
				}
			}
		}
	}
	else{
		for(int i=strlen(b_down)-1; i>=0; i--){
			if(a_down[i] == 0)
				plus_down[i] += b_down[i] -48;
			else{
				plus_down[i] += ((a_down[i] - 48) + (b_down[i] - 48));
				if(plus_down[i] >= 10){
					if(i==0){
						plus_up[0] += 1;
						plus_down[i] -= 10;
					}
					else{
						plus_down[i-1] += 1;
						plus_down[i] -= 10;
					}
				}
			}
		}
	}

	if(strlen(a_up) >= strlen(b_up)){ // 정수부(a_up 길이 >= b_up 길이) 덧셈 후 plus_up 배열에 저장
		for(int i=0; i<strlen(a_up) ; i++){
			if(b_up[i] == 0)
				plus_up[i] += (a_up[i]-48);
			else
				plus_up[i] += (a_up[i]-48) + (b_up[i]-48);
			if(plus_up[i] >= (10))
			{
				plus_up[i+1] += 1;
				plus_up[i] -= 10;
			}

		}

		if(plus_up[strlen(a_up)] != 0){
			for(int i=strlen(a_up) ; i>=0 ; i--)
				printf("%d",plus_up[i]);
		}
		else{
			for(int i = strlen(a_up)-1; i>=0 ; i--)
				printf("%d" , plus_up[i]);
		}
		printf("\n");
	}	

	else // 정수부(a_up의 길이 < b_up의 길이) 덧셈 후 plus_up 배열에 저장
	{
		for(int i=0; i<strlen(b_up); i++){
			if(a_up[i] == 0)
				plus_up[i] += (b_up[i]-48);
			else
				plus_up[i] += (b_up[i]-48) + (a_up[i]-48);
			if(plus_up[i] >= 10){
				plus_up[i+1] += 1;
				plus_up[i] -= 10;
			}
		}

		if(plus_up[strlen(a_up)] != 0){
			for(int i=strlen(a_up) ; i>=0 ; i--)
				printf("%d",plus_up[i]);
		}

		else{
			for(int i = strlen(a_up)-1; i>=0 ; i--)
				printf("%d" , plus_up[i]);
		}
	}
	printf("\n");

	if(strlen(a_down) >= strlen(b_down))
		for(int i=0; i<strlen(a_down); i++)
			printf("%d", plus_down[i]);
	
	else
		for(int i=0; i< strlen(b_down); i++)
			printf("%d", plus_down[i]);

	return ;
}
		
	void minus(char a_up[], char a_down[], char b_up[], char b_down[]){

					char minus_up[51] = {}, minus_down[10]={};
					}

					void multiple(char a_up[], char a_down[], char b_up[], char b_down[]){

					char multipe_up[51] = {}, multiple_down[10]={};
					}

					void devide(char a_up[], char a_down[], char b_up[], char b_down[]){

					char devide_up[51] = {}, devide_down[10] = {};
					}
