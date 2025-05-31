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

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool isBST (Node *root, int min, int max){
    // base case
    if (root == NULL)
        return true;
  
    if (root-> data >= min && root->data <= max){
        bool left = isBST (root->left, min, root->data);
        bool right = isBST (root->right, root->data, max);
        return left && right;
    }
    else
        return false;
    
}

bool validateBST(Node *root) {
    return isBST (root, INT_MIN, INT_MAX);    
}