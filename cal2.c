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
		
		for( ; t>=0; t--) // 길이가 짧은 배열 위치 재조정
			b[t+shift] = b[t];

		for(;shift>0;shift--)	// 위치 조정 후 남는 공간에 '0' 넣기
				b[shift-1] = '0'; 

		for(; i >= 0; i--){
			c[i] += (a[i]+b[i]); 
			
			if(c[i] >= 10)
			{
				c[i-1] += 1;
				c[i] = c[i]-10;	
			}   
		}
		
}
for(i=0;i<=str_a-1;i++){
	printf("%d",c[i]-87);
}	

printf("%d", atoi(c));
		
		
	return 0;
}

