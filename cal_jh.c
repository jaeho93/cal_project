#include <stdio.h>
#include <string.h>
#include <Stdlib.h>
#include <stdbool.h>
#define N 60

int main(void){

	char Input1[N] = {};
	char Input2[N] = {};
	char Input3[N] = {};
	char Input1_j[50] = {};
	char Input3_j[50] = {};
	char Input1_s[9] = {};
	char Input3_s[9] = {};
	char plus_j[N] = {};
	char plus_s[N] = {};
	char temp = 0;
	char temp_j;
	int str_Input1, str_Input2, str_Input3, str_plus_j, str_plus_s;
	int first = 0, last = 0;

start:

	printf("(input) ");
	scanf("%s", Input1);
	str_Input1 = strlen(Input1);

	if (str_Input1 == 1);
		else { // 사칙연산 시작

			scanf("%s", Input2);
			str_Input2 = strlen(Input2);

			if (str_Input2 == 1) // 사칙연산인지 결정
			{ scanf("%s", Input3);
				switch (Input2[0]){
			case '+' :
				{
				for(int i = 0; i <= 49; i++) // 정수 소수 분리 1
				{if (Input1[i] == '.')
					{temp_j = i+1; break;}
				else Input1_j[i] = Input1[i];
				}
				for(int i = 0; i <= 8; temp_j++, i++)
					Input1_s[i] = Input1[temp_j];
				
				for(int i = 0; i <= 49; i++)  // 정수 소수 분리 2
				{if (Input3[i] == '.')
					{temp_j = i+1; break;}
				else Input3_j[i] = Input3[i];
				}
				for(int i = 0; i <= 8; temp_j++, i++)
					Input3_s[i] = Input3[temp_j];

				last = strlen(Input1_j) - 1; // 배열 뒤집기 1
				while(1){
					if(first > last) break;
					temp = Input1_j[last];
					Input1_j[last] = Input1_j[first];
					Input1_j[first] = temp;
					first++; last--;
				}
				first = 0, last = 0;
				printf("%s\n", Input1_j);
				
				last = strlen(Input1_s) - 1;
				while(1){
					if(first > last) break;
					temp = Input1_s[last];
					Input1_s[last] = Input1_s[first];
					Input1_s[first] = temp;
					first++; last--;
				}
				first = 0, last = 0;
				printf("%s\n", Input1_s);


				last = strlen(Input3_j) - 1; // 배열 뒤집기 2
				while(1){
					if(first > last) break;
					temp = Input3_j[last];
					Input3_j[last] = Input3_j[first];
					Input3_j[first] = temp;
					first++; last--;
				}
				first = 0, last = 0;
				printf("%s\n", Input3_j);
				
				last = strlen(Input3_s) - 1;
				while(1){
					if(first > last) break;
					temp = Input3_s[last];
					Input3_s[last] = Input3_s[first];
					Input3_s[first] = temp;
					first++; last--;
				}
				first = 0, last = 0;
				printf("%s\n", Input3_s);

				if (strlen(Input1_j) >= strlen(Input3_j))
						str_plus_j = strlen(Input1_j);
				else str_plus_j = strlen(Input3_j);

				if (strlen(Input1_s) >= strlen(Input3_s))
						str_plus_s = strlen(Input1_s);
				else str_plus_s = strlen(Input3_s);


				for (int i = 0, k = 0; i <= (str_plus_j-1); i++)  //더하기

				{
				plus_j[i] = (Input1_j[i]-'0') + (Input3_j[i]-'0') + k;
				if (plus_j[i] >= 10)
					k = 1;
				else k = 0;}
				

				for (int i = 0, k = 0; i <= (str_plus_s-1); i++)
				{plus_s[i] = (Input1_s[i]-'0') + (Input3_s[i]-'0') + k;
				if (plus_s[i] >= 10)
					k = 1;
				else k = 0;}
			
				for (int i = 0; i <= str_plus_j; i++)
				plus_j[i] += '0';
				for (int i = 0; i <= str_plus_s; i++)
				plus_s[i] += '0';



				last = strlen(plus_j) - 1; // 배열 뒤집기 3
				while(1){
					if(first > last) break;
					temp = plus_j[last];
					plus_j[last] = plus_j[first];
					plus_j[first] = temp;
					first++; last--;
				}
				first = 0, last = 0;
				printf("%s\n", plus_j);
				
				last = strlen(plus_s) - 1;
				while(1){
					if(first > last) break;
					temp = plus_s[last];
					plus_s[last] = plus_s[first];
					plus_s[first] = temp;
					first++; last--;
				}
				first = 0, last = 0;
				printf("%s\n", plus_s);
				printf("%s.%s\n", plus_j,plus_s);
				}
			default: ;}}}
				






return 0;}




