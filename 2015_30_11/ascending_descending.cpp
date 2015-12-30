
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};
void number(int);
void reverse(struct node*, struct node*, struct node**);
void correct(struct node*);
void main(){
	int N = 15;
	int a[] = { 1, 2, 3, 4, 5, 8, 7, 6, 9, 10, 11, 15, 14, 13, 12 };
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
	correct(head);
	//temp = (struct node*)malloc(sizeof(struct node));
	//reverse(NULL, head->next, &temp);





	for (current = head; current != NULL; current = current->next){
		printf("%d", current->num);
	}
	_getch();

	//scanf("%d");
}

void reverse(struct node *prev, struct node *current, struct node **newhead){
	if (current == *newhead){
		*newhead = current;
		current->next = prev;
	}
	else{
		reverse(current, current->next, newhead);
		current->next = prev;

	}

}


void correct(struct node *head){
	struct node  *current, *prev,*newhead,*temp;
	prev = head;
	int flag = 0;
	current = head->next;
	while (current != NULL){
		if (current->num > current->next->num){
			while (current->num > current->next->num  && current->next != NULL){
				if (current->next->next != NULL){
					flag = 1;
					current = current->next;
				}
				else{
					flag = 0;
					break;
				}
			}
			if (flag == 0){
				current = current->next;
			}
			temp = (struct node*)malloc(sizeof(struct node));
			temp = current->next;
			newhead = (struct node*)malloc(sizeof(struct node));
			newhead = current;
			reverse(prev->next, prev->next->next,&newhead );
			prev->next->next = temp;
			prev->next = newhead;
			current = temp;
		}
		prev = current;
		if (current!=NULL)
		current = current->next;
	}
}