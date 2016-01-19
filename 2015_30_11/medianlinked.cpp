
#include <stdio.h>
#include<malloc.h>



struct node {
	int num;
	struct node *next;
};
void number(int);
void median(struct node*,int);
void main(){
	int N;
	//scanf_s("%d", &N);
	number(10);

}
void number(int N){
	if (N < 0){
		N *= -1;
	}
	int i=0,count=0;
	struct node *head, *current, *temp;
	current = (struct node*)malloc(sizeof(struct node));
	current->num = 0;
	current->next = NULL;
	head = current;
	


		
		while (i <=N){
			temp = (struct node*)malloc(sizeof(struct node));
			temp->num = i;
			i++;
			count++;
			temp->next = NULL;
			
			current->next = temp;
			current = temp;

		}
		current = head->next;

		median(head,count);
	

}
void median(struct node *head,int count){
	int  i=count,j;
	float median = 0;
	struct node *current;
	for (i = 0, current = head->next; current != NULL; current = current->next){
		i++;
	}
	
	i /= 2;
	for (j = 0, current = head->next; j <i;){
		j++;
		if(j<i)
			current = current->next;
	}
	if (j % 2 != 0){
		median = current->num;
	}
	else{
		median += current->num;
		current = current->next;
		median += current->num;
		median /= 2;
	}
	printf("%f", median);

}