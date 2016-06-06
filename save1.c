#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 60

int main(void){
	int i;
	static int cnt = 0;
	char x;
	char x1[N] = {};
	char equal;
	char a[N] = {};

	cnt ++;

	if (cnt >= 10)
		return 0; 

	else{

		scanf("%c %c %s", &x, &equal, a);

		for(i=0; i < strlen(a); i++)
			x1[i] = a[i];

		FILE *out;
		out = fopen("save","a+");

		fprintf(out, "%c = %s\n", x, x1);
		fclose(out);
	}
	return 0;
}
