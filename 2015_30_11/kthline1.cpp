#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
void main(){
	FILE *fp; char ch; int count = 0, count1 = 0;
	int K;
	scanf_s("%d", &K);
	fp = fopen("trail.txt", "r");
	if (fp == NULL){
		printf("no such file");
	}
	while(!feof(fp)){
		ch = fgetc(fp);
		if (ch == '\n')
			count++;
		
	}
	count++;
	count -= K;
	fp = fopen("trail.txt", "r");
	while (!feof(fp)){
		ch = fgetc(fp);
		if (ch == '\n')
			count1++;
		if (count1 == count)
			break;
	}
	while (!feof(fp)){
		ch = fgetc(fp);
		printf("%c", ch);
	}
}