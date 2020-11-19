#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{ 
	int data;
	struct Node *next;
}*current,*head,*tail;

/* Problem 1.1.1
 * Create and Display a "Singly Linked List"
 * in "Reverse" 
 */
 
void Create();
void Display();
void Reverse();

int data; 

int main() {
	
	
	puts("Input numbers terminated by 0 ");
	puts("============================== ");
	Create();
	puts("\n\nGiven DATA");
	puts("==================");
	Display();
	puts("\n\nReversed Given DATA");
	puts("==================");
	Reverse();
	Display();
	return 0;
}

void Create(){
	
	int i = 0;
	
	//main problem would be if we need a node of 0 
	
	/* proves that the loop can be done using 
	(/)do while, syntax do{}while(i!=0) or not equal to any negative number 
	while, syntax while(i!=-1) not equal to any negative number
	and (/)for for(i = 1; i != 0; i++) or not eqaul to any negative number.
	 */
	 
	// creating n nodes and adding to linked list
	while(i!=-1){ //initialize a loop 
		printf("Data: "); //print the data 
		current = (struct Node *)malloc(sizeof(struct Node));
		scanf("%d", &data);
		
		if(data == 0){ //check if input of data will be terminated
			break;
		} //if
		
		current->data = data;
		//points out that the current data is equals to the given data
		current->next = NULL;
		//points out that the next node will be null
		
		if(i==0){ // meaning there is no input in first node yet.
			head = current;
			// points out that the head will adopt the input data
			tail = current;
			// point out that the tail will adopt the input data
		}else{
			tail->next = current;
			// points out that the next tail will go to the current data
			tail = current; 
			//points out that the tail will adopt the new input data
		} //if else 
	
		i++;
	} //while loop
} //create

void Display(){
	
	current = head;
	//points out that the current should go again to the head
	//p.s. to return to the start
	
	while(current != NULL)
	{
		printf("%d  ", current->data);
		//points out that it will print out the current data
		
		current = current->next;
		//points out that the current would move to the next node
	}
}

void Reverse(){
        tail = head;
        current = head->next;
        head = head->next;
 
        tail->next = NULL; //convert the first node as last
 
        while(head != NULL)
        {
            head = head->next;
            current->next = tail;
 
            tail = current;
            current = head;
        }
        head = tail; //convert the last node as head
}

