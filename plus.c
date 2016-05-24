#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 60

int main(void){
	char a[N]={}, b[N]={};
	char c[N]={};
	int i=0, t=0, str_a, str_b, str_c;

	scanf("%s",a);
	str_a=strlen(a);

	scanf("%s",b);
	str_b=strlen(b);

	for(i=str_a-1;i>=0;i--)
		printf("%c",a[i]);
	printf("\n");             // 입력받은 배열 a  거꾸로 출력

	for(t=str_b-1;t>=0;t--)
		printf("%c",b[t]);
	printf("\n");            // 입력받은 배열 b 거꾸로 출력

	i = str_a -1;
	t = str_b -1;

	int shift;
	if(str_a >= str_b){

		shift = str_a - str_b;

		for( ; t>=0; t--) // 길이가 짧은 배열b 위치 재조정
			b[t+shift] = b[t];
		for(;shift>0;shift--)	// 위치 조정 후 남는 공간에 '0' 넣기
			b[shift-1] = '0'; 

		for(; i >= 0; i--){
			c[i+1] += ((a[i]+b[i])); 

			if(c[i+1] >= (10+96)){
				c[i]+=1;
				c[i+1] -= (96+10);}

			else{ c[i+1] -= 96;}			
		}
		if(c[0] == 0)
			for(int j=1;j <= str_a;j++)
				printf("%d",c[j]);
		else
			for(int j=0; j<=str_a ;j++)
				printf("%d",c[j]);
	}

	else if(str_b > str_a){  //길이가 짧은 a 배열 위치 조정
		shift = str_b - str_a;

		for(; i>=0 ; i--)	
			a[i+shift] = a[i];

		for(; shift>0 ; shift--)
			a[shift-1] = '0';

		for( ; t >= 0 ;t--){

			c[t+1] += ((a[t]+b[t]));

			if(c[t+1] >= (10+96)){

				c[t]+=1;

				c[t+1] -= (96+10);}

			else { c[t+1] -= 96;}	}

	

	if(c[0] == 0)
	for(int j=1; j <= str_b ; j++)
			printf("%d",c[j]);

	else if(c[0] != 0)
		for(int j=0 ; j <= str_b ; j++)
			printf("%d", c[j]);

	}
	return 0;
}
