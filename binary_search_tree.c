#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node* left;
	struct Node* right;
	int data; 
}Node; 

Node* createNode(int data)
{
	Node * newnode = (Node *)malloc(sizeof(Node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = data;

	return newnode;
}

Node* searchNode(Node * Tree, int finddata)
{
	if(Tree == NULL) {
		return NULL;
	}
	if(Tree->data == finddata) {
		return Tree;
	} else if(Tree->data > finddata){
		searchNode(Tree->left , finddata);
	} else {
		searchNode(Tree->right, finddata);
	}
	return Tree;
}

void insertNode(Node * Tree, Node * newnode)
{
	if(newnode->data > Tree->data){
		if(Tree->right != NULL){
			insertNode(Tree->right, newnode);
		} else {
			Tree->right = newnode;
		}
	} else if(newnode->data < Tree->data) {
		if(Tree->left != NULL){
			insertNode(Tree->left, newnode);
		} else {
			Tree->left = newnode;
		}
	}
}

Node * findMinNode(Node * Tree)
{
	if(Tree == NULL) return NULL;
	
	if(Tree->left != NULL) {
		return findMinNode(Tree->left);
	} else {
		return Tree;
	}
}

Node * removeNode(Node * Tree, int data)
{
	Node * tmp_node;
	if(Tree == NULL){
		printf("not search node!\n");
	} else if(Tree->data > data) {
		Tree->left = removeNode(Tree->left, data); 
	} else if(Tree->data <  data) {
		Tree->right = removeNode(Tree->right, data); 
	} else {
		if(Tree->left != NULL && Tree->right != NULL){
			tmp_node = findMinNode(Tree->right);
			Tree->data = tmp_node->data;

			Tree->right = removeNode(Tree->right, tmp_node->data);
		} else {
			tmp_node = Tree;
			if(Tree->left == NULL) {
				Tree = Tree->right;
			} else if(Tree->right == NULL) {
				Tree = Tree->left;
			}
			free(tmp_node);
		}
	}
	return Tree;
}

void print_tree(Node * Tree)
{
	if(Tree == NULL) return;
	print_tree(Tree->left);
	printf("%d ",Tree->data);
	print_tree(Tree->right);
}

int main(void)
{
	Node * Tree = createNode(0);
	Node * find_node = NULL;
	int input;

	insertNode(Tree, createNode(5));
	insertNode(Tree, createNode(1));
	insertNode(Tree, createNode(6));
	insertNode(Tree, createNode(17));
	insertNode(Tree, createNode(14));
	insertNode(Tree, createNode(21));
	printf("%s:%d\n",__FUNCTION__,__LINE__);

	while(1)
	{
		print_tree(Tree);
		scanf("%d", &input);
		find_node = searchNode(Tree, input);
		
		if(find_node != NULL){
			printf("serach node, node remove %p\n",find_node);
			removeNode(Tree, input);
			printf("now tree node print : ");
			print_tree(Tree);
			printf("\n");

		} else {
			printf("no search node\n");
		}
	}
	return 0;
}
