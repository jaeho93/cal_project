#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define N 60

void cl(void);

int main(void){

	int i = 0;
	int var_num = 0;
	char Input1[N] = {};
	char Input2[N] = {};
	char clear[N] = "clear";
	char end[N] = "end";
	char VAR[N] = "VAR";
	char var[10] = {};
	char var_var[10][60] = {};
	int str_Input;

start:
	printf("(input) ");
	scanf("%s", Input1);
	str_Input = strlen(Input1);

	if (str_Input == 1)
	{if (Input1[0] >= 'A' && Input1[0] <= 'Z')
		{ scanf("%s", Input2);
		if (Input2[0] = '=')
		{var[var_num] = Input1[0];
		 scanf("%s", var_var[var_num]);
		 printf("= %s\n", var_var[var_num]);
		 var_num++;
		 goto start;}}
	else if (Input1[0] >= 'a' && Input1[0] <= 'z')
		{ scanf("%s", Input2);
		if (Input2[0] = '=')
		{var[var_num] = Input1[0] - 32;
		 scanf("%s", var_var[var_num]);
		 printf("= %s\n", var_var[var_num]);
		 var_num++;
		 goto start;}}}
	
	else
	{
		i = strcmp (Input1, clear);
		if (i == 0)
		{cl(); goto start;}

		else {
				i = strcmp (Input1, end);
				if (i == 0)
					exit(1);
				else{
					 i = strcmp (Input1, VAR);
					 if (i == 0)
						{
						  for (int i = 0; var[i] != 0; i++)
						  printf("%c = %s\n", var[i], var_var[i]);	  goto start;}
					 else{
						 printf("error\n");
						 goto start;
					 }}}}
	return 0;
}
void cl(void){system("clear");}

