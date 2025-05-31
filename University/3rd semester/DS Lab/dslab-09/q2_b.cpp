#include <iostream>
using namespace std;

class node {
	public:
		int key;
		node * right;
		node * left;
		node (int d)
		{
			key = d;
			right = NULL;
			left = NULL;
		}	
};

void inorder (node * root);

class BinaryTree{
	private:
		node * root;
	public:
		void AddNode (int key)
		{
			node * newnode = new node (key);
			
			if (root == NULL)
			{
				root = newnode;
			}
			else
			{
				node * parent;
				node * child = root;
				
				while (child != NULL)
				{
					parent = child;
					if ( newnode->key > parent->key){
						child = child->right;
					}
					else if ( newnode->key < parent->key){
						child = child->left;
					}
				}
				
				

				if ( newnode->key > parent->key){
					parent->right = newnode;
				}
				else if ( newnode->key < parent->key){
					parent->left= newnode;
				}
			}
		}
		void display ()
		{
			inorder(root);
		}
};


void inorder (node * root)
{
	if (root == NULL)
	{
		return; 
	}
	
	inorder(root->left);
	cout<< root->key<<" ";
	inorder(root->right);
}

int main (void)
{
	BinaryTree BT;	
	int BST[7] = { 15, 10, 20, 8, 12, 16, 25 };
	
	for (int i=0; i<7; i++)
		BT.AddNode(BST[i]);
		
	BT.display();
}
