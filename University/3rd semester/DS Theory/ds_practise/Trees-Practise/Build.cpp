#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * left, * right;
    Node (int d)
    {
        data=d;
        left=right=NULL;
    }
};

Node * CreateNode (int d)
{
    Node * newnode = new Node (d);
    return newnode;
}

int search (int inorder[], int curr, int s, int e)
{
    int i;
    for (i=s; i<e; i++)
    {
        if (curr == inorder[i])
            return i;
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int index = 0;

    // base case
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[index];
    index++;
    Node * node = CreateNode(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search (inorder, curr, start, end);
    node->left = buildTree(preorder, inorder, start, pos-1);
    node->right = buildTree(preorder, inorder, pos+1, end);

    return node;
}

void inorder_print(Node * root)
{
    if (root == NULL)
        return;

    inorder_print(root->left);
    cout<< root->data<<" ";
    inorder_print(root->right);    
}


int main (void)
{
    int preorder[]= {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node * root = buildTree(preorder, inorder, 0, 3);
    inorder_print(root); 
    return 0;
}