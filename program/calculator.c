#include <stdio.h>	// 단항 연산자 아직 구현 못함.ㅠㅠ								
#include <string.h>
#include <stdlib.h>
#define N 61

char in1[N] = {};
char in2[N] = {};
char in3[N] = {};
char res[N] = {};
char in1_j[51] = {};
char in3_j[51] = {};
char in1_s[10] = {};
char in3_s[10] = {};
char res_j[51] = {};
char res_s[10] = {};
int div_j[51] = {};

char var[10] = {};					// 여기는 변수 저장용으로 초기화 하지 않는다.
char var_var[10][61] = {};
int var_num = 0;

char c_lear[N] = "clear";
char e_nd[N] = "end";
char V_AR[N] = "VAR";

int str_in1, str_in2, str_in3, str_res_s;
int temp = 0, temp1_d = 0, temp3_d = 0, res_d = 0, temp_j = 0, temp_s = 0;
int first = 0, last = 0;
int k = 0, p = 0, q = 0, daeso = 0, choice = 0, chosen;

void c_hoice();		 // 명령 선택 (아직 구현 x)
void separate(); 			// 정수부 소수부 분리
void invert1();   			// 계산 전 배열 뒤집기
void invert2();				// 계산 후 배열 뒤집기
void compare();				// 앞뒤수 비교
void compare_div();			// 나누기용 앞뒤수 비교
void convert1();			// char > int 변환
void convert2();			// int > char 변환
void convert3();
void plus();
void minus();
void minus_div();			// 나누기용 마이너스
void mutiply();
void divide();
void remain();
void initialization();
void comma(char n[]);
void VAR();
void var_in();

int main() {

printf("Start....");
start:

	printf("\n(input) ");			//계산기 프로그램 시작
	
	scanf("%s", in1);
	str_in1 = strlen(in1);
																
	c_hoice();

	if (chosen != 1){

	scanf("%s", in2);
	str_in2 = strlen(in2);

	scanf("%s", in3);
	str_in3 = strlen(in3);

	separate();

	switch (in2[0]) 				{		
	
	case '+' : { invert1(); convert1(); plus(); convert2(); invert2(); break; }
	case '-' : { invert1(); compare(); convert1(); minus(); convert2(); invert2(); break; }
	/*case '*' : { multiply(); }*/
	case '/' : { invert1(); compare(); convert1(); divide(); convert2(); invert2(); break; }
	case '%' : { invert1(); compare(); convert1(); remain(); convert2(); invert2(); break; }

	default: ;
									}	

	printf("= ");
	if (daeso == 1)
	printf("-");
	comma(res_j);
	if (p != 0)
	{printf(".");
	comma(res_s);}					

	}

    initialization();

	goto start;

	return 0;
}

void c_hoice(){

	var_in(); if (chosen == 1) return ;
	
	choice = strcmp (in1, c_lear);
	if (choice == 0) {system("clear"); chosen = 1; return ;}
	else { choice = strcmp (in1, e_nd); 
	if (choice == 0) exit(1);
	else { choice = strcmp (in1, V_AR);
	if (choice == 0) {VAR(); chosen = 1; return ;}
	}}

} // choice 함수



void separate(){		// 정수부 소수부 분리하는 함수

	for (int i = 0; i <= 49; i++) {
	if (in1[i] == '.')
	{temp1_d = i+1; break;}
	else in1_j[i] = in1[i];		  }
	if (in1[50] == '.')
	temp1_d = 51;

	if (temp1_d != 0){
	for (int i = 0; i <= 8; temp1_d++, i++)
	in1_s[i] = in1[temp1_d];
	}

	for (int i = 0; i <= 49; i++) {
	if (in3[i] == '.')
	{temp3_d = i+1; break;}
	else in3_j[i] = in3[i];		  }
	if (in3[50] == '.')
	temp3_d = 51;

	if (temp3_d != 0){
	for (int i = 0; i <= 8; temp3_d++, i++)
	in3_s[i] = in3[temp3_d];
	}
} // separate 함수 끝			

void invert1(){			// 계산 전 정수부 배열을 뒤집는 함수

	last = strlen(in1_j) - 1;
	while(1) {
	if(first > last) break;
	temp = in1_j[last];
	in1_j[last] = in1_j[first];
	in1_j[first] = temp;
	first++; last--;
 	 	 	 }
	first = 0; last = 0;
 
	last = strlen(in3_j) - 1;
	while(1) {
	if(first > last) break;
	temp = in3_j[last];
	in3_j[last] = in3_j[first];
	in3_j[first] = temp;
	first++; last--;
 	 	 	 }
	first = 0; last = 0;
} // invert1 함수 

void invert2(){			// 계산 후 정수부 배열을 뒤집는 함수

	last = strlen(res_j) - 1;
	while(1) {
	if(first > last) break;
	temp = res_j[last];
	res_j[last] = res_j[first];
	res_j[first] = temp;
	first++; last--;
 	 	 	 }
	first = 0; last = 0;
 
} // invert2 함수 

void compare(){				// 빼기, 나누기 전 크기 비교하는 함수

	if (strlen(in3_j) > strlen(in1_j))
	daeso = 1;
	else if(strlen(in3_j) < strlen(in1_j))
	{daeso = 0; goto dae;}
	else{
	for (int i = strlen(in1_j); i >= 0; i--)
	{if (in1_j[i] == in3_j[i]);
	 else if (in1_j[i] > in3_j[i])
	 {daeso = 0; goto dae;}
	 else {daeso = 1; break;}}}

	 if (daeso == 0) {
	 for (int i = 0; i <= 8; i++) {
	 if (in1_s[i] == in3_s[i]);
	 else if (in1_s[i] > in3_s[i])
		  {daeso = 0; break;}
	 else {daeso = 1; break;}}}
dae:;
} // compare 함수

void compare_div(){				// 나누기에 사용하는 크기 비교하는 함수

	for (int i = 49; i >= 0; i--)   {
	if ( in3_j[i] > res_j[i] )
	{ daeso = 1; return ; }
	else if ( in3_j[i] < res_j[i] )
	{ daeso = 0; return ; }          }
	
	for (int i = 0; i <= 8; i++)     {
	if ( in3_s[i] > res_s[i] )
	{ daeso = 1; return ; }
	else if ( in3_s[i] < res_s[i] )
	{ daeso = 0; return ; }          }

} // compare_div 함수

void convert1(){		// char > int 변환 함수

	for (int i = 0; i <= 49; i++) {
	if  (in1_j[i] == 0) ;
	else in1_j[i] -= '0';		  }

	if  (temp1_d != 0){
	for (int i = 0; i <= 8; i++)  {
	if  (in1_s[i] == 0);
	else in1_s[i] -= '0';		  }
	}

	for (int i = 0; i <= 49; i++) {
	if  (in3_j[i] == 0) ;
	else in3_j[i] -= '0';		  }

	if  (temp3_d != 0){
	for (int i = 0; i <= 8; i++)  {
	if  (in3_s[i] == 0);
	else in3_s[i] -= '0';		  }
	}
}  // convert1 함수 


void convert2(){		// int > char 변환 함수 - 마이너스 일때

	for (int i = 49; i >= 0; i--) {
	if  (res_j[i] != 0)
	{temp_j = i; break;}		  }

	for (int i = 0; i <= temp_j; i++)
	res_j[i] += '0';
	
	for (int i = 8; i >= 0; i--) {
	if  (res_s[i] != 0)
	{temp_s = i; break;}	     }

	if (temp_s != 0)              {
	for (int i = 0; i <= temp_s; i++)
	res_s[i] += '0';             }

	if (temp_s == 0){
	if (res_s[0] != 0){
	for (int i = 0; i <= temp_s; i++)
	res_s[i] += '0';}}

	p = strlen(res_s);

}  // convert2 함수 
/*
void convert3(){		// int > char 변환 함수 - 플러스 일때

	for (int i = 49; i >= 0; i--)			{		// 수를 문자로 바꾸기
	if (res_j[i] != 0)
	{temp_j = i; break;}					}
	
	for (int i = 0; i <= temp_j; i++)
	res_j[i] += '0';
	
	for (int i = 8; i >= 0; i--)			{		// 수를 문자로 바꾸기
	if (res_s[i] != 0)
	{temp_s = i; break;}					}

	for (int i = 0; i <= temp_s; i++)
	res_s[i] += '0';

} // convert3 함수
*/
void plus(){

	for (int i = 8; i >= 0; i--)			{	// 소수 더하기
	res_s[i] = in1_s[i] + in3_s[i] + k;
	if (res_s[i] >= 10) 	{
		k = 1; res_s[i] -= 10;}					// 오류 생길 수 있다.
	else k = 0;								}
	
	p = strlen(res_s);
	
	for (int i = 0; i <= 49; i++)			{		// 정수 더하기
	res_j[i] = in1_j[i] + in3_j[i] + k;
	if (res_j[i] >= 10)	{
		k = 1; res_j[i] -= 10;}
	else k = 0;								}

} // plus 함수 

void minus(){

	if (daeso == 0) //앞에 수가 큰 경우
	{
	for (int i = 8; i >= 0; i--)			{	// 소수 빼기
	res_s[i] = in1_s[i] - in3_s[i] - k;
	if ( i != 0)	{
	if (res_s[i] < 0) 	{
		k = 1; res_s[i] += 10;}					// 오류 생길 수 있다.
	else k = 0;								}}
	if (res_s[0] < 0)
		{res_s[0] += 10; k = 1;}
	else k = 0;
	
	for (int i = 0; i <= 49; i++)			{		// 정수 빼기
	res_j[i] = in1_j[i] - in3_j[i] - k;
	if (res_j[i] < 0)	{
		k = 1; res_j[i] += 10;}
	else k = 0;								}

	}

	else { // 뒤에 수가 큰 경우

	for (int i = 8; i >= 0; i--)			{	// 소수 빼기
	res_s[i] = in3_s[i] - in1_s[i] - k;
	if ( i != 0)	{
	if (res_s[i] < 0) 	{
		k = 1; res_s[i] += 10;}					// 오류 생길 수 있다.
	else k = 0;								}}
	if (res_s[0] < 0)
		{res_s[0] += 10; k = 1;}
	else k = 0;
	
	for (int i = 0; i <= 49; i++)			{		// 정수 빼기
	res_j[i] = in3_j[i] - in1_j[i] - k;
	if (res_j[i] < 0)	{
		k = 1; res_j[i] += 10;}
	else k = 0;								}

	}
} // minus 함수

void minus_div(){   // 나누기용 마이너스 함수

	for (int i = 8; i >= 0; i--)			{	// 소수 빼기
	res_s[i] = res_s[i] - in3_s[i] - k;
	if ( i != 0)	{
	if (res_s[i] < 0) 	{
		k = 1; res_s[i] += 10;}					// 오류 생길 수 있다.
	else k = 0;								}}
	if (res_s[0] < 0)
		{res_s[0] += 10; k = 1;}
	else k = 0;
	
	for (int i = 0; i <= 49; i++)			{		// 정수 빼기
	res_j[i] = res_j[i] - in3_j[i] - k;
	if (res_j[i] < 0)	{
		k = 1; res_j[i] += 10;}
	else k = 0;								}

} // minus_div 함수

void divide(){

	if ( daeso == 1 )
	{res_j[0] = 0; daeso = 0; return ;}

	else {
	minus(); compare_div(); div_j[0] = 1;
	if (daeso == 1) ;
	else {
	while( daeso != 1 ) {
	minus_div();
	compare_div();
	div_j[0]++;
	for(int i = 0; i <= 49; i++){
	while (div_j[i] >= 10)
	{div_j[i] -= 10; div_j[i+1]++;}}
	}}}

	for (int i = 0; i <= 49; i++)
		res_j[i] = div_j[i];
	for (int i = 0; i <= 8; i++)
		res_s[i] = 0;
	daeso = 0;
} // divide 함수

void remain(){

	if ( daeso == 1 )
	{res_j[0] = 0; daeso = 0; return ;}

	else {
	minus(); compare_div();
	if (daeso == 1) ;
	else {
	while( daeso != 1 ) {
	minus_div();
	compare_div();
						}
	}}

	daeso = 0;

} // remain 함수

void initialization(){

for (int i = 0; i <= 59; i++)
{
in1[i] = 0;
in2[i] = 0;
in3[i] = 0;
res[i] = 0;
}
for (int i = 0; i <= 49; i++)
{
in1_j[i] = 0;
in3_j[i] = 0;
res_j[i] = 0;
div_j[i] = 0;
}
for (int i = 0; i <= 8; i++)
{
in1_s[i] = 0;
in3_s[i] = 0;
res_s[i] = 0;
}

str_in1 = 0, str_in2 = 0, str_in3 = 0, str_res_s = 0;
temp = 0, temp1_d = 0, temp3_d = 0, temp_j = 0, temp_s = 0;
first = 0, last = 0;
k = 0, p = 0, q = 0, daeso = 0, choice = 0, chosen = 0;

} // 초기화 함수

void comma(char n[]){

	int t, i;
	i = (strlen(n) - 1) % 3;

	for (t = 0; t <= strlen(n)-1; t++){
		printf("%c", n[t]);
	if (t == strlen(n) - 1) break;
	if (t % 3 == i) printf(",");     }

} // comma 함수

void VAR(){

	for (int i = 0; var[i] != 0; i++){
	for (int u = 0; u <= N; u++)
	in1[u] = var_var[i][u];
	separate();
	p = strlen(in1_s);
	printf("%c = ", var[i]);
	comma(in1_j);
	if (p != 0)
	{printf(".");
	comma(in1_s);}
	printf("\n");}	
	return ;

} // VAR 함수

void var_in(){

	if (str_in1 == 1) 						{
	if (in1[0] >= 'A' && in1[0] <= 'Z')		{
	scanf("%s", in2); 
	if (in2[0] == '=')  {
	var[var_num] = in1[0];
	scanf("%s", var_var[var_num]);				// 콤마 찍기 구현 안됨
	for (int u = 0; u <= N; u++)
	in1[u] = var_var[var_num][u];
	separate();
	p = strlen(in1_s);
	printf("= ");
	comma(in1_j);
	if (p != 0)
	{printf(".");
	comma(in1_s);}
	printf("\n");	
	var_num++; chosen = 1;
	return ;			}					}
	
	else if (in1[0] >= 'a' && in1[0] <= 'z')  {
	scanf("%s", in2);
	if (in2[0] = '=')   {
	var[var_num] = in1[0] - 32;
	scanf("%s", var_var[var_num]);
	for (int u = 0; u <= N; u++)
	in1[u] = var_var[var_num][u];
	separate();
	p = strlen(in1_s);
	printf("= ");
	comma(in1_j);
	if (p != 0)
	{printf(".");
	comma(in1_s);}
	printf("\n");	
	var_num++; chosen = 1;
	return ;			}					  }}

} // var_in 함수



