#include <cstdio>
#include <cstdlib>

struct node{
	int data;
	node* leftChild;
	node* rightChild;
};

node* makeNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

node* sortedArrayToBst(int array[], int first, int last){

	if(first > last)
		return NULL;

	int middle = (first+last)/2;

	node* root = makeNode(array[middle]);

	root->leftChild = sortedArrayToBst(array, first, (middle - 1));

	root->rightChild = sortedArrayToBst(array, (middle+1), last);

	return root;
}

void printPreorderTraversal(node* root){
	if(root == NULL)
		return;
	printf("\n %d", root->data);

	printPreorderTraversal(root->leftChild);
	printPreorderTraversal(root->rightChild);
}
int main(){
	int arr[] = {1,2,3,4,5,6,7};
	int first = 0, last = sizeof(arr)/sizeof(arr[0]);

	int mid = (first+last)/2;

	node* root = sortedArrayToBst(arr, first, last);

	printPreorderTraversal(root);
}
