#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
void main(){
	FILE *fp1,*fp2; char ch1,ch2; int count = 0, count1 = 0;
	int K;
	scanf_s("%d", &K);
	fp1 = fopen("trail.txt", "r");
	if (fp1 == NULL){
		printf("no such file");
	}
	while (!feof(fp1)){
		ch1 = fgetc(fp1);
		if (ch1 == '\n')
			count++;
		if (count == K)
			break;

	}
	fp2 = fopen("trail.txt", "r");
	while (!feof(fp1)){
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);

	}
	while (!feof(fp2)){
		ch2 = fgetc(fp2);
		printf("%c", ch2);
	}
	
}