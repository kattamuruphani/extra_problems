#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int num;
	struct node *next;
};
void generate(int, int);
void merge(struct node*, struct node*);
void main(){
	generate(0, 0);
}
void generate(int num1, int num2){
	int i = 0, count = 0;
	struct node *head1, *current1, *temp1,*head2,*current2,*temp2;
	current1 = (struct node*)malloc(sizeof(struct node));
	current2 = (struct node*)malloc(sizeof(struct node));

	current1->num = 0;
	current1->next = NULL;
	head1 = current1;
	while (i <= num1){
		temp1 = (struct node*)malloc(sizeof(struct node));
		temp1->num = i;
		i += 2;
		count++;
		temp1->next = NULL;

		current1->next = temp1;
		current1 = temp1;

	}

	current2->num = 0;
	current2->next = NULL;
	head2 = current2;
	i = 0;
	while (i <= num2){
		temp2 = (struct node*)malloc(sizeof(struct node));
		temp2->num = i;
		i += 2;
		count++;
		temp2->next = NULL;

		current2->next = temp2;
		current2 = temp2;

	}
	
	merge(head1, head2);
}
void merge(struct node *head1, struct node *head2){
	struct node *current1, *current2,*temp1,*temp2;
	
	int a[10], i = 0;
	current1 = head1->next;
	current2 = head2->next;
	temp1 = current1->next;
	temp2 = current2->next;
	while (temp1!= NULL){
		if (current1->num <= current2->num&&current2->num<=temp1->num&&temp2!=NULL){
			current1->next = current2;
			current2->next = temp1;
			current1 = current2;
			current2 = temp2;
			
			temp2 = temp2->next;
		}
		else{
			current1 = temp1;
			temp1 = temp1->next;
		}
	}
	if (current1->num < current2->num){
		current1->next = current2;
		current1 = current2;
	}
	else{
		current1->next = current2;
		current1 = current2;
		current2 = current2->next;
	}
	if (current1->next == NULL&&current2!=NULL){
		if (current1->num <= current2->num){
			current1->next = current2;
		}
		else{
			temp2 = current1;
			current1 = current2;
			current1->next = current2;
		}

	}

	/*if (current1->next == NULL&&current2->next != NULL){
		
			current1->next = current2;
			
		
	}*/
	printf("head");
	for (current1 = head1->next; current1 != NULL; current1 = current1->next){
		printf("->%d  ", current1->num);
	}
}