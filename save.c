#include<stdio.h>
#include<string.h>
#define N 60
int main(void){
	int i=0;
	char x;
	char	x1[N]={}; 
	char equal; 
	char a[N]={};

	//scanf("%c");
	//printf("= undefined.\n");

	scanf("%c %c %s",&x, &equal, a); // 변수 x 입력 
	printf("= %s",a);

	printf("\n");

	for( i=0; i<strlen(a) ; i++)
		x1[i] = a[i];  //변수 x1 에 저장 


	// save 파일에 변수 저장


	FILE *out;
	out = fopen("save","w");

	fprintf(out,"x = %s\n",x1);
	fclose(out);


	return 0;
}
