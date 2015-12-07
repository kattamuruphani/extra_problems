#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int num;
	struct node *next;
	int flag = 0;
};
void generate(int,int);
void loop(struct node*, int);
void check(struct node*);
void main(){
	generate(5,6);
	_getch();
}
void generate(int num1,int num2){
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
	current1->next = head1->next;

	loop(head1,num2);

}

void loop(struct node *head, int num){
	struct node *current, *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->num = num;
	temp->next = NULL;
	current = head->next;
	if (current->num > temp->num){
		temp->next = current;
		current = temp;
	}
	else{
		while (1){
			if (current->num > temp->num&&current->next->num){
				temp->next = current->next;
				current->next = temp;
				break;
			}
			else if (current->num < temp->num&&current->next->num < current->num){
				temp->next = current->next;
				current->next = temp;
				break;
			}
			current = current->next;

		}
	}


	for (current = head->next; current != NULL; current = current->next){
		printf("%d", current->num);
	}
}