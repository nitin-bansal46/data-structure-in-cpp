#include <iostream>
#include<cstdlib>


using namespace std;


struct Node {
   int data;
   struct Node *next;
};

struct Node* head = NULL;


void insert(int new_data) {
   struct Node* new_node = new Node();
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}
void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
void insert_end(int new_data){
    struct	Node *new_node = new Node();
	new_node->data = new_data;
	struct Node *curr;
	curr = head;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = new_node;
}

void insert_at(int new_data, int pos){
	Node *curr = head;
	Node *prev;
	int i = 0;
	Node *new_node = new Node();
	new_node->data = new_data;
	
	while(i != pos){
		prev = curr;
		curr = curr->next;
		i++;
	}
	prev->next = new_node;
	new_node->next = curr;
	
	
}
void count(){
	int count = 0;
	Node *curr;
	curr = head;
	while(curr != NULL){
		count = count + 1;
		curr = curr->next;
	}
	cout<<"\n"<<"Total Length is : "<<count;
}

void search(int data){
	
	int index = 1;
	Node *curr;
	curr = head;
	while(curr != NULL && curr->data != data){
		index = index + 1;
		curr = curr->next;
	}

	if(curr != NULL){
		cout<<"\n"<<"Found at : "<<index;
		 
	}
	else{
		cout<<"\n"<<"Not Found!!!";
		}
	
}

void delete_first(){
	Node *curr = head;
	head = head->next;
	free(curr);
	}
	
void delete_last(){
	Node *last = head;
	Node *second_last;
	while(last->next != NULL){
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	free(last);
}	

void delete_at(int pos){
	int i=0;
	Node *curr = head;
	Node *prev;
	
	while(i !=pos ){
		prev = curr;
		curr = curr->next;
	i++;
	}
	prev->next = curr->next;
	free(curr);
	
	cout<<"\nSuccesfully Deleted at Position : "<<pos<<"\n ";
}
int main() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert_end(13);
   insert(9);
   insert_end(11);
   
   //delete_last();
   //delete_first();
   
   
   cout<<"The linked list is: ";
   display();
   count();
   //delete_at(3);
   insert_at(99,1);
   cout<<"The linked list is: ";
   display();
   //search(-7);
   
   return 0;
}
