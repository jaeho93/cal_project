#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 60
int main(void){
	
	char a[N]={0}, b[N]={0}, c[N]={0};
	int i=0, t=0, str_a, str_b;
	
	scanf("%s",a);
	str_a=strlen(a);

	scanf("%s",b);
	str_b=strlen(b);
	
	for(i=str_a-1;i>=0;i--){
		printf("%c",a[i]);}
	printf("\n");             // 입력받은 배열 a  거꾸로 출력
	
	for(t=str_b-1;t>=0;t--){
		printf("%c",b[t]);}
	printf("\n");            // 입력받은 배열 b 거꾸로 출력

	for(i=str_a-1, t=str_b-1;i>=0||t>=0;i--,t--){
		// i,t 재설정, i와 t 둘 다 0이하가  될 때까지 for문 반복
		
		if(i>=t){
			c[i]=a[i]+b[t]; // a의 길이가 더 길면 c의길이도 a 길이까지
			
			/* if(c[i]>9){
				c[i+1]=c[i]/10;
				c[i]=c[i]%10;} */
			
			if(b[t]==0){
				printf("%d",c[i]-48);}
			else printf("%d",c[i]-96);}   
	// b의 배열이 끝나면 a[i] 값의 아스키코드 값이 나옴 => 0의 아스키코드를 빼줌.
	// a와 b 모두 값이 0이 아닌 경우에는 알파벳소문자로 나옴=> a의 아스키코드를 빼줌
		
		else {
			c[t]=a[i]+b[t];

			if(a[i]==0){
				printf("%d",c[t]-48);}
			else printf("%d",c[t]-96);}
	}
	printf("\n");
	
	
	return 0;
}
