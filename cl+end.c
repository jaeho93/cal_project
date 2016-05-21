#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int cl(int i){
		system("clear");
	return 0;
}

int e_xit(int i){
	return 0;}

int main(void){
	
	int i = 0;
	char Input[60];
 	char clear[60] = "clear";
	char end[60] = "end";

start:
	printf("(input) ");
	scanf("%s", Input);

	i = strcmp (Input, clear);
	if (i == 0)
	{cl(1); goto start;}

	else { 
	
	i = strcmp (Input, end);
	if (i == 0)
		e_xit(1);
	else{
		printf ("error\n");
	  	goto start;
	}}


	return 0;
}
