#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

struct Node{
	int data;
	Node *left_child ;
	Node *right_child;
};

Node *root = NULL;


void insertNode(Node *node, int data){
	Node *temp = new Node();
	temp->data = data;
	

	if(data < node->data){
		if(node->left_child != NULL){
			insertNode(node->left_child, data);
		}
		else{
			node->left_child = temp;
		}
	}
	else{
		if(node->right_child != NULL){
			insertNode(node->right_child, data);
		}
		else{
			node->right_child = temp;
		}
	}
}
void insert(int data){
	Node *temp = new Node();
	temp->data = data;
	if(root == NULL){
		root = temp;
		}
	else{
		insertNode(root,data);
	}
}

int heightRecurssive(Node* root){
	if(root == NULL)
		return 0;

	else{
		int lheight = heightRecurssive(root->left_child);
		int rheight = heightRecurssive(root->right_child);

		if(lheight > rheight)
			return lheight + 1;
		else
			return rheight + 1;

	}
}
int heightIterative(Node* root){

	if(root == NULL){
		return 0;
}


	queue<Node*>  q;

	q.push(root);
	int height = 0;

	while(1){
		int nodeCount = q.size();
		if(nodeCount == 0)
			return height;

		height++;


	while(nodeCount > 0){
		Node *node = q.front();
		q.pop();

		if(node->left_child != NULL)
			q.push(node->left_child);
		if(node->right_child != NULL)
			q.push(node->right_child);

		nodeCount--;
		}
	}
}

void preOrder(Node* root){
	if(root!= NULL){
		cout<<root->data;
		preOrder(root->left_child);
		preOrder(root->right_child);
	}
}

void inOrder(Node* root){
	if(root != NULL){
		inOrder(root->left_child);
		cout<<root->data;
		inOrder(root->right_child);
	}
}

void postOrder(Node* root){
	if(root != NULL){
		postOrder(root->left_child);
		postOrder(root->right_child);
		cout<<root->data;
	}
}

void printLevelData(Node *root, int level){
	if(root == NULL)
		return;

	if(level == 1)
		cout<<root->data;

	else if(level > 1){
		printLevelData(root->left_child, level-1);
		printLevelData(root->right_child, level-1);
	}

}
void levelOrder(Node* root){
	
	int n = heightRecurssive(root);


	for(int i = 1; i<= n; i++){
		printLevelData(root, i);
	}
}



int find(Node* root, int val){
	int temp;

if(root == NULL){

		return 0;
	}
	else{
	if(root->data == val ){
		cout<<"Data found ";
		return 1;
		}
	else{
		temp = find(root->left_child,val);
		if(temp != 0){
			return temp;
			}
		else{
            return find(root->right_child,val);
		}
        }
	}
}

int min(Node* curNode){
	if(curNode->left_child != NULL){
		return min(curNode->left_child);
	}
	return curNode->data;
}
int getMin(Node* root){
	if(root != NULL){
		return min(root);
	}
}


int max(Node* curNode){
	if(curNode->right_child != NULL){
		return max(curNode->right_child);
		}
		return curNode->data;
}
int getMax(Node *root){
	if(root != NULL)
	return max(root);
}



int size(Node *root){
	if(root == NULL){
		return 0;
	}
	else{
		return size(root->left_child) + 1 + size(root->right_child);
	}
}

Node* removeNode(Node* root, int data){
	if (root == NULL){

		return NULL;
}
	if(data < root->data){
		root->left_child = removeNode(root->left_child, data);
	}
	else if(data > root->data){
		root->right_child = removeNode(root->right_child, data);
	}
	
	else{
		
		if(root->left_child == NULL && root->right_child == NULL){
			cout<<"Removing a leaf node...";
            delete(root);
            root = NULL;

			}
			
		else if(root->left_child == NULL){
			cout<<"Removing a node with only right child...";
			Node* temp = root;
			root = root->right_child;
			delete(temp);

		}
		
		else if(root->right_child == NULL){
			cout<<"Removing a node with only left child...";
			Node* temp = root;
			root = root->left_child;
			delete(temp);

		}
		else{
			cout<<"Removing node having both child...";
			
			int temp = getMin(root->right_child);
			root->data = temp;
			root->right_child = removeNode(root->right_child, temp);
		}
	}
		return root;
}


int main(){


	insert(5);
	insert(4);
	insert(1);
	insert(7);
	insert(6);
	insert(8);

	preOrder(root);
	cout<<endl;
//	inOrder(root);
//    cout<<endl;
//	postOrder(root);
//	cout<<endl;
//	levelOrder(root);
//cout<<endl;
//levelOrder(root);

//find(root,8);
//cout<<getMax(root)<<endl;

//cout<<getMin(root);

//cout<<size(root);
//cout<<heightIterative(root);
//cout<<heightRecurssive(root);

//cout<<endl;
preOrder(removeNode(root,5));

}





