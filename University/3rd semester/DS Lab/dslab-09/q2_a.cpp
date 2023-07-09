#include <iostream>
using namespace std;

class node {
	public:
		int key;
		string name;
		node * right;
		node * left;
		node (int d, string n)
		{
			name = n;
			key = d;
			right = NULL;
			left = NULL;
		}	
};

class BinaryTree{
	private:
		node * root;
	public:
		void AddNode (int key, string name)
		{
			node * newnode = new node (key, name);
			
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
};


int main (void)
{
	return 0;
}
