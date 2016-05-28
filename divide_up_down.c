#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[61]={}, a_up[51]={}, a_down[10]={};
	char b[61]={}, b_up[51]={}, b_down[10]={};
	int input_a=0, input_b; //점의 위치 기억하는 변수
	int i=0,j=0,k=0,t=0;

	for(i=0; i<61; i++){ //a배열 입력받는 과정
		a[i] = getchar();
		if(a[i] == '\n')
			break;	
	}
		
	for(j=0; j<61; j++){ //b배열 입력받는 과정
		b[j] = getchar();
		if(b[j] == '\n')
			break;	
	}

	for(int m=0; m<i ; m++){
		if(a[m] == '.'){
			input_a = m; //a배열 점의 위치 기억
		}
	}
	printf("input_a의값:%d\n",input_a);

	for(int n=0; n<i ; n++){
		if(b[n] == '.'){
			input_b = n; //b배열 점의 위치 기억
		}
	}
	printf("input_b의값:%d\n",input_b);
		
	for(int p = 0 ; p<input_a; p++) // 소숫점 위치 확인후에 정수부 소수부로 나누는 과정
		a_up[p] = a[p];
	for(int q=input_a+ 1; q<i ; q++){
		a_down[k] = a[q];  //변수 k는 처음 부분에서 미리 선언해줌
		k++;
	}
	for(int p = 0 ; p<input_b; p++)
		b_up[p] = b[p];
	for(int q=input_b+ 1; q<j ; q++){
		b_down[t] = b[q];  //변수 t는 처음 부분에서 미리 선언해줌
		t++;
	}
	
	for(int r=0 ; r<strlen(a_up) ; r++) // a와 b 배열의 정수부 소수부 나눠서 출력하는 과정
		printf("%c",a_up[r]);
	for(int s=0 ; s<strlen(a_down) ; s++)
		printf("%c", a_down[s]);

	printf("\n");

	for(int r=0 ; r<strlen(b_up) ; r++)
		printf("%c",b_up[r]);
	for(int s=0 ; s<strlen(b_down) ; s++)
		printf("%c", b_down[s]);

	return 0;

}

