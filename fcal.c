#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 60
#define M 50

int main(void){
	char a[N]={}, b[N]={} ,a_up[M]={} ,b_up[M]= { }, c_up[M] ={};
	char c[N]={};
	int e=0,k,p,q,g=0,i=0, t=0, str_a, str_b, str_c;

	scanf("%s",a);

	for(i=0; ;i++){
		if(a[i]==46) break;
	   
	    for(k=0; k <= i;k++)   // 정수부분은 k 자리  만약 111.1 이면 k = 3이다
	    a_up[k] = a[k]; }      //a_up 은 정수 부분만 
	    	  
    str_a = i-1;

	scanf("%s",b);
	
	  for(e=0;;e++){

	   if(b[e]==46) break;

	   for(g=0;g <= e; g++)
		   b_up[g] = b[g];     //정수부분은 g 자리  b_up은 정수 부분만
	  }
    str_b = e-1;


	p = str_a -1;
	q = str_b -1; 

	int shift;

	if(str_a >= str_b){

		shift = str_a - str_b;
		for(int i ;i >= 0 ;i--)
            a_up[p+shift] = a_up[p];

		for( ; q>=0; q--) // 길이가 짧은 배열b 위치 재조정
			b_up[q+shift] = b_up[q];

		for(; shift > 0 ; shift--)	// 위치 조정 후 남는 공간에 '0' 넣기
			b_up[shift-1] = '0'; 


		for(; p >= 0; p--){

			c_up[p+1] += (( a_up[p] + b_up[p] ));

		   if(c_up[p+1] >= (10+96)){

				c_up[p]+=1;

				c_up[p+1] -= (96+10);}

			else { c_up[p+1] -= 96;}			
		}

		if(c[0] != 0)
			for(int j=0; j<= str_a ; j++)
				printf("%d", c_up[j]);
		else
			for(int j=1; j<= str_a; j++)
				printf("%d", c_up[j]);
	}

	else if(str_b > str_a){  //길이가 짧은 a 배열 위치 조정
		shift = str_b - str_a;

		for(; p>=0 ; p--)	
			a_up[i+shift] = a_up[p];

		for(; shift>0 ; shift--)
			a_up[shift-1] = '0';

		for( ; q >= 0 ;q--){

			c_up[q+1] += ((a_up[q]+b_up[q]));

			if(c_up[q+1] >= (10+96)){

				c_up[q]+=1;

				c_up[q+1] -= (96+10);}

			else c_up[q+1] -= 96;	}	

	if(c_up[0] == 0)

	for(int j=1; j <= str_b ; j++)
			printf("%d",c_up[j]);

	else if(c[0] != 0)
		
		for(int j=0 ; j <= str_b ; j++)
			printf("%d", c_up[j]);

	}
	return 0;
}















