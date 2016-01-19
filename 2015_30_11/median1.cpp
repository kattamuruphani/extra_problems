#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};
void number(int);
void median2(struct node*);
void main(){
	int N = 6;
	int a[] = { 1, 2, 3, 8, 5, 8 };
	if (N < 0){
		N *= -1;
	}
	int i = 0, count = 0;
	struct node *head, *current, *temp;
	current = (struct node*)malloc(sizeof(struct node));
	current->num = 0;
	current->next = NULL;
	head = current;




	while (i < N){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->num = a[i];
		i++;
		count++;
		temp->next = NULL;

		current->next = temp;
		current = temp;

	}
	current = head->next;
	
	median2(head);

	_getch();

}


void median2(struct node *head){
	struct node *current1, *current2;
	current1 = head->next;
	current2 = head->next;
	int median;
	while (current2 != NULL){
		if (current2->next->next != NULL&&current2 != NULL){
			current2 = current2->next->next;
			current1 = current1->next;
		}
		if (current2->next == NULL){
			median = current1->num;
			break;
		}
		 else if (current2->next->next == NULL&&current2->next != NULL){
			median = current1->num;
			median += current1->next->num;
			median /= 2;
			break;
		}
		 
	}
	printf(" median: %d", median);
}
