#include <stdio.h>

#include<stdlib.h>

int main(void){
	int  i, t;
	static int cnt = 0;
	char c, a[1024][100];
	FILE *in;
	in = fopen("save","r");

	while(( in = getchar() ) != EOF){
		if( in == NULL )
			cnt++;
	}

	for(i=0 ; i < cnt ; i++){
		for(t=0; t<3; t++){
			fscanf(in, "%s",a);
			printf("%s",a);
		}
	}
	fclose(in);
	return 0;
}
