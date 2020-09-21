#include<iostream>
#include<cstdlib>

using namespace std;

// create structure
struct Node{
	int data;
	Node* next;
	Node* prev;
};

Node *head = NULL;
Node *last = NULL;

void push(int new_data){
	
	
	Node *new_node = new Node();  // Creation of new node.
	new_node->data = new_data;   // input thenew data to new node.
	new_node->next = head;		// link head to next to new node. 
	new_node->prev = NULL;		// link previous node of new node as NULL.
	if(head != NULL)			// check if head is NULL or not, if not null it means already  some data was present so,
	head->prev = new_node;		// also link previous pointer of already present data to new node. 
	head = new_node;		// point head new node to head.
    last = new_node;
	
}
// forward traverse 
void traverse_in(){
	Node *curr = head;
	while(curr != NULL){
		cout<<curr->data<<" <--> ";
		curr = curr->next;
	}
}

// backward travesre 
void traverse_out(){
	Node *curr  = last;
	while(curr != NULL){
		cout<<curr->data<<" <--> ";
		curr = curr->prev;
	}
}
// insertion at end..
void insert_end(int new_data){
	Node* new_node = new Node(); // creation of new node.
	Node *curr = head;				// create new node as current node and point to head .
	new_node->data = new_data;   // put new data in new node.
	new_node->next = NULL;   // link NULL as next of new node.
	if(head == NULL){        // check whether linked list is empty or not, if yes then
		new_node->prev = NULL; 
		head = new_node;
	}
	while(curr->next != NULL){ // if not empty, 
		curr = curr->next;   // traverse to last of the list.
	}
	curr->next = new_node;
	new_node->prev = curr;
	last = new_node;
	}
	
void insert_after(int new_data, int pos){
	Node* new_node = new Node();
	int i = 0;
	Node *curr = head;
	new_node->data = new_data;
	while( i != pos-1){
		curr = curr->next;
		i++;
	}
	new_node->next = curr->next;
	new_node->prev = curr;
	if(curr->next != NULL){
		curr->next->prev = new_node;
		
	}
	curr->next = new_node;
}	

int size(){
	int size = 0;
	Node* curr = head;
	while(curr != NULL){
		size++;
		curr = curr->next;
	}
	return size;
}

void Delete(int pos){
	Node *curr = head;
	int i = 1;
	while(i != pos && curr != NULL){
		curr = curr->next;
		i++;
	}
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	free(curr);
	cout<<"\nNode succesfully deleted from pos : "<<pos<<endl;
	}






int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
//	insert_end(0);
	insert_end(-1);
	insert_after(11,3);
	cout<<"Doubly Linked List is :";
	traverse_in();
	cout<<"\n"<<"Reversed Doubley Linked list : ";
	traverse_out();
	cout<<"\n"<<"Size of the Linked List id : "<<size();
    Delete(5);
	cout<<"Doubly Linked List is :";
	traverse_in();
	
	}
