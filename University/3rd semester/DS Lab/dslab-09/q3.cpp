#include <iostream>
using namespace std;

class node {
	public:
		int data;
		node * right;
		node * left;
		node (int d)
		{
			data = d;
			right = NULL;
			left = NULL;
		}
		
};


void inorder (node * root)
{
	if (root == NULL)
	{
		return; 
	}
	
	inorder(root->left);
	cout<< root->data<<" ";
	inorder(root->right);
}

void preorder (node * root)
{
	if (root == NULL)
	{
		return; 
	}
	
	cout<< root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}

int main (void)
{
	node * root = new node (5);
	root-> right = new node (7);
	root-> right->left = new node (6);
	
	root->left = new node (2);
	root->left->right = new node (3);
	root->left->left = new node (1);
	
	cout<<"In order traversal: ";
	inorder(root);
	cout<<endl<<"Pre order traversal: ";
	preorder(root);
	
}






//	              15
//	            /   \
//	           10    20
//			  / \    / \
//			 8  12  18  25
