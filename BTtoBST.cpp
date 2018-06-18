/*
 * BSTFromPreOrder.cpp
 *
 *  Created on: 17-Jun-2018
 *      Author: Sahil S
 */

#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;
struct node{
	int data;
	node* leftChild;
	node* rightChild;
};

node* newNode(int newData){
	node* newNode = new node();
	newNode->data = newData;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

int countNodes(node* root){
	if(root == NULL)
		return 0;

	return (countNodes(root->leftChild) + countNodes(root->rightChild) + 1);

}
void inOrder(node* root,int* array, int* arrPtr){
	if(root != NULL){
		inOrder(root->leftChild, array, arrPtr);
		array[*arrPtr] = root->data;
		(*arrPtr)++;
		inOrder(root->rightChild, array, arrPtr);
	}
}
int compare(const void* a,const void* b){
	return (*(int*)a - *(int*)b);
}

void arrayToBST(int *arrayPtr, node* root, int* indexPtr){
	if(root == NULL)
		return;

	arrayToBST(arrayPtr,root->leftChild,indexPtr);

	root->data = arrayPtr[*indexPtr];
	(*indexPtr)++;

	arrayToBST(arrayPtr,root->rightChild,indexPtr);
}


/* Utility function to print inorder traversal of Binary Tree */
void printInorder (node* root)
{
    if (root == NULL)
        return;

    printInorder (root->leftChild);
    printf("%d ", root->data);
    printInorder (root->rightChild);
}
void binaryTreeToBST(node* root){
	int n = countNodes(root);

	int array[n];
	int i = 0;
	inOrder(root,array,&i);

	printf("InOrder \n");
	for (int i =0;i<n;i++)
		printf("\n Key %d", array[i]);

	qsort(array, n, sizeof(array[0]),compare);

	printf("\n After Sorting");
	for (int i =0;i<n;i++)
		printf("\n Key %d", array[i]);

	i = 0;
	arrayToBST(array, root, &i);

	printInorder(root);

}

int main_BTtoBST(){
	node *root;

	root = newNode(10);
	root->leftChild = newNode(30);
	root->rightChild = newNode(5);
	root->leftChild->leftChild = newNode(45);
	root->rightChild->rightChild = newNode(3);

	binaryTreeToBST(root);
}
