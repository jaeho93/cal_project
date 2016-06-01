#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 60

int main(void){

	char a[N]={0}, b[N]={0};
	int c[N]={0};
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

		if(i>=t){
			if(t>=0){

				c[i]=a[i]+b[t];
				printf("%d",c[i]-96);}

			/*if(c[i+1]>=10){

				if(i==str_a)
					continue;

				else {
					c[i]+=c[i+1]/10;
					printf("%d\n",c[i]%10);}} */

			else if(t<0){
				c[i]=a[i];
				printf("%d",c[i]-48);}}

		else {
			c[t]=a[i]+b[t];

			if(a[i]==0){
				printf("%d",c[t]-48);}
			else printf("%d",c[t]-96);}}

			return 0;
}
