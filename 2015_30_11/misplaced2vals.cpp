#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int num;
	struct node *next;
};
void generate(int);
void swap(struct node*);
void check(struct node*);
void main(){

	int i = 1, count = 0;
	struct node *head1, *current1, *temp1, *head2, *current2, *temp2;
	current1 = (struct node*)malloc(sizeof(struct node));

	current1->num = 0;
	current1->next = NULL;
	head1 = current1;
	scanf_s("%d", &i);
	while (i != 0){
		temp1 = (struct node*)malloc(sizeof(struct node));
		temp1->num = i;
		temp1->next = NULL;
		current1->next = temp1;
		current1 = temp1;
		scanf("%d", &i);
	}
	swap(head1);
	_getch();
}
void swap(struct node *head){
	struct node *temp1, *current1, *aft1, *bef1, *bef2, *current2, *aft2,*temp2;
	int flag = 0;
	
	bef1 = head;
	current1 = head->next;
	aft1 = current1->next;
	while (1 && current1 != NULL){
		if (current1->num > aft1->num){
			flag++;
			break;
		}
		else{
			bef1 = bef1->next;
			current1 = current1->next;
			aft1 = aft1->next;
		}
	}
	bef2 = bef1->next;
	current2 = current1->next;
	aft2 = aft1->next;
	while (1 && current2 != NULL){
		if (current2->num < bef2->num){
			flag++;
			break;
		}
		else{
			bef2 = bef2->next;
			current2 = current2->next;
			aft2 = aft2->next;
		}
		
	}
	
	if (flag == 2){
		flag = current1->num;
		current1->num = current2->num;
		current2->num = flag;

	}
	check(head);
}

void check(struct node * head){
	struct node * current1;
	current1 = head->next;
	for (; current1 != NULL; current1 = current1->next){
		printf("%d", current1->num);
	}
}