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

bool isBST(node * root, int min, int max)
{
	
	if (root == NULL)
	{
		return true;
	}
	
	
	if (root->data > max || root->data < min)
	{
		return false;
	}
	
	bool leftvalid = isBST (root->left, min, root->data);
	bool rightvalid = isBST (root->right, root->data, max);
	
	
	return leftvalid && rightvalid;
}


void AutoGrader(node * root)
{
	cout<< endl;
	if (isBST(root, INT_MIN, INT_MAX))
	{
		cout<< "10 points.";
	}
	else
	{
		cout<<"0 points.";
	}
	
}



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

int main (void)
{
	node * root = new node (5);
	root-> right = new node (7);
	root-> right->left = new node (6);
	
	root->left = new node (2);
	root->left->right = new node (3);
	root->left->left = new node (1);
	
	inorder(root);
	
	AutoGrader (root);
}
