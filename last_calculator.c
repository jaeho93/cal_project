#include <stdio.h>								
#include <string.h>
#include <stdlib.h>
#define N 61

char begin[1000] = {};
char temp_in1[N] = {};
char temp_in3[N] = {};
char in1[N] = {};
char in2[N] = {};
char in3[N] = {};
char res[N] = {};
char in1_j[51] = {};
char in3_j[51] = {};
char in1_s[10] = {};
char in3_s[10] = {};
char last_mul[N] = {};
char res_j[51] = {};
char res_s[10] = {};
int mul_1[51] = {};
int mul_3[51] = {};
int div_1[61] = {};
int div_3[61] = {};
int mul[N] = {};
int div_j[51] = {};
char quo[61] = {};
int check[26] = {};

char var[10] = {};					// 여기는 변수 저장용으로 초기화 하지 않는다.
char var_var[10][61] = {};
int var_num = 0;

char c_lear[N] = "clear";
char e_nd[N] = "end";
char V_AR[N] = "VAR";
char s_ave[N] = "save";
char l_oad[N] = "load";

_Bool carry, point;

int str_in1, str_in2, str_in3, str_res_s, str_in3_j, str_in1_j;  //in1 , in2, in3, res_s의 길이
int temp = 0, temp1_d = 0, temp3_d = 0, res_d = 0, temp_j = 0, temp_s = 0;
char temp_var_s[10][10] = {}, temp_var_j[10][10] = {}, temp_var_d = 0;
char var_var_j[10][10] = {}, var_var_s[10][10] = {};
int first = 0, last = 0;
int k = 0, p = 0, q = 0, daeso = 0, choice = 0, chosen;
int m = 0, x = 0, y = 0;
int minus_sign_count = 0;
int if_minus_first = 0;    //input1 부호 체크
int if_minus_last = 0;     //input3 부호 체크
int when_put_minus = 0;
int begin_val = 0, begin_num = 0, begin_chosen = 0;
int quo_max = 0, quo_s_max = 0, div_ok = 0, quo_s = 0, quo_swap = 0, quo_swap_val = 0, div_sosu = 0, remain_zero = 0, remain_s = 0;
int again = 0, num = 0, var_cal_switch = 0;

void input();   // 입력받는 함수
void error();
void c_hoice();  // 변수인지 명령인지 구별하는 함수
void var_cal();	 //수식에서 변수 사용 지원한는 함수
void separate(); 			// 정수부 소수부 분리

void check_sign_in1();   //input 부호체크
void check_sign_in3();   //input3 부호체크
void re_array_in1();     //(-)부호 제외하고 다항연산 고려해서 input1 재배열
void re_array_in3();     //(-)부호 제외하고 다항연산 고려해서 input3 재배열

void invert1();   			// 계산 전 배열 뒤집기
void invert1_mul_s();
void invert2();				// 계산 후 배열 뒤집기
void invert2_mul_s();
void compare();				// 앞뒤수 비교
void convert1();			// char > int 변환
void convert2();			// int > char 변환
void plus();                // 더하기 함수
void minus();               // 빼기 함수
void multiply();            // 곱하기 함수
void dividing();
void dividing2();
void quo_arrange();
void quo_arrange2();
void remain2();
void initialization();    // 계산을 여러번 반복하기 위해 배열, 변수를 초기화 하는 함수
void comma(char n[]);     // 3자리마다 콤마 출력하는 함수 
void VAR();
void var_in();            // 변수선언 할때 사용하는 함수
void save();              // 변수값을 파일로 저장하는 함수
void load();              // 파일로부터 변수값을 읽어오는 함수
void which_sign();


int main() {

	printf("Start....");
start:

	printf("\n(input) ");			//계산기 프로그램 시작

	input();

	error();

	if(again == 1)
	{
	initialization();
		goto start;
	}

	c_hoice();

	if (chosen != 1){    //in1에 입력받은 문자가 1자리 대소문자가 아닌 경우

		var_cal();
		if (var_cal_switch == 1)
		{
			printf("        = error\n");
			initialization();
			goto start;
		}

		check_sign_in1();   // input1 +/- 부호 체크
		check_sign_in3();   // input3 +/- 부호 체크
		re_array_in1();     // 다항 연산 고려  순서 바꿔 저장
		re_array_in3();     // 다항 연산 고려  순사 바꿔 저장
		separate();

		which_sign();


		switch (in2[0]) 				{		

			case '+' : { invert1(); convert1(); plus(); convert2(); invert2(); break; }
			case '-' : { invert1(); compare(); convert1(); minus(); convert2(); invert2(); break; }
			case '*' : { invert1(); invert1_mul_s();  multiply(); invert2(); invert2_mul_s(); break;  }
			case '/' : { dividing(); break; }
			case '%' : { remain2(); break; }

			default: ;
		}	

		printf("        = ");

		if(when_put_minus == 1)
			printf("-");	


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

void input()
{
	for (int i = 0; i < 100; i++)
	{
		begin_val = getchar();   // 문자 한 개씩 받아서 bigin_var넣기
		if (begin_val != 10)     // 받은 문자가 엔터가 아닌 경우
			begin[i] = begin_val;
		else                     // 받은 문자가 엔터인 경우
		{
			begin[i] = begin_val;
			break;
		}
	}
	for (int i = 0; i <= 60; i++)
	{
		if (begin[i] == 10)         // 받은 문자가 엔터인 경우
			return ;
		else {
			if (begin[i] != 32)     // 받은 문자가 공백이 아닌 경우
				in1[i] = begin[i];
			else                    // 받은 문자가 엔터인 경우
			{
				begin_num = i + 1;
				break;
			}
		}}
	for (int i = 0; i <= 60; i++, begin_num++)
	{
		if (begin[begin_num] == 10)   // 받은 문자가 엔터인 경우
			return ;
		else                          // 받은 문자가 엔터가 아닌 경우
		{
			if (begin[begin_num] != 32)  // 받은 문자가 공백이 아닌 경우
				in2[i] = begin[begin_num];
			else                          // 공백인 경우
			{
				begin_num++;
				break;
			}
		}
	}

	for (int i = 0; i <= 60; i++, begin_num++)
	{
		if (begin[begin_num] != 10)          // 받은 문자가 엔터인 경우
			in3[i] = begin[begin_num];
		else                                  // 엔터 아님
			break;
	}
}

void c_hoice(){

	str_in1 = strlen(in1);      // in1, in2, in3 길이 재기
	str_in2 = strlen(in2);
	str_in3 = strlen(in3);

	var_in(); if (chosen == 1) return ;         //var_in 함수 에서 나왔던 chosen이 1이면(= 변수 1개가 정의됬으면) choice함수 종료

	else            // var_in함수에서 변수가 정의 되지 않았으면
	{
		if (str_in1 == 1)    //in1에 입력받은 문자가 1 자리인 경우
		{	if (str_in2 == 0)  // 그뒤로 아무것도 입력받지 않은경우
			{
				if (in1[0] >= 'A' && in1[0] <= 'Z')  //in1에 대문자가 들어온 경우
				{
					for (int i = 0; i <= 9; i ++)
					{
						if (in1[0] == var[i])    //in1에 입력된 문자가 var에 선언된 변수 이름과 같은경우
						{
							begin_chosen = i;
							printf("        = ");
							for(int i = 0 ; i <= 49; i++){
								if(var_var[begin_chosen][i] == '.')
								{temp_var_d = i +  1; break;}
								else var_var_j[begin_chosen][i] = var_var[begin_chosen][i];}
							if(var_var[begin_chosen][50] == '.')
								temp_var_d = 51;
							if(temp_var_d != 0){
								for(int i = 0; i <= 8; temp_var_d++, i++)
									var_var_s[begin_chosen][i] = var_var[begin_chosen][temp_var_d];
							}

							p = strlen(var_var_s[begin_chosen]);
							comma(var_var_j[begin_chosen]);
							if (p != 0){
								printf(".");
							comma(var_var_s[begin_chosen]);}
							printf("\n");
							chosen = 1;
							return;

						}
						else     // in1이 var에 선언된 변수가 아닌 경우
							begin_chosen = 100;
					}
				}

				else if (in1[0] >= 'a' && in1[0] <= 'z')   // 소문자인 경우
				{
					in1[0] -= 32;  // 대문자로 바꾸기
					for (int i = 0; i <= 9; i ++)
					{
						if (in1[0] == var[i])
						{
							begin_chosen = i;
							printf("        = "); 
							for(int i = 0 ; i <= 49; i++){
								if(var_var[begin_chosen][i] == '.')
								{temp_var_d = i +  1; break;}
								else var_var_j[begin_chosen][i] = var_var[begin_chosen][i];}
							if(var_var[begin_chosen][50] == '.')
								temp_var_d = 51;
							if(temp_var_d != 0){
								for(int i = 0; i <= 8; temp_var_d++, i++)
									var_var_s[begin_chosen][i] = var_var[begin_chosen][temp_var_d];
							}

							p = strlen(var_var_s[begin_chosen]);
							comma(var_var_j[begin_chosen]);
							if (p != 0){
								printf(".");
							comma(var_var_s[begin_chosen]);}
							printf("\n");
							chosen = 1;
							return;

						}
						else
							begin_chosen = 100;
					}
				}
			}}

		else 
		{
			choice = strcmp (in1, c_lear);
			if (choice == 0) {system("clear"); chosen = 1; return ;}
			else { choice = strcmp (in1, e_nd); 
				if (choice == 0) exit(1);
				else { choice = strcmp (in1, V_AR);
					if (choice == 0) {VAR(); chosen = 1; return ;}
					else { choice = strcmp (in1, s_ave);
						if (choice == 0) {save(); chosen = 1; return;}
						else { choice = strcmp (in1, l_oad);
							if (choice == 0) {load(); chosen = 1; return;}
						}}}}
		}
		if (begin_chosen == 100)
		{printf("        = undefined."); chosen = 1; return;}
	}

} // choice 함수

void var_cal(){ /* 수식에서 변수를 연산자로 사용 할 때  쓰는 함수 */

	if (str_in1 == 2)  // 두자리수 받은  경우
		if (in1[0] == '-')  // 음수인 경우
		{
			if (in1[1] >= 'A' && in1[1] <= 'Z')  // 변수 이름인 경우
			{
				for (int i = 0; i <= 9; i ++)
				{
					if (in1[1] == var[i])
					{
						var_cal_switch = 0;
						begin_chosen = i;
						for (int u = 0, ui = 1; u <= 60; u++, ui++)
							in1[ui] = var_var[begin_chosen][u];
						break;	
					}
					else
					{
						var_cal_switch = 1;
							return;
					}
				}
			}


			else if (in1[1] >= 'a' && in1[1] <= 'z')   //변수 이름인 경우
			{
				in1[1] -= 32;
				for (int i = 0; i <= 9; i ++)
				{
					if (in1[1] == var[i])
					{
						var_cal_switch = 0;
						begin_chosen = i;
						for (int u = 0, ui = 1; u <= 60; u++, ui++)
							in1[ui] = var_var[begin_chosen][u];
						break;	
					}
					else
					{
						var_cal_switch = 1;
						return;
					}
				}
			}
		}

	if (str_in3 == 2)   // in3에 두자리 받은 경우
		if (in3[0] == '-')  // 음수인 경우
		{
			if (in3[1] >= 'A' && in3[1] <= 'Z')  //변수 이름인 경우
			{
				for (int i = 0; i <= 9; i ++)
				{
					if (in3[1] == var[i])
					{
						var_cal_switch = 0;
						begin_chosen = i;
						for (int u = 0, ui = 1; u <= 60; u++, ui++)
							in3[ui] = var_var[begin_chosen][u];
						break;	
					}
					else
					{
						var_cal_switch = 1;
						return;
					}
				}
			}


			else if (in3[1] >= 'a' && in3[1] <= 'z')  //변수이름 (소문자)인 경우
			{
				in3[1] -= 32;  // 대문자로 바꾸기
				for (int i = 0; i <= 9; i ++)
				{
					if (in3[1] == var[i])
					{
						var_cal_switch = 0;
						begin_chosen = i;
						for (int u = 0, ui = 1; u <= 60; u++, ui++)
							in3[ui] = var_var[begin_chosen][u];
						break;	
					}
					else
					{
						var_cal_switch = 1;
						return;
					}
				}
			}
		}

	if (str_in1 == 1)
	{
		if (in1[0] >= 'A' && in1[0] <= 'Z')
		{
			for (int i = 0; i <= 9; i ++)
			{
				if (in1[0] == var[i])
				{
						var_cal_switch = 0;
					begin_chosen = i;
					for (int u = 0; u <= 60; u++)
						in1[u] = var_var[begin_chosen][u];
					break;	
				}
					else
					{
						var_cal_switch = 1;
						return;
					}
			}
		}

		else if (in1[0] >= 'a' && in1[0] <= 'z')
		{
			in1[0] -= 32;
			for (int i = 0; i <= 9; i ++)
			{
				if (in1[0] == var[i])
				{
						var_cal_switch = 0;
					begin_chosen = i;
					for (int u = 0; u <= 60; u++)
						in1[u] = var_var[begin_chosen][u];
					break;	
				}
					else
					{
						var_cal_switch = 1;
						return;
					}
			}
		}
	}

	if (str_in3 == 1)
	{
		if (in3[0] >= 'A' && in3[0] <= 'Z')
		{
			for (int i = 0; i <= 9; i ++)
			{
				if (in3[0] == var[i])
				{
						var_cal_switch = 0;
					begin_chosen = i;
					for (int u = 0; u <= 60; u++)
						in3[u] = var_var[begin_chosen][u];
					break;	
				}
					else
					{
						var_cal_switch = 1;
						return;
					}
			}
		}

		else if (in3[0] >= 'a' && in3[0] <= 'z')
		{
			in3[0] -= 32;
			for (int i = 0; i <= 9; i ++)
			{
				if (in3[0] == var[i])
				{
						var_cal_switch = 0;
					begin_chosen = i;
					for (int u = 0; u <= 60; u++)
						in3[u] = var_var[begin_chosen][u];
					break;	
				}
					else
					{
						var_cal_switch = 1;
						return;
					}
			}
		}
	}
}

void check_sign_in1(){ // 부호 체크하는 함수
	if(in1[0] == '-'){  // 음수면
		for(int i = 0 ; i < N; i++){
			temp_in1[i] = in1[i+1];}  // - 부호 제외하고 임시 저장 배열에 넣기
		if_minus_first += 1;          // input1이  음수
		minus_sign_count += 1;}       // 결과에 (-) 붙일지 말지 판별

	else  // 양수
		for(int i = 0; i < N ; i++)
			temp_in1[i] = in1[i];
}	

void check_sign_in3(){ // 부호 체크하는 함수
	if(in3[0] == '-'){  // 음수
		for(int i = 0 ; i < N; i++){  
			temp_in3[i] = in3[i+1];}  // - 부호 제외하고 임시 저장 배열에 넣기
		if_minus_last += 1;        // 두번째 연산자가 음수
		minus_sign_count += 1;}    // 결과에 (-)를 붙일지 말지 판별

	else   // 양수면
		for(int i = 0; i < N ; i++)
			temp_in3[i] = in3[i];  // 그대로 임시 저장 배열에 넣기
}	

void re_array_in1(){            // 원래의 배열(in1)에 부호를 빼서 넣어주는 함수
	if(in2[0] == '/' || in2[0] == '%'){
		if((if_minus_first + if_minus_last)== 0)   // 두 연산자 모두 양수 일때
			for(int i = 0; i < N; i++)
				in1[i] = temp_in1[i];
		else if((if_minus_first + if_minus_last) == 1){
			if(if_minus_first == 1){   // 첫번째가 음수
				for(int i = 0; i < N; i++)
					in1[i] = temp_in1[i];}
			if(if_minus_last == 1){	  // 두번째수가 음수
				for(int i = 0; i < N; i++)
					in1[i] = temp_in1[i];}}
		else                  // 둘다  음수
			for(int i = 0; i < N; i++)
				in1[i] = temp_in1[i];}


	else{   // + , - , % 연산인 경우
		if((if_minus_first + if_minus_last)== 0) // 둘다  양수
			for(int i = 0; i < N; i++)
				in1[i] = temp_in1[i];

		else if((if_minus_first + if_minus_last) == 1){
			if(if_minus_first == 1){  // 첫번째가 음수
				for(int i = 0; i < N; i++)
					in3[i] = temp_in1[i];}
			if(if_minus_last == 1){	  // 두번째가 음수
				for(int i = 0; i < N; i++)
					in1[i] = temp_in1[i];}}
		else  // 둘다 음수
			for(int i = 0; i < N; i++)
				in3[i] = temp_in1[i];}

}

void re_array_in3(){ // 원래의 배열(in3)에 부호를 빼서 넣어주는 함수
	if(in2[0] == '/' || in2[0] == '%'){
		if((if_minus_first + if_minus_last) == 0) 
			for(int i = 0; i < N; i++)
				in3[i] = temp_in3[i];
		else if((if_minus_first + if_minus_last) == 1){
			if(if_minus_last == 1){
				for(int i = 0; i< N ; i++)
					in3[i] = temp_in3[i];}
			if(if_minus_first == 1){
				for(int i = 0; i < N ; i++)
					in3[i] = temp_in3[i];}}
		else
			for(int i = 0; i < N; i++)
				in3[i] = temp_in3[i];}

	else{
		if((if_minus_first + if_minus_last) == 0) 
			for(int i = 0; i < N; i++)
				in3[i] = temp_in3[i];
		else if((if_minus_first + if_minus_last) == 1){
			if(if_minus_last == 1){
				for(int i = 0; i< N ; i++)
					in3[i] = temp_in3[i];}
			if(if_minus_first == 1){
				for(int i = 0; i < N ; i++)
					in1[i] = temp_in3[i];}}
		else
			for(int i = 0; i < N; i++)
				in1[i] = temp_in3[i];}

}


void separate(){		// 정수부 소수부 분리하는 함수

	for (int i = 0; i <= 49; i++) {
		if (in1[i] == '.')
		{temp1_d = i+1; break;}  // in1의 정수부분 in1_j 배열에 저장
		else in1_j[i] = in1[i];		  } 
	if (in1[50] == '.')
		temp1_d = 51;

	if (temp1_d != 0){
		for (int i = 0; i <= 8; temp1_d++, i++)
			in1_s[i] = in1[temp1_d];  // 처음 숫자 소수부분 in1_s 배열에 저장
	}

	for (int i = 0; i <= 49; i++) {  // 두번째 입력받은수 똑같이 반복
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

void invert1_mul_s(){     //계산 전 소수부 배열 뒤집는 함수
	last = strlen(in1_s) - 1;
	while(1) {
		if(first > last) break;
		temp = in1_s[last];
		in1_s[last] = in1_s[first];
		in1_s[first] = temp;
		first++; last--;
	}
	first = 0; last = 0;

	last = strlen(in3_s) - 1;
	while(1) {
		if(first > last) break;
		temp = in3_s[last];
		in3_s[last] = in3_s[first];
		in3_s[first] = temp;
		first++; last--;
	}
	first = 0; last = 0;
}


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

void invert2_mul_s(){			// 계산 후 정수부 배열을 뒤집는 함수

	last = strlen(res_s) - 1;
	while(1) {
		if(first > last) break;
		temp = res_s[last];
		res_s[last] = res_s[first];
		res_s[first] = temp;
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

void plus(){

	for (int i = 8; i >= 0; i--)			{	// 소수 더하기
		res_s[i] = in1_s[i] + in3_s[i] + k;
		if (res_s[i] >= 10) 	{  // 더해서 10 넘어가면
			k = 1; res_s[i] -= 10;}					// 1올림수 k 에 저장 / 10을 뺀 나머지 저장 /예를 들어 더해서 17이면  앞배열에 1 더하고 현재배열에 7 저장 /  오류 생길 수 있다.
		else k = 0;								} 	// 더해서 10미만이면 올릴 수 없음

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
			if (res_s[0] < 0)								// 소수자리 연산 후 소수 첫째 자리가 음수면 10 더하기
			{res_s[0] += 10; k = 1;}						// 1만큼 정수 자리에서 뺴기 위함
			else k = 0;										// 소수 첫째 자리가 음수가 아니면 정수에서 1 안 뻄

			for (int i = 0; i <= 49; i++)			{		// 정수 빼기
				res_j[i] = in1_j[i] - in3_j[i] - k;			// 정수끼리 빼기( k : 정수에서 빌려온 값이 있으면 1, 없으면 0)
				if (res_j[i] < 0)	{
					k = 1; res_j[i] += 10;}					// 빼서 음수면 10 더한 값 저장
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

void multiply(){

	x = strlen(in1_s) + strlen(in1_j); // x = (in1_s 의 소수길이) + (in1_j 의 정수길이)
	y = strlen(in3_s) + strlen(in3_j); // y = (in3_s 의 소수길이) + (in3_j 의 정수길이)

	for(int i = 0 ; i < strlen(in1_s) ; i++) // in1_s 소수부 받고 in1_j 정수부 받기(문자를 숫자로 변환하여 저장)
		mul_1[i] = in1_s[i]-'0';	
	for(int i = strlen(in1_s), t = 0 ; i < strlen(in1_s) + strlen(in1_j) ;){ // 지역변수 t 설정(정수부 넣기 위해서)
		mul_1[i] = in1_j[t]-'0';			
		t++,i++;}

	for(int i = 0 ; i < strlen(in3_s) ; i++) // in3_s 소수부 받고 in1_j 정수부 받기(문자를 숫자로 변환하여 저장)
		mul_3[i] = in3_s[i]-'0';	
	for(int i = strlen(in3_s), t = 0 ; i < strlen(in3_s) + strlen(in3_j) ;){ // 지역변수 t 설정(정수부 넣기 위해서)
		mul_3[i] = in3_j[t]-'0';
		t++,i++;}


	if(strlen(in3) >= strlen(in1)){  // 곱셈결과를 mul배열에 차곡차곡 쌓는 과정(in3의 길이가 더 긴 경우)
		for(int i = 0; i < x; i++){ 
			for(int n = 0; n < y; n++) // mul 배열에 mul_1 과 mul_3 의 곱셈한 값을 저장	
			{mul[m] += (mul_1[i] * mul_3[n]);	
				m++;}

			m -= y-1;}}
	else{							// 곱셈결과를 mul배열에 차곡차곡 쌓는 과정(in1의 길이가 더 긴 경우)
		for(int i = 0; i < y ; i++){
			for(int n = 0; n < x ; n++) // mul 배열에 mul_1 과 mul_3 의 곱셈한 값을 저장
			{mul[m] += (mul_3[i] * mul_1[n]);
				m++;}

			m -= x-1;}}

	point = ((temp1_d + temp3_d)!= 0) ? 1 : 0; //소수점이 있으면 point = 1 , 없으면 point = 0

	if(point){							 // 입력 받은 두 수 중에 하나라도 소수점이 있는 경우
		for(int i = 0 ; i < x+y; i++){   // 곱셈의 값이 쌓여있는 mul 배열을 올림수를 고려하여 다시 정리하는 과정
			if(mul[i] >= 10){
				mul[i+1] += (mul[i]) / 10;
				mul[i] = (mul[i]) % 10;
			}
			else{
				mul[i] = (mul[i]) % 10;}}}

	else{								// 입력 받은 두 수에 소수점이 없는 경우	
		for(int i = 0; i<x+y-1; i++){   // 곱셈의 값이 쌓여있는 mul 배열을 올림수를 고려하여 다시 정리하는 과정
			if(mul[i] >= 10){
				mul[i+1] += (mul[i]) / 10;
				mul[i] = (mul[i]) % 10;}
			else
				mul[i] = (mul[i]) % 10;}}

	carry = (mul[x+y-1] != 0 ? 1 : 0);	 // mul배열에 가장 마지막에 올림수가 있으면 carry = 1


	if(point){		
		p=1;
		if(carry){						// 소수점이 있으면서 마지막에 올림수가 있는 경우 last_mul 배열에 점을 넣어 숫자를 문자로 변환하여 저장한다.
			for(int i = 0, c = 0; i < x+y+1 ; i++,c++){ // 소수점이 있기 때문에 +1 을 넣어 길이를 조정한다.
				if(i == strlen(in1_s) + strlen(in3_s) ){
					last_mul[i] = '.'; 
					c--;}

				else{
					last_mul[i] = mul[c] + '0';	}}}

		else{							// 소수점은 있지만 마지막에 올림수가 없는 경우 last_mul 배열에 점을 넣어 숫자를 문자로 변환하여 저장한다.
			for(int i = 0 , c = 0; i<x+y; i++, c++){ //, 소수점이 없기 때문에 길이를 조정하지 않는다.
				if(i == strlen(in1_s) + strlen(in3_s) ){
					last_mul[i] = '.';
					c--;}

				else{
					last_mul[i] = mul[c] + '0';	}}}}

	else{
		p=0;
		if(carry){						// 소수점이 없지만 마지막에 올림수가 있는 경우 last_mul 배열에 소수점 없이 숫자를 문자로 변환하여 그대로 넣어준다.
			for(int i = 0, c = 0; i< x+y; i++,c++)
				last_mul[i] = mul[c] + '0';}

		else							// 소수점도 없고 마지막에 올림수도 없는 경우 last_mul 배열에 소수점 없이 숫자를 문자로 변환하여 그대로 넣어준다.
			for(int i = 0, c = 0; i<x+y-1; i++,c++)
				last_mul[i] = mul[c] + '0';}



	if(point){							// 소수점이 있는 경우 res_s 와 res_j 배열에 소수부와 정수부를 나눠서 넣어주는 과정
		for(int i=0, c=0 ; i < strlen(last_mul); i++){
			if( i < strlen(in1_s) + strlen(in3_s)){
				res_s[i] = last_mul[c];
				c++;}

			else{
				if( c < strlen(last_mul)-1){ // 소수점이 있기 때문에 -1 을 넣어 길이를 조정한다.
					res_j[i-(strlen(in1_s)+strlen(in3_s))] = last_mul[c+1];
					c++;}

				else
					break;}}}
	else{								// 소수점이 없는 경우 res_S 와 res_j 배열에 소수부와 정수부를 나눠서 넣어주는 과정
		for(int i=0, c=0; i < strlen(last_mul); i++){
			if( i < strlen(in1_s) + strlen(in3_s)){
				res_s[i] = last_mul[c];
				c++;}

			else{
				if( c < strlen(last_mul)){ // 소수점이 없기 때문에 길이를 조정하지 않는다.
					res_j[i-(strlen(in1_s)+strlen(in3_s))] = last_mul[c];
					c++;}

				else
					break;}}}

} // multiply 함수


void initialization(){

	for (int i = 0; i <= 999; i++)
		begin[i] = 0;

	for (int i = 0; i <= 59; i++)
	{
		in1[i] = 0;
		in2[i] = 0;
		in3[i] = 0;
		res[i] = 0;
		mul[i] = 0;
		temp_in1[i] = 0;
		temp_in3[i] = 0;
		quo[i] = 0;
		div_1[i] = 0;
		div_3[i] = 0;
	}
	for (int i = 0; i <= 49; i++)
	{
		in1_j[i] = 0;
		in3_j[i] = 0;
		res_j[i] = 0;
		div_j[i] = 0;
		last_mul[i] = 0;
		mul_1[i] = 0;
		mul_3[i] = 0;
	}
	for (int i = 0; i <= 8; i++)
	{
		in1_s[i] = 0;
		in3_s[i] = 0;
		res_s[i] = 0;
	}

	str_in1 = 0, str_in2 = 0, str_in3 = 0, str_res_s = 0, str_in3_j, str_in1_j;
	temp = 0, temp1_d = 0, temp3_d = 0, temp_j = 0, temp_s = 0;
	first = 0, last = 0, again = 0, var_cal_switch = 0;
	k = 0, p = 0, q = 0, daeso = 0, choice = 0, chosen = 0;
	m = 0, x = 0, y = 0;
	if_minus_last = 0, if_minus_first = 0, minus_sign_count = 0;
	when_put_minus = 0;
	begin_val = 0, begin_num = 0, begin_chosen = 0;
	quo_max = 0, quo_s_max = 0, div_ok = 0, quo_s = 0, quo_swap = 0, quo_swap_val = 0, div_sosu = 0, remain_zero = 0, remain_s = 0;

} // 초기화 함수

void comma(char n[]){

	int t, i;
	i = (strlen(n) - 1) % 3;     // i는 배열 인덱스 값(-> 길이에 -1을 해주는 이유)

	for (t = 0; t <= strlen(n)-1; t++){
		printf("%c", n[t]);
		if (t == strlen(n) - 1) break;		// 배열의 끝에서는 ,를 찍지 않음
		if (t % 3 == i) printf(",");     }	// 3자리마다 , 찍기

} // comma 함수

void VAR(){

	for (int i = 0; var[i] != 0; i++){		// NULL문자가 들어가기 전까지 반복문
		for (int u = 0; u <= N; u++)
			in1[u] = var_var[i][u];
		separate();
		p = strlen(in1_s);
		printf("        %c = ", var[i]);
		comma(in1_j);
		if (p != 0)
		{printf(".");
			comma(in1_s);}
		printf("\n");}	
	
	if (var[0] == 0){					// var[0]에 아무것도 들어가있지 않으면 아래의 메시지 출력
		printf("     정의된 변수 없음");
	}
	return;
}

// VAR 함수

void var_in(){

	if (str_in1 == 1) 						{				// in1에 입력받은 수가 한자리라면
		if (in1[0] >= 'A' && in1[0] <= 'Z')		{ 			// in1에 대문자 들어갈 때
			if (in2[0] == '=')  {
				var[var_num] = in1[0];						// 변수 저장 배열에 변수 이름 넣기
				for (int i = 0; i <= 60; i++)
					var_var[var_num][i] = in3[i];			// 변수에 입력값 저장
				for (int u = 0; u <= N; u++)
					in1[u] = var_var[var_num][u];			// in1 배열에 저장받은 변수 값 넣기 (저장한 값을 출력하기 위함)
				separate();
				p = strlen(in1_s);
				printf("        = ");
				comma(in1_j);
				if (p != 0)									// in1 소수 자리수가 있으면
				{printf(".");								// '.' 찍기
					comma(in1_s);}

				var_num++; chosen = 1;
				return ;			}					}

		else if (in1[0] >= 'a' && in1[0] <= 'z')  {			// in1에 소문자 들어갈 때
			if (in2[0] == '=')   {
				var[var_num] = in1[0] - 32;					// 대소문자 구별 안 함. 변수 저장 배열에 변수 이름 넣기
				for (int i = 0; i <= 60; i++)
					var_var[var_num][i] = in3[i];			// 변수에 입력값 저장
				for (int u = 0; u <= N; u++)
					in1[u] = var_var[var_num][u];			// in1 배열에 저장했던 변수값 넣기 (저장한 값 출력하기 위함)
				separate();
				p = strlen(in1_s);
				printf("        = ");
				comma(in1_j);								// 세자리마다 , 실행
				if (p != 0)									// in1에 소수 자리수가 있으면
				{printf(".");								// '.' 찍기
					comma(in1_s);}

				var_num++; chosen = 1;						// main 함수 start 부분부터 다시 시작
				return ;			}					  }}

} // var_in 함수

void save()
{

	FILE *out1;
	FILE *out2;
	FILE *out3;

	out3 = fopen("save_var_num", "w+");			// save_var_num 파일을 열어 쓰겠다. 그 과정을 out3라 하겠다.
	fprintf(out3, "%d", var_num); 				// out3를 실행해 var_num 숫자를 출력하게 하겠다. > var_num은 저장된 변수의 수를 의미한다.
	fclose(out3);

	out1 = fopen("save_var", "w+");				// save_var 파일을 열어 쓰겠다. 이 과정을 ou1이라고 하겠다.

	for (int i = 0; i <= 9; i++)
	{
		if (var[i] != 0)
		{
			fprintf(out1, "%c", var[i]);		//이 때 fprint되는 값은 변수의 이름이다. ex) A, B, C
	//		check[var[i]-65] = 1;
		}
		else break;
	}

	fclose(out1);
	out2 = fopen("save_var_var", "w+");

	for (int i = 0; i <= 9; i++)
	{
		if (strlen(var_var[i]) != 0)
		{
			fprintf(out2, "%s\n", var_var[i]);	 //이 때 fprint 되는 값은 변수의 해당 수 문자열이다.
		}
		else break;
	}

	fclose(out2);

}

void load()
{
	int cnt = 0, u;
	u = var_num;

	FILE *in1;
	FILE *in2;
	FILE *in3;

	in3 = fopen("save_var_num", "r");			// save_var_num 파일에서 저장된 var_num값을 읽어 cnt 변수에 저장한다.
	fscanf(in3, "%d", &cnt);
	fclose(in3);


	in1 = fopen("save_var", "r");
	for (int i = 0; i <= (cnt - 1); u++, i++)
	{
		if (u == 10) { fclose(in1); return ; }
		else
		{
			fscanf(in1, "%c", &var[u]);			// cnt 수만큼 var_num에서 변수를 읽어 var배열에 저장한다.
		}
	}

	u = var_num;
	fclose(in1);
	in2 = fopen("save_var_var", "r");

	for (int i = 0; i <= (cnt - 1); u++, i++)
	{
		if (u == 10) { fclose(in2); return ; }
		else
		{
			fscanf(in2, "%s", var_var[u]);		// cnt 수만큼 변수에 해당하는 문자열을 var_var배열에 저장한다.
		}
	}
	var_num = u;
	fclose(in2);

	//num = 1;  //처음에 0
}


void dividing()
{

	str_in1_j = strlen(in1_j);
	str_in3_j = strlen(in3_j);
	quo_max = str_in1_j - str_in3_j + 1; // 몫의 정수 자리수 예를 들어 이게 3이면 몫의 앞자리 3개가 정수이고 그밑으로 9자리까지 몫 받고 함수 종료된다. 
	if (quo_max < 0)
	{
		quo_swap = -quo_max;			// 몫의 정수 값이 0일때 의 경우를 저장해준다.
		quo_max = 0;
	}
	quo_s_max = quo_max + 9;			// 몫의 소수부 자릿수를 9자리까지 제한한다.

	for(int i = 0 ; i < strlen(in1_j) ; i++) {// in1_s 소수부 받고 in1_j 정수부 받기
		div_1[i] = in1_j[i]-'0'; 	}
	for(int i = strlen(in1_j), t = 0 ; i < strlen(in1_s) + strlen(in1_j) ;){ // 변수 t 설정(정수부 넣기 위해서)
		div_1[i] = in1_s[t]-'0';
		t++,i++; 
	}

	for(int i = 0 ; i < strlen(in3_j) ; i++) // in3_s 소수부 받고 in1_j 정수부 받기
	{div_3[i] = in3_j[i]-'0'; }
	for(int i = strlen(in3_j), t = 0 ; i < strlen(in3_s) + strlen(in3_j) ; ){
		div_3[i] = in3_s[t]-'0';
		t++,i++; }
	
	for ( int quo_i = 0; quo_i < quo_s_max; quo_i++)		// 몫이 소수9째짜리수가 될때까지 나누어지는 for문
	{
can_you_divide: 				  // goto can_you_divide 나누기를 한번 진행한뒤 다시 나누어 질 수 있는지 판단하러 가는 것이다.

		if (div_1[0] > div_3[0]) // dividend의 첫째 짜리수가 divisor의 첫쨰 자리 수보다 크다. >> 무조건 나눌수 있는 경우 
		{
		i_can_divide:			// goto i_can_divide를 만나면 한번 더 나누어 질 수 있다는 것이다.

			for ( int i = 0; i <= 58; i++)
				div_1[i] = div_1[i] - div_3[i];
			{quo[quo_i]++; }
			for ( int i = 1; i <= 58; i++)
			{
				if ( div_1[i] < 0 )
				{
					div_1[i] += 10;
					div_1[i-1] -= 1;
				}
			}
		goto can_you_divide;
		}
		else
		{
			for (int i = 0; i <= 58; i++)
			{
				if (div_1[i] < div_3[i])
				{
					dividing2();			// div_1 배열의 맨앞자리부터 비교해서 dividend의 값이 divisor보다 작은경우 dividng2함수 실행
					break;
				}
				else
				{
					if (div_1[i] > div_3[i])
						goto i_can_divide;
				}
			}
			if (div_ok == 1)
			{
				div_ok = 0;
			}
			else				//  더이상 나눌 수 없는 상태로 dividing함수를 종료한다.
			{
				quo[quo_i]++;
				break;
			}
		}
	}
	quo_arrange();			// 몫의 값이 들어있는 quo배열을 정리하고 결과 배열에 넣어주는 함수
}
			


void dividing2()			// dividend 배열의 [0]값이 divisor배열의 [0]값보다 작아 dividend 배열의 첫째값과 둘째값을 합쳐주고 dividend배열의 모든 배열을 한칸씩 앞으로 당긴다.
{
	div_1[1] += div_1[0] * 10;
	for (int swap = 0; swap <= 58; swap++)
		div_1[swap] = div_1[swap+1];
	div_ok = 1;
}

void quo_arrange()   // 몫 배열의 값들을 자릿수에 맞게 정리해주고 결과 배열에 넣어준다.
{
	for (int quo_i = 0; quo_i < quo_max; quo_i++)
	{
		if ( quo[quo_i] != 0)
		{
			quo_s = quo_i;
			break;
		}
		else
			quo_s = quo_max;
	}
	res_j[0] = '0';

	if (quo_s != quo_max)
	{
		for (int i = 0; quo_s < quo_max; quo_s++, i++)
			res_j[i] = quo[quo_s] + '0';
	}

	if (quo_swap != 0)
	{
		for ( int i = 0; i < quo_swap; i++)
			res_s[i] = 0;
	
		quo_swap_val = quo_swap;
	}

	for (; quo_max <= quo_s_max-1; quo_swap_val++, quo_max++)
	{
		res_s[quo_swap_val] = quo[quo_max];
	}

	res_s[9] = 0;


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

	for (int i = 0; i <= 10; i++)
		printf("%d", res_s[i]);
	p = strlen(res_s);
	
}

void remain2()					// 나머지 함수
{

	str_in1_j = strlen(in1_j);
	str_in3_j = strlen(in3_j);
	quo_max = str_in1_j - str_in3_j + 1; // 몫의 정수 자리수 예를 들어 이게 3이면 몫의 앞자리 3개가 정수이고 그밑으로 9자리까지 몫 받고 함수 종료된다. 
	if (quo_max < 0)
	{
		quo_swap = -quo_max;
		quo_max = 0;
	}
	quo_s_max = quo_max + 9;

	for(int i = 0 ; i < strlen(in1_j) ; i++) {// in1_s 소수부 받고 in1_j 정수부 받기
		div_1[i] = in1_j[i]-'0';} 
	for(int i = strlen(in1_j), t = 0 ; i < strlen(in1_s) + strlen(in1_j) ;){ // 변수 t 설정(정수부 넣기 위해서)
		div_1[i] = in1_s[t]-'0';
		t++,i++; 
	}

	for(int i = 0 ; i < strlen(in3_j) ; i++) // in3_s 소수부 받고 in1_j 정수부 받기
	{div_3[i] = in3_j[i]-'0';} 
	for(int i = strlen(in3_j), t = 0 ; i < strlen(in3_s) + strlen(in3_j) ; ){
		div_3[i] = in3_s[t]-'0';
		t++,i++; }
	
	for(int i = 0; i <= 58 ; i++){           // dividend와 divisor가 같아서 나머지가 무조건 0인 경우로 리소스의 낭비를 방지하기 위해 처음에 따로 수행한다.
		remain_zero = 1;
		if(div_1[i] != div_3[i])
		{remain_zero = 0; break;}}
	if ( remain_zero == 1)
	{res_j[0] = '0';
	return ;
	}

	if ( str_in1_j < str_in3_j)				// dividend가 divisor보다 작은 경우로 나머지가 무조건 dividend의 값을 갖는다.
	{
	for (int i = 0; i <= str_in1_j; i++)
	res_j[i] = in1_j[i];
	
	for (int i = 0; i <= strlen(in1_s); i++)
	res_s[i] = in1_s[i];
	return ;
	}
	for ( int quo_i = 0; quo_i < quo_max; quo_i++)	// 나누기를 몫이 정수일때 까지만 진행한다.
	{
can_you_divide:

		if (div_1[0] > div_3[0]) // dividend의 첫째 짜리수가 divisor의 첫쨰 자리 수보다 크다. >> 무조건 나눌수 있는 경우 
		{
		i_can_divide:

			for ( int i = 0; i <= 58; i++)
				div_1[i] = div_1[i] - div_3[i];
			{quo[quo_i]++; }
			for ( int i = 58; i >= 1; i--)
			{
				if ( div_1[i] < 0 )
				{
					div_1[i] += 10;
					div_1[i-1] -= 1;
				}
			}
		goto can_you_divide;
		}
		else
		{
			if( quo_i+1 != quo_max) {
			for (int i = 0; i <= 58; i++)
			{
				if (div_1[i] < div_3[i])
				{
					dividing2();
					break;
				}
				else
				{
					if (div_1[i] > div_3[i])
						goto i_can_divide;
				}
			}
			if (div_ok == 1)
			{
				div_ok = 0;
			}
			else
			{
				for(int i = 0; i < 58 ; i++){
					div_1[i] = 0;}
				quo[quo_i]++;
				break;
			}
		}}
	}
	quo_arrange2();
}
			

void quo_arrange2()     // 나머지를 정리해주는 함수이다.
{

	for (int i = 0; i <= 59; i++)
	for (int i = 0; i <= 59; i++)
	{
		if ( div_1[i] != 0)
		{
			remain_s = i;
			break;
		}
		else
			remain_s = 0;
	}
	for (int i = remain_s, t = 0; i < str_in3_j; t++, i++){
		res_j[t] = div_1[i] + '0';
		}

	for (int i = str_in3_j; i <= quo_s_max-1; i++)
	{
		if (div_1[i] != 0)
			{div_sosu = 1; break;}
	}
if ( div_sosu != 0)
{
	for (int i = 0; i <= quo_s_max-1; i++, str_in3_j++)
	{
		res_s[i] = div_1[str_in3_j];
	}



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
}
	p = strlen(res_s);
	
}

void error(){
	for(int i = 0; i < strlen(begin);  i++){
		if((begin[i] >= '0' && begin[i] <= '9') || (begin[i] >= 'a' && begin[i] <= 'z') || (begin[i] >= 'A' && begin[i] <= 'Z') || (begin[i] == '+') || (begin[i] == '-') || (begin[i] == '*') || (begin[i] == '/') || (begin[i] == '%') || (begin[i] == '.') || (begin[i] == '=') ||(begin[i] == 32) || (begin[i] == 10)) {}

		else{													// begin에서 받을만한 것 외의 이상한 문자가 들어갔을 때 error 출력
			printf("     = error");
			again = 1;
			return;
		}

		if(strlen(in1) == 1){
			// 변수가 정의되어있는 변수가 아닌 경우
		}

		if(strcmp(in3,"END") == 0){
			printf("    = error"); again = 1; return;}
		if(strcmp(in3,"save") == 0){
			printf("    = error"); again = 1; return;}
		if( strcmp(in3,"load") == 0){
			printf("    = error"); again = 1; return;}
		if(strcmp(in3,"VAR") == 0){
			printf("    = error"); again = 1; return;}
		if(strcmp(in3,"clear") == 0){
			printf("    = error"); again = 1; return;}						// in1이 in2 in3로 계속 이어졌을 때 save, clear가 in1에 들어가있으면 error 뜨게 하는 것도 같은 원리

		/*		for( int i = 0 ; i <= 9 ; i++ ){
				if(strcmp(in1,var[i]) == 0){
				return;}
				else{
				printf("    = error"); again = 1; return;}

				}*/
	}}

void which_sign()
{

		if(in2[0] == '-'){						// - 단항, - 이항 수행
			if(minus_sign_count == 0)
				in2[0] = '-';
			else if(minus_sign_count == 1){
				if(if_minus_first == 1){
					in2[0] = '+';
					when_put_minus =1;}
				if(if_minus_last == 1)
					in2[0] = '+';}
			else{
				in2[0] = '-';}}


		else if(in2[0] == '+'){					// + 단항, + 이항 수행
			if(minus_sign_count == 0)
				in2[0] = '+';
			else if(minus_sign_count == 1){
				if(if_minus_first == 1)
					in2[0] = '-';
				if(if_minus_last == 1)
					in2[0] = '-';}
			else{ 
				in2[0] = '+';
				when_put_minus=1;}}


		else if(in2[0] == '*'){					// * 단항, * 이항 수행
			if(minus_sign_count == 0 || minus_sign_count == 2)
				in2[0] = '*';
			else if(minus_sign_count == 1){
				in2[0] = '*';	
				when_put_minus=1;}}

		else if(in2[0] == '/'){
			if(minus_sign_count == 0 || minus_sign_count == 2)
				in2[0] = '/';
			else if(minus_sign_count == 1){
				in2[0] = '/';	
				when_put_minus=1;}}

		else if(in2[0] == '%'){					// % 단항, % 이항 수행
			if(minus_sign_count == 0 || minus_sign_count == 2){
				if(if_minus_first == 1){
					in2[0] = '%';
					when_put_minus = 1;}

				else
					in2[0] = '%';}

			else if(minus_sign_count == 1){
				if(if_minus_first == 1){
					in2[0] = '%';
					when_put_minus = 1;}

				else
					in2[0] = '%';}}
}
