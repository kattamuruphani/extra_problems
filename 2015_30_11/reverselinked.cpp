
#include <stdio.h>
#include<malloc.h>



struct node {
	int num;
	struct node *next;
};
void number(int);
void reverse(struct node*, struct node*,struct node**);
void main(){
	int N=5;
	
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
		i++;
		count++;
		temp->next = NULL;

		current->next = temp;
		current = temp;

	}
	current = head->next;
	temp = (struct node*)malloc(sizeof(struct node));
	reverse(NULL,head->next,&temp);
	
	
	
	
	
	for (current = temp; current != NULL; current = current->next){
		printf("%d", current->num);
	}
	
	//scanf("%d");
}

void reverse(struct node *prev, struct node *current, struct node **newhead){
	if (current->next == NULL){
		*newhead = current;
		current->next = prev;
	}
	else{
		reverse(current, current->next, newhead);
		current->next = prev;
		
	}

}
