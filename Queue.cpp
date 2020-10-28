#include<iostream>

using namespace std;

int queue[100], back = -1, capacity = 100, front = -1;

void enqueue(int data){
	if(front == capacity-1){
		cout<<"Queue is full !!!";
	}
	else{
		if(front == -1)
		front = 0;
		back++;
		queue[back] = data;
		}
}

void dequeue(){
	if(front == -1){
		cout<<"Queue is empty !!!";
		return;
	}
	else{
		front++;
	}
}

void display(){
	if(front == -1){
		cout<<"Queue is empty ";
	}
	else{
		for(int i = front; i<=back; i++){
			cout<<queue[i]<<endl;
		}
	}
}

int  main(){
	
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	display();

	dequeue();
	display();



}
