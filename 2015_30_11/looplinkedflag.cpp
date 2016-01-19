#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int num;
	struct node *next;
	int check = 0;
};
void number(int,int);
void median(struct node*,int);
void main(){
	int N;
	scanf_s("%d", &N);
	number(10,N);

}
void number(int N,int num1){
	if (N < 0){
		N *= -1;
	}
	int i = 0, count = 0;
	struct node *head, *current, *temp;
	current = (struct node*)malloc(sizeof(struct node));
	current->num = 0;
	current->next = NULL;
	head = current;




	while (i <= N){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->num = i;
		i+=2;
		count++;
		temp->next = NULL;

		current->next = temp;
		current = temp;

	}
	current->next = head;

	median(head,num1);


}


void median(struct node *head,int num1){
	struct node *current, *temp1,*temp2;
	current = head->next;
	temp1 = current->next;
	int flag = 0;
	temp2 = (struct node*)malloc(sizeof(struct node));
	temp2->num = num1;
	while (current ->next!= head){
		if (current->num <= num1&&temp1->num >= num1){
			current->next = temp2;
			temp2->next = temp1;
			flag = 1;
		}
		current = current->next;
		temp1 = temp1->next;
	}
	if (flag == 0 && head->num<temp2->num){
		current->next = temp2;
		temp2->next = head;
	}
	else if(flag==0&&head->num<=temp2->num){
		current->next = temp2;
		temp2->next = head;
		head = temp2;
	}
	
	for (current = head->next; current != head; current = current->next){
		printf("%d\t", current->num);
	}

}
