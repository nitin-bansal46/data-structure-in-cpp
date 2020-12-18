#include<iostream>
#include<cstdlib>

using namespace std;

struct Node{

	int data;
	Node* left_child;
	Node* right_child;
	int height ;
};

Node* root = NULL;

 
int height(Node* curNode){
	if(curNode == NULL){
		return 0;
	}
	return curNode->height;
}

int max(int a, int b){
	return (a>b) ? a : b;
}


//Node *newNode(int data) {
//  Node *node = new Node();
//  node->data = data;
//  node->left_child = NULL;
//  node->right_child = NULL;
//  node->height = 1;
//  return (node);
//}


Node* leftRotation(Node* x){
	
	cout<<"\nLeft Rotation on : "<<x->data<<endl;

	Node* y = x->right_child;
	Node* temp2 = y->left_child;

	y->left_child = x;
	x->right_child = temp2;
		
	x->height = max(height(x->left_child), height(x->right_child)) + 1;
	y->height = max(height(y->left_child), height(y->right_child)) + 1;
	
	return y;
	}
	
Node* rightRotation(Node* y){
	
	cout<<"\nRight Rotation on : "<<y->data<<endl;

	Node* x = y->left_child;
	Node* temp2 = x->right_child;

	x->right_child = y;
	y->left_child = temp2;
	
	
	x->height = max(height(x->left_child), height(x->right_child)) + 1;
	y->height = max(height(y->left_child), height(y->right_child)) + 1;

	return x;
}
int balanceFactor(Node* curNode){
	if(curNode == NULL)
		return 0;
else{

	return height(curNode->left_child) - height(curNode->right_child);
}}

Node* newNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->height = 1;
	
	return temp;
}


Node* insertNode(Node* node, int data){

	if (node == NULL){
		return newNode(data);
	}
	if(data < node->data){
		node->left_child = insertNode(node->left_child, data);

	}else if(data > node->data){
		node->right_child = insertNode(node->right_child, data);
	}
	else{
		return node;
	}

// if(data < node->data){
//		if(node->left_child != NULL){
//			insertNode(node->left_child, data);
//		}
//		else{
//			node->left_child = temp;
//		}
//	}
//	else if(data > node->data){
//		if(node->right_child != NULL){
//			insertNode(node->right_child, data);
//		}
//		else{
//			node->right_child = temp;
//		}
//	}
//	else{
//		return node;
//	}

	node->height = max(height(node->left_child), height(node->right_child)) + 1;
	
	int balance = balanceFactor(node);

	if(balance > 1){
		if(data < node->left_child->data){
		cout<<"Case : LL Doing Right Rotations ";
		return rightRotation(node);
		}
	    else if(data > node->left_child->data){
		cout<<"Case : LR Doing Left-->Right Rotations";
		node->left_child = leftRotation(node->left_child);
		return rightRotation(node);
	    }
	}
	if(balance < -1){
		
		if(data > node->right_child->data){
		cout<<"Case : RR Doing Left Rotations ";
		return leftRotation(node);
		}
		else if ( data < node->right_child->data){
		cout<<"Case : RL Doing Right-->Left Rotations ";
		node->right_child = rightRotation(node->right_child);
		return  leftRotation(node);
	}
}
 return node;
}


void insert(int data){
	
	root = insertNode(root, data);

}

void printTree(Node *root, string indent, bool last) {
  if (root != NULL) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->data << endl;
    printTree(root->left_child, indent, false);
    printTree(root->right_child, indent, true);
  }
}
void inOrder(Node* root){
	if(root != NULL){
		inOrder(root->left_child);
		cout<<root->data<<endl;
		inOrder(root->right_child);
	}
}

void preOrder(Node* root){
	if(root != NULL){
		cout<<root->data<<endl;
		preOrder(root->left_child);
		preOrder(root->right_child);
	}
}


int main(){
//	Node* root = NULL;

	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
//	insert(-2);
//	inOrder(root);
//	printTree(root, "", true);
	preOrder(root);

}
