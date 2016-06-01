#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	
	char a[61]={};
	int i, t=0;
	scanf("%s",a);
	
	for(; t < strlen(a) ; t++){
		printf("%d",a[t]-48);
		i = (strlen(a)-1)%3;
		if(t==strlen(a)-1)
			break;
		if( t%3 == i )
			printf(",");
	}

	return 0;
}
