#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[61]={}, a_up[51]={}, a_down[10]={};
	char b[61]={}, b_up[51]={}, b_down[10]={};
	char plus_up[51] = {}, plus_down[10]={};
	int input_a=0, input_b=0; //점의 위치 기억하는 변수
	int i=0,j=0,k=0,t=0;
	int temp=0;

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
			break;
		}
		else
			a_up[m] = a[m]; //점을 만나지 못하면 정수 배열에 계속 입력
		
	}
	printf("input_a의값:%d\n",input_a);

	for(int n=0; n<j ; n++){
		if(b[n] == '.'){
			input_b = n; //b배열 점의 위치 기억
			break;
		}
		else
			b_up[n] = b[n]; //점을 만나지 못하면 정수 배열에 계속 입력
	}
	printf("input_b의값:%d\n",input_b);
	if(input_a != 0){	
		for(int q=input_a+ 1; q<i ; q++){
			a_down[k] = a[q];  //변수 k는 처음 부분에서 미리 선언해줌
			k++;
		}
	}
	if(input_b != 0){
		for(int q=input_b+ 1; q<j ; q++){
			b_down[t] = b[q];  //변수 t는 처음 부분에서 미리 선언해줌
			t++;
		}
	}
	printf("strlen(a_up)의 값:%d\n",strlen(a_up));
	printf("strlen(b_up)의 값:%d\n",strlen(b_up));
/*	
	for(int r=0 ; r<strlen(a_up) ; r++) // a와 b 배열의 정수부 소수부 나눠서 출력하는 과정
		printf("%c",a_up[r]);
	if(input_a != 0){
		for(int s=0 ; s<strlen(a_down) ; s++)
			printf("%c", a_down[s]);
	}
	printf("\n");

	for(int r=0 ; r<strlen(b_up) ; r++)
		printf("%c",b_up[r]);
	if(input_b != 0){
		for(int s=0 ; s<strlen(b_down) ; s++)
			printf("%c", b_down[s]);
	}
*/	

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
	
	if(strlen(a_up) >= strlen(b_up))
	{
		for(int i=0; i<strlen(a_up) ; i++){
			if(b_up[i] == 0)
				plus_up[i] = (a_up[i]-48)+ (b_up[i]);
			else
				plus_up[i] = (a_up[i]-48) + (b_up[i]-48);
			if(plus_up[i] >= (10))
			{
				plus_up[i+1] += 1;
				plus_up[i] -= 10;
			}
								
		}
	}
	for(int i = strlen(a_up)-1 ; i>=0 ; i--)
	{
		if(plus_up[i] > 96)
			printf("%d", plus_up[i]-48);	
		else
			printf("%d", plus_up[i]);
	}
	return 0;

}

