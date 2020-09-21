#include<iostream>

using namespace std;


int size = 100;
int stack[100];
int  top = -1;



void push(int data){
	if(top > size-1 ){
		cout<<"STACK OVERFLOW !!!";
	}
	else{
	top++;
	stack[top] = data;
}
	//cout<<"Element is succesfully Pushed";
}

void pop(){
	if(top < -1){
		cout<<" STACK IS EMPTY !!! ";
	}
	else{
	top--;
	cout<<" Element id succesfullu Poped ";
}
}

void display(){
	int i;
	for(i = top+1; i> -1; i--){
		cout<<stack[i]<<endl;
	}
}

int  main(){
	push(6);
	push(5);
	push(4);
	push(3);
	push(2);
	push(1);
	pop();
//	pop();
	display();
}
