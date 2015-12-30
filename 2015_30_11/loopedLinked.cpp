#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int num;
	struct node *next;
};
void generate(int);
void loop(struct node*);
void check(struct node*);
void main(){
	generate(20);
}
void generate(int num1){
	int i = 1, count = 0;
	struct node *head1, *current1, *temp1, *head2, *current2, *temp2;
	current1 = (struct node*)malloc(sizeof(struct node));

	current1->num = 0;
	current1->next = NULL;
	head1 = current1;
	while (i <= num1){
		temp1 = (struct node*)malloc(sizeof(struct node));
		temp1->num = i;
		i += 1;
		count++;
		temp1->next = NULL;

		current1->next = temp1;
		current1 = temp1;

	}
	temp1 = head1->next;
	count = num1 / 2;
	for (i = 0; i <= count ; i++){
		temp1 = temp1->next;
	}
	current1->next = temp1;
	loop(head1);

}
void loop(struct node *head){
	struct node *current1,*current2,*temp;
	current1= head->next;
	current2 = head->next;
	int i, flag = 0,count=0,tempc;
	
	while (1){
		count++;
		current1 = current1->next;
		current2 = current2->next->next;
		if (current1 == current2){
			break;
		}
	}
	temp = current2;
	current2 = current1->next;
	
	while (flag != 1){
		current1 = head->next;
		tempc = 0;
		while (current1 != current2){
			current1 = current1->next;
			tempc++;
		}
		if (tempc >= count){
			temp = current2;
			current2 = current2->next;
		}
		else{
			temp->next = NULL;
			break;
		}
		
	}
	check(head);
	
}
void check(struct node *head){
	struct node *current1;
	current1 = head->next;
	while (current1 != NULL){
		printf("%d\t", current1->num);
		current1 = current1->next;
	}
}