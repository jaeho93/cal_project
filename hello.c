#include <stdio.h>	// 단항 연산자 아직 구현 못함.ㅠㅠ								
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
int mul[N] = {};
int div_j[51] = {};

char var[10] = {};					// 여기는 변수 저장용으로 초기화 하지 않는다.
char var_var[10][61] = {};
int var_num = 0;

char c_lear[N] = "clear";
char e_nd[N] = "end";
char V_AR[N] = "VAR";
char s_ave[N] = "save";
char l_oad[N] = "load";

_Bool carry, point;
//_Bool minus_count_1, minus_count_2;

int str_in1, str_in2, str_in3, str_res_s;   // in1, in2, in3, res_s의 길이
int temp = 0, temp1_d = 0, temp3_d = 0, res_d = 0, temp_j = 0, temp_s = 0;
int first = 0, last = 0;
int k = 0, p = 0, q = 0, daeso = 0, choice = 0, chosen;
int m = 0, x = 0, y = 0;
int minus_sign_count = 0;
int if_minus_first = 0;
int if_minus_last = 0;
int when_put_minus = 0;
int begin_val = 0, begin_num = 0, begin_chosen = 0;

void input();
void c_hoice();
void var_cal();	
void separate(); 			// 정수부 소수부 분리

void check_sign_in1();
void check_sign_in3();
void re_array_in1();
void re_array_in3();

void invert1();   			// 계산 전 배열 뒤집기
void invert1_mul_s();
void invert2();				// 계산 후 배열 뒤집기
void invert2_mul_s();
void compare();				// 앞뒤수 비교
void compare_div();			// 나누기용 앞뒤수 비교
void convert1();			// char > int 변환
void convert2();			// int > char 변환
void mul_convert();         // char > int 변환(곱셈 일때)
void convert3();
void plus();
void minus();
void minus_div();			// 나누기용 마이너스
void multiply();
void divide();
void remain();
void initialization();
void comma(char n[]);
void VAR();
void var_in();
void save();
void load();

int main() {

	printf("Start....");
start:

	printf("\n(input) ");			//계산기 프로그램 시작

	input();

	c_hoice();

	if (chosen != 1){  				// in1에 입력받은 문자가 1자리 대소문자가 아닌 경우 

		var_cal();


		check_sign_in1();  // 첫번째 연산자 +/- 부호 체크
		check_sign_in3();  // 두번째 연산자 +/- 부호 체크
		re_array_in1();    // 경우에 따라 연산자 순서 바꿔 저장
		re_array_in3();    // 경우에 따라 연산자 순서 

		separate();


		if(in2[0] == '-'){
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


		else if(in2[0] == '+'){
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


		else if(in2[0] == '*'){
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

		else if(in2[0] == '%'){
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



		switch (in2[0]) 				{		

			case '+' : { invert1(); convert1(); plus(); convert2(); invert2(); break; }
			case '-' : { invert1(); compare(); convert1(); minus(); convert2(); invert2(); break; }
			case '*' : { invert1(); invert1_mul_s();  multiply(); invert2(); invert2_mul_s(); break;  }
			case '/' : { invert1(); compare(); convert1(); divide(); convert2(); invert2(); break; }
			case '%' : { invert1(); compare(); convert1(); remain(); convert2(); invert2(); break; }

			default: ;
		}	

		printf("        = ");

		if(when_put_minus == 1)
			printf("-");	
		//	if(when_remove_minus == 1)
		//여기서 - 부호 하나를 배열에서 빼주는 명령어 쓸 수 없을까?


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
	for (int i = 0; i < 999; i++)
	{
		begin_val = getchar();    // 문자 한 개씩 받아서 begin_var 넣기
		if (begin_val != 10)  	  // 받은 문자가 엔터가 아닌 경우
			begin[i] = begin_val;
		else					  // 받은 문자가 엔터인 경우
		{
			begin[i] = begin_val;
			break;
		}
	}

	for (int i = 0; i <= 60; i++)
	{
		if (begin[i] == 10)   	// 받은 문자가 엔터인 경우
			return ;
		else {
			if (begin[i] != 32)   // 받은 문자가 공백이 아닌 경우
				in1[i] = begin[i];
			else  				// 받은 문자가 엔터인 경우
			{
				begin_num = i + 1;
				break;
			}
		}}

	for (int i = 0; i <= 60; i++, begin_num++)
	{
		if (begin[begin_num] == 10)  // 받은 문자가 엔터인 경우
			return ;
		else 						// 엔터가 아닌 경우
		{
			if (begin[begin_num] != 32)  // 받은 문자가 공백이 아닌 경우
				in2[i] = begin[begin_num];
			else 					// 공백인 경우
			{
				begin_num++;
				break;
			}
		}
	}

	for (int i = 0; i <= 60; i++, begin_num++)
	{
		if (begin[begin_num] != 10)   // 받은 문자가 엔터인 경우
			in3[i] = begin[begin_num];
		else						// 엔터가 아닌 경우
			break;
	}
}

void c_hoice(){

	str_in1 = strlen(in1);   // in1, in2, in3 길이 재기
	str_in2 = strlen(in2);
	str_in3 = strlen(in3);

	var_in(); if (chosen == 1) return ;   //var_in함수  에서 나왔던 chosen이 1 이면(=변수 1개가 정의됬으면) choice함수 총료

	else   //  var_in함수에서 변수가 정의 되지 않았으면
	{
		if (str_in1 == 1)   //in1에 입력받은 문자가 1 자리인 경우
		{	
			if (str_in2 == 0)  //in2에 아무것도 입력받지 않은 경우
			{
				if (in1[0] >= 'A' && in1[0] <= 'Z')  // in1에 대문자가 들어온 경우
				{
					for (int i = 0; i <= 9; i ++)
					{
						if (in1[0] == var[i])  // in1에 입력된 문자가 var에 선언된 변수 이름과 같은경우
						{
							begin_chosen = i;   
							printf("        = "); comma(var_var[begin_chosen]); chosen = 1; return; // 선언했던 변수값 세자리마다 ',' 찍어서 출력

						}
						else // in1이 var에 선언된 변수가 아닌 경우
							begin_chosen = 100;
					}
				}

				else if (in1[0] >= 'a' && in1[0] <= 'z')  // 소문자인 경우
				{
					in1[0] -= 32;				// 대문자로 바꾸기
					for (int i = 0; i <= 9; i ++)
					{
						if (in1[0] == var[i])
						{
							begin_chosen = i;
							printf("        = "); comma(var_var[begin_chosen]); chosen = 1; return;

						}
						else
							begin_chosen = 100;
					}
				}
			}}

		else // in1에 입력받은 문자가 1자리가 아닌 경우
		{
			choice = strcmp (in1, c_lear);  // in1과 c_lear 비교
			if (choice == 0) {system("clear"); chosen = 1; return ;}  // in1 에 clear 입력되면 화면 지움.
			else { choice = strcmp (in1, e_nd);  //in1과 e_nd 비교
				if (choice == 0) exit(1);   // in1에 end 입력됬으면 프로그램 종료
				else { choice = strcmp (in1, V_AR); //in1과 V_AR 비교
					if (choice == 0) {VAR(); chosen = 1; return ;}  //in1 == V_AR 이면 VAR함수 실행 
					else { choice = strcmp (in1, s_ave); //in1 과 s_ave 비교
						if (choice == 0) {save(); chosen = 1; return;}  // in1 에  save 입력되면 save()함수 실행, 변수 값을 파일로 저장 
						else { choice = strcmp (in1, l_oad); //in1 과 l_oad 비교
							if (choice == 0) {load(); chosen = 1; return;} // in1에 load 입력되면 load() 함수 실행, 파일로부터 변수의 값을 읽어옴
						}}}}
		}
		if (begin_chosen == 100)   // in1이 var에 선언된 변수가 아닌 경우
		{printf("        = undefined."); chosen = 1; return;}
	}

} // choice 함수

void var_cal(){ /*수식에서 변수를 연산자로 사용할 때   쓰는 함수 */

	if (str_in1 == 2)   // 두자리수인 경우
		if (in1[0] == '-')  //음수인 경우
		{
		if (in1[1] >= 'A' && in1[1] <= 'Z')  // 변수 이름인 경우
		{
			for (int i = 0; i <= 9; i ++)
			{
				if (in1[1] == var[i])
				{
					begin_chosen = i;
					for (int u = 0, ui = 1; u <= 60; u++, ui++)
						in1[ui] = var_var[begin_chosen][u];
					break;	
				}
			}
		}
		

		else if (in1[1] >= 'a' && in1[1] <= 'z')  // 변수 이름인 경우
		{
			in1[1] -= 32;
			for (int i = 0; i <= 9; i ++)
			{
				if (in1[1] == var[i])
				{
					begin_chosen = i;
					for (int u = 0, ui = 1; u <= 60; u++, ui++)
						in1[ui] = var_var[begin_chosen][u];
					break;	
				}
			}
		}
		}

	if (str_in3 == 2)
		if (in3[0] == '-')
		{ 
		
		if (in3[1] >= 'A' && in3[1] <= 'Z')
		{
			for (int i = 0; i <= 9; i ++)
			{
				if (in3[1] == var[i])
				{
					begin_chosen = i;
					for (int u = 0, ui = 1; u <= 60; u++, ui++)
						in3[ui] = var_var[begin_chosen][u];
					break;	
				}
			}
		}
		

		else if (in3[1] >= 'a' && in3[1] <= 'z')
		{
			in3[1] -= 32;
			for (int i = 0; i <= 9; i ++)
			{
				if (in3[1] == var[i])
				{
					begin_chosen = i;
					for (int u = 0, ui = 1; u <= 60; u++, ui++)
						in3[ui] = var_var[begin_chosen][u];
					break;	
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
					begin_chosen = i;
					for (int u = 0; u <= 60; u++)
						in1[u] = var_var[begin_chosen][u];
					break;	
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
					begin_chosen = i;
					for (int u = 0; u <= 60; u++)
						in1[u] = var_var[begin_chosen][u];
					break;	
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
					begin_chosen = i;
					for (int u = 0; u <= 60; u++)
						in3[u] = var_var[begin_chosen][u];
					break;	
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
					begin_chosen = i;
					for (int u = 0; u <= 60; u++)
						in3[u] = var_var[begin_chosen][u];
					break;	
				}
			}
		}
	}
}

void check_sign_in1(){ // 부호 체크하는 함수
	if(in1[0] == '-'){  // 음수면
		for(int i = 0 ; i < N; i++){
			temp_in1[i] = in1[i+1];}  // -부호 제외하고 임시 저장 배열에 넣기
		if_minus_first += 1;   // 첫번째 연산가 음수
		minus_sign_count += 1;}  // 결과에  (-)를 붙일지 말지 판별

	else               // 양수면
		for(int i = 0; i < N ; i++)
			temp_in1[i] = in1[i];  // 그대로 임시 저장 배열에 넣기
}	

void check_sign_in3(){ // 두번째 연산자 부호 체크하는 함수
	if(in3[0] == '-'){   // 음수면
		for(int i = 0 ; i < N; i++){
			temp_in3[i] = in3[i+1];}  // - 부호 제외하고 임시 저장 배열에 넣기
		if_minus_last += 1;           // 두번째 연산자가 음수
		minus_sign_count += 1;}       // 결과에 (-)를 붙일지 말지 판별

	else  // 양수면
		for(int i = 0; i < N ; i++)
			temp_in3[i] = in3[i];  // 그대로 임시 저장 배열에 넣기
}	

void re_array_in1(){ /* 원래의 배열(in1)에 부호를 빼서 넣어주는 함수 */
	if(in2[0] == '/' || in2[0] == '%'){   
		if((if_minus_first + if_minus_last)== 0)  // 두 연산자 모두 양수 일때
			for(int i = 0; i < N; i++)
				in1[i] = temp_in1[i];         
		else if((if_minus_first + if_minus_last) == 1){
			if(if_minus_first == 1){   // 두 연산자 중에 음수가 첫번째 연산자인 경우
				for(int i = 0; i < N; i++)
					in1[i] = temp_in1[i];}  

			if(if_minus_last == 1){	   // 두 연산자 중에 음수가 두번째 연산자인 경우
				for(int i = 0; i < N; i++)
					in1[i] = temp_in1[i];}}
		else        //  두 연산자 모두 음수
			for(int i = 0; i < N; i++)
				in1[i] = temp_in1[i];}


	else{  // + , - , % 연산인경우
		if((if_minus_first + if_minus_last)== 0)   // 두 연산자 모두 양수
			for(int i = 0; i < N; i++)
				in1[i] = temp_in1[i];

		else if((if_minus_first + if_minus_last) == 1){
			if(if_minus_first == 1){ // 두 연산자중 첫번째 연산자 음수
				for(int i = 0; i < N; i++)
					in3[i] = temp_in1[i];}

			if(if_minus_last == 1){	// 두 연산자중 두번째 연산자 음수 
				for(int i = 0; i < N; i++)
					in1[i] = temp_in1[i];}}
		else  // 두연산자 모두 음수
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
		{temp1_d = i+1; break;}
		else in1_j[i] = in1[i];		  } // in1의 정수부분 in1_j 배열에 저장
	if (in1[50] == '.')
		temp1_d = 51;

	if (temp1_d != 0){  // temp1_d : 소수점이 앞에서부터 몇번째인지
		for (int i = 0; i <= 8; temp1_d++, i++)
			in1_s[i] = in1[temp1_d];  // in1 (첫번째 연산자)의 소수부분 in1_s 배열에 저장
	}


	for (int i = 0; i <= 49; i++) {
		if (in3[i] == '.')
		{temp3_d = i+1; break;}
		else in3_j[i] = in3[i];		  }  //
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
   void mul_convert(){    // char > int 변환 함수 - 곱셈 일때

   for(int i = 0; i < strlen(in1_s) ; i++)
   mul_1[i] - in1_s[i] - '0';

   for(int i = strlen(in1_s), t = 0; i<strlen(in1_s) + strlen(in1_j); i++){
   mul_1[i] = in1_j[t] - '0';
   t++;}

   for(int i = 0; i < strlen(in3_s) ; i++)
   mul_3[i] - in3_s[i] - '0';

   for(int i = strlen(in3_s), t = 0; i<strlen(in3_s) + strlen(in3_j); i++){
   mul_3[i] = in3_j[t] - '0';
   t++;}
   }

*/

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

	for (int i = 8; i >= 0; i--)			{	/******* 소수 더하기*******/
		res_s[i] = in1_s[i] + in3_s[i] + k;  
		
		if (res_s[i] >= 10) 	{  //더해서 10 이 넘어가면
			k = 1; res_s[i] -= 10;}					//   k : 1 올림수  , 10을뺀 나머지를 저장  예를들어 더해서 17이면 앞배열에 1 더하고 현재 배열에 7 저장          오류 생길 수 있다.
		else k = 0;	  // 더해서 10미만이면  올림수 없음							}

		p = strlen(res_s);

		for (int i = 0; i <= 49; i++)			{		// 정수 더하기
			res_j[i] = in1_j[i] + in3_j[i] + k;
			if (res_j[i] >= 10)	{
				k = 1; res_j[i] -= 10;}
			else k = 0;								}

} // plus 함수 

void minus(){   /* 마이너스함수 */

	if (daeso == 0) //앞에 수가 큰 경우
	{
		for (int i = 8; i >= 0; i--)			{	/**** 소수 빼기****/
			res_s[i] = in1_s[i] - in3_s[i] - k;
			
			if ( i != 0)	{     
				if (res_s[i] < 0) 	{
					k = 1; res_s[i] += 10;}					// 오류 생길 수 있다.
				else k = 0;								}
		}
			
			if (res_s[0] < 0)  //   소수자리 연산후   소수 첫째 자리가 음수면 10 더하기
			       {res_s[0] += 10; k = 1;}  //   1 만큼 정수 자리에서 빼기 위함
		
			else k = 0;  // 소수 첫째 자리가 음수가 아니면  정수에서 1 안뺌

			
			for (int i = 0; i <= 49; i++)			{		/**** 정수 빼기****/
				res_j[i] = in1_j[i] - in3_j[i] - k;  // 정수끼리 빼기        /*   k : 정수에서 빌려온값이 있으면 1 없으면 0  */ 
				
				if (res_j[i] < 0)	{
					k = 1; res_j[i] += 10;}   //  빼서 음수면 10 더한값 저장 

				else k = 0;			
			}

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

	x = strlen(in1_s) + strlen(in1_j);
	y = strlen(in3_s) + strlen(in3_j);

	for(int i = 0 ; i < strlen(in1_s) ; i++) 

		mul_1[i] = in1_s[i]-'0';        // mul_1배열에 소수부분 아스키코드값 빼서 저장	

	for(int i = strlen(in1_s), t = 0 ; i < strlen(in1_s) + strlen(in1_j) ;){ // 변수 t 설정(정수부 넣기 위해서)
		mul_1[i] = in1_j[t]-'0';    //  mul_1배열에  . 을 제외하고 정수부분 이어서 저장
		t++,i++;}

	for(int i = 0 ; i < strlen(in3_s) ; i++) 
		mul_3[i] = in3_s[i]-'0';	// mul_3배열에 아스키 코드값 빼서 소수부분 저장

	for(int i = strlen(in3_s), t = 0 ; i < strlen(in3_s) + strlen(in3_j) ; ){
		mul_3[i] = in3_j[t]-'0';   // mul_3 배열에 . 을 제외하고 정수 부분 이어서 저장
		t++,i++;}


	if(strlen(in3) >= strlen(in1)){  //곱셈결과를 mul 배열에 차곡차곡 쌓는 과정
		for(int i = 0; i < x; i++){  // 더 짧은수 돌리는 for문
			for(int n = 0; n < y; n++)		
			{mul[m] += (mul_1[i] * mul_3[n]);	
				m++;}

			m -= y-1;}}
	else{
		for(int i = 0; i < y ; i++){
			for(int n = 0; n < x ; n++)
			{mul[m] += (mul_3[i] * mul_1[n]);
				m++;}

			m -= x-1;}}

	point = ((temp1_d + temp3_d)!= 0) ? 1 : 0; //소수점이 있으면 point = 1 , 없으면 point = 0

	
	if(point){							 //입력 받은 두 수중에 하나라도 소숫점이 있는 경우
		for(int i = 0 ; i < x+y; i++){      
			if(mul[i] >= 10){
				mul[i+1] += (mul[i]) / 10;
				mul[i] = (mul[i]) % 10;
			}
			
			else{
				mul[i] = (mul[i]) % 10;}
		}
	}


	else{								
		for(int i = 0; i<x+y-1; i++){
			if(mul[i] >= 10){
				mul[i+1] += (mul[i]) / 10;
				mul[i] = (mul[i]) % 10;}
			else
				mul[i] = (mul[i]) % 10;}}

	carry = (mul[x+y-1] != 0 ? 1 : 0);	 // mul배열에 가장 마지막에 올림수가 있으면 carry = 1


	for (int i = 0; i <= 49; i++) {		// 소수점(temp1_d) 재조정
		if (in1[i] == '.')
		{temp1_d = i+1; break;}}
	for (int i = 0; i <= 49; i++) {		
		if (in3[i] == '.')
		{temp3_d = i+1; break;}}

	if(point){
		if(carry){	
			for(int i = 0, c = 0; i < x+y+1 ; i++,c++){ 
				if(i == strlen(in1_s) + strlen(in3_s) ){
					last_mul[i] = '.'; 
					c--;}

				else{
					last_mul[i] = mul[c] + '0';	}}}

		else{
			for(int i = 0 , c = 0; i<x+y; i++, c++){
				if(i == strlen(in1_s) + strlen(in3_s) ){
					last_mul[i] = '.';
					c--;}

				else{
					last_mul[i] = mul[c] + '0';	}}}}

	else{
		if(carry){
			for(int i = 0, c = 0; i< x+y; i++,c++)
				last_mul[i] = mul[c] + '0';}

		else
			for(int i = 0, c = 0; i<x+y-1; i++,c++)
				last_mul[i] = mul[c] + '0';}



	if(point){
		for(int i=0, c=0 ; i < strlen(last_mul); i++){
			if( i < strlen(in1_s) + strlen(in3_s)){
				res_s[i] = last_mul[c];
				c++;}

			else{
				if( c < strlen(last_mul)-1){
					res_j[i-(strlen(in1_s)+strlen(in3_s))] = last_mul[c+1];
					c++;}

				else
					break;}}}
	else{
		for(int i=0, c=0; i < strlen(last_mul); i++){
			if( i < strlen(in1_s) + strlen(in3_s)){
				res_s[i] = last_mul[c];
				c++;}

			else{
				if( c < strlen(last_mul)){
					res_j[i-(strlen(in1_s)+strlen(in3_s))] = last_mul[c];
					c++;}

				else
					break;}}}

} // multiply 함수



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

	if ( daeso == 1 ){
		for(int i = 0; i <= 49 ; i++)
			res_j[i] = in1_j[i];
		for(int i = 0; i <= 8 ; i++)
			res_s[i] = in1_s[i];
		daeso = 0; return ;} 


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

	str_in1 = 0, str_in2 = 0, str_in3 = 0, str_res_s = 0;
	temp = 0, temp1_d = 0, temp3_d = 0, temp_j = 0, temp_s = 0;
	first = 0, last = 0;
	k = 0, p = 0, q = 0, daeso = 0, choice = 0, chosen = 0;
	m = 0, x = 0, y = 0;
	if_minus_last = 0, if_minus_first = 0, minus_sign_count = 0;
	when_put_minus = 0;
	begin_val = 0, begin_num = 0, begin_chosen = 0;

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
		printf("        %c = ", var[i]);
		comma(in1_j);
		if (p != 0)
		{printf(".");
			comma(in1_s);}
		printf("\n");}	
	return ;

} // VAR 함수

void var_in(){   /* 변수 선언 및 정의 함수   */

	if (str_in1 == 1) 	{  //in1에 입력받은 수가 한자리 라면
		if (in1[0] >= 'A' && in1[0] <= 'Z')		{  //in1에 대문자 들어갈 때
			if (in2[0] == '=')  {
				var[var_num] = in1[0];          //변수 저장 배열에 변수 이름 넣기
				for (int i = 0; i <= 60; i++)
					var_var[var_num][i] = in3[i];      // 변수에 입력값 저장
				for (int u = 0; u <= N; u++)           
					in1[u] = var_var[var_num][u];    // in1 배열에 저장했던 변수값 넣기 (저장한값 출력하기 위함)
				separate();          
				p = strlen(in1_s);
				printf("        = ");
				comma(in1_j);
				if (p != 0)    // in1 소수 자리수가 있으면
				{printf(".");   // '.'찍기 
					comma(in1_s);}

				var_num++; chosen = 1;
				return ;			}					}

		else if (in1[0] >= 'a' && in1[0] <= 'z')  {  // in1에 소문자 들어갈 때
			if (in2[0] == '=')   {
				var[var_num] = in1[0] - 32;   // 대소문자 구별 안함. 변수 저장 배열에 변수 이름 넣기
				for (int i = 0; i <= 60; i++)
					var_var[var_num][i] = in3[i];  // 변수에 입력값 저장
				for (int u = 0; u <= N; u++)
					in1[u] = var_var[var_num][u];   // in1 배열에 저장했던 변수값 넣기 (저장한값 출력하기 위함)
				separate();
				p = strlen(in1_s);
				printf("        = ");
				comma(in1_j);  // 세자리마다 , 삽입
				if (p != 0)               // in1에 소수 자리수가 있으면
				{printf(".");           //'.'찍기
					comma(in1_s);}

				var_num++; chosen = 1;  // main함수 start부분 부터 다시 시작
				return ;			}					  }}

} // var_in 함수

void save()
{

	FILE *out1;
	FILE *out2;
	FILE *out3;

	out3 = fopen("save_var_num", "w+");
	fprintf(out3, "%d", var_num); 
	fclose(out3);

	out1 = fopen("save_var", "w+");

	for (int i = 0; i <= 9; i++)
	{
		if (var[i] != 0)
		{
			fprintf(out1, "%c", var[i]);
		}
		else break;
	}

	fclose(out1);
	out2 = fopen("save_var_var", "w+");

	for (int i = 0; i <= 9; i++)
	{
		if (strlen(var_var[i]) != 0)
		{
			fprintf(out2, "%s\n", var_var[i]);	
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

	in3 = fopen("save_var_num", "r");
	fscanf(in3, "%d", &cnt);
	fclose(in3);


	in1 = fopen("save_var", "r");
	for (int i = 0; i <= (cnt - 1); u++, i++)
	{
		if (u == 10) { fclose(in1); return ; }
		else
		{
			fscanf(in1, "%c", &var[u]);
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
			fscanf(in2, "%s", var_var[u]);
		}
	}
	var_num = u;
	fclose(in2);
}





