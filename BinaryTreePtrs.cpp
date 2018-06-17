/*
 * BinaryTreePtrs.cpp
 *
 *  Created on: 16-Jun-2018
 *      Author: Sahil S
 */
#include <cstdlib>
#include <cstdio>
using namespace std;

struct node{
	int data;
	node* leftChild;
	node* rightChild;
};

node* createNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

// insert recursively
node* insert(node* root, int data){
	if(root == NULL) return createNode(data);

	if(data < root->data)
		root->leftChild = insert(root->leftChild, data);
	else if (data > root->data)
		root->rightChild = insert(root->rightChild, data);

	return root;
}
//InOrder - Left SubTree. Key. Right Subtree
void inOrder(node* root){

	if(root!=NULL){
		inOrder(root->leftChild);
		printf("Key %d \n", root->data);
		inOrder(root->rightChild);
	}
}

//PreOrder : Root, LeftSubtree, RightSubtree
void preOrder(node* root){
	if(root != NULL){
		printf("\n Key %d",root->data);
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}

//PostOrder : Left Subtree, Right Subtree, Root

void postOrder(node* root){
	if(root != NULL){
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		printf("\n Key %d", root->data);
	}
}
node* minValueNode(node* root){
	node* current = root;
	while(current->leftChild != NULL)
		current = current->leftChild;

	return current;
}
//deletion recursively
//3 cases: 1) Left/Right Single Leaf Node. 2) No Child 3) Two childs
node* deletion(node* root,int key){
	if(root == NULL) return root;

	if(key < root->data)
		root->leftChild = deletion(root->leftChild, key);
	else if(key > root->data)
		root->rightChild = deletion(root->rightChild, key);

	else{ //root->data == key
		//If only one child or no child
		if(root->leftChild == NULL){
			node* temp = root->rightChild;
			delete root->rightChild;
			root->rightChild = NULL;
			return temp;
		}
		else if(root->rightChild == NULL){
			node* temp = root->leftChild;
			delete root->leftChild;
			root->leftChild = NULL;
			return temp;
		}
		//deletion of a node with two children
		node* temp = minValueNode(root->rightChild);
		root->data = temp->data;
		//delete the inorder successor
		root->rightChild = deletion(root->rightChild,temp->data);
	}
	return root;
}
//search recursively
node* search(node* root, int key){
	if(root == NULL || root->data == key)
		return root;

	if(key < root->data)
		return search(root->leftChild, key);
	else
		return search(root->rightChild,key);

}

//driver function
int main(){
	node* root = createNode(8);
	insert(root,6);
	insert(root,13);
	insert(root,7);
	insert(root,11);
	insert(root,6);
	insert(root,10);
	insert(root,3);
	insert(root,4);
	insert(root,1);

	inOrder(root);
	root = deletion(root,3);
	inOrder(root);

	node *found = search(root,13);
	printf("\n Key, LeftChild %d %d ",found->data, found->leftChild->data);
	//preOrder(root);
	//postOrder(root);
	return 0;
}
