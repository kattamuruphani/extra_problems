#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void kth(int, int, int);
void main(){
	
	kth(5, 8, 10);
	_getch();

}
void kth(int K, int a, int b){
	int i = 2,x=a,y=b,val;
	int lcm = 1, total;
	int sum1=0, sum2=0;
	while (i <= a && i <= b){
		while (x%i == 0 && y%i == 0){
			x /= i;
			y /= i;
			lcm *= i;
		}
		i++;
	}
	lcm *= x*y;
	x = lcm / a;
	y = lcm / b;
	
	total = (x + y);
	total --;
	val = K / total;
	x = val*x;
	y = val*y;
	sum1 = x*a;
	sum2 = sum1;
	val = 0;
	total *= val;
	if (K > total){
		while (total < K){
			if (sum1 + a < sum2 + b){
				sum1 += a;
				val = sum1;
			}
			else{
				sum2 += b;
				val = sum2;
			}
			total++;
		}
		printf("%d", val);
	}
	else{
		total = 0;
		while (total < K){
			if (sum1 + a < sum2 + b){
				sum1 += a;
				val = sum1;
			}
			else{
				sum2 += b;
				val = sum2;
			}
			total++;
		}
		printf("%d", val);
	}

}