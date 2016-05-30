#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {

	char a[4] = {};
	char b[4] = {};
	char mu[6] = {0, 0, 0, 0, 0};
	int m = 0, first = 0, last = 0, temp = 0;


	scanf("%s", a);
	scanf("%s", b);

	printf("처음수 \n");
	printf("%s\n", a);
	printf("%s\n", b);


	last = strlen(a) - 1;
	while(1) 					{
		if(first > last) break;
		temp = a[last];
		a[last] = a[first];
		a[first] = temp;
		first++, last--;		}
	first = 0, last = 0;

	last = strlen(b) - 1;
	while(1) 					{
		if(first > last) break;
		temp = b[last];
		b[last] = b[first];
		b[first] = temp;
		first++, last--;		}
	first = 0, last = 0;

	printf("뒤집은 수 \n");
	printf("%s\n", a);
	printf("%s\n", b);

	for (int i = 0; i <= 2; i++) 
	a[i] -= '0';			 
	for (int i = 0; i <= 2; i++) 
	b[i] -= '0';			 

	for (int i = 0; i <= 2; i++)
	printf("%d\n", a[i]);
	for (int i = 0; i <= 2; i++)
	printf("%d다음에 곱\n", b[i]);

	for(int i = 0; i <= 2; i++)	{
	for(int n = 0; n <= 2; n++)		
	{mu[m] += (a[n] * b[i]);						
	printf("%d\n", mu[m]);
	m += 1;	} m -= 1;}

	for (int i = 0; i <= 4; i++)
	printf("전까지 곱%d\n", mu[i]);

	for(int i = 0; i <= 4; i++)					{
	if (mu[i] >= 10)
	{mu[i+1] += 1; mu[i] -= 10;}				}

	for (int i = 0; i <= 4; i++)
	mu[i] += '0';

	last = strlen(mu) - 1;
	while(1) 					{
		if(first > last) break;
		temp = mu[last];
		mu[last] = mu[first];
		mu[first] = temp;
		first++, last--;		}
	first = 0, last = 0;

	printf("답\n");
	printf("%s", mu);
	

	return 0;
}
