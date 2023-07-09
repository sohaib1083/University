#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(){
        left = right = NULL;
    }
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

class BinarySearchTree{
private:
    Node *nodes;
    Node* root;
public:
    BinarySearchTree(){
        root = nodes = NULL;
    }
    void insertNode(int data){
        nodes = new Node(data);
        Node *current = root;
        Node* parent = NULL;
        while(current != NULL)
		{
            parent = current;
            if(data<current->data){
                current  = current->left;
            }
			else{
                current = current->right;
            }
        }
        if(parent == NULL){
            root = nodes;
        }
		else if(parent->data > data){
            parent->left = nodes;
        }
		else{
            parent->right = nodes;
        }
        current = nodes;
    }
    
    Node* InorderSuccessor(Node* curr)
	{
        while(curr && curr->left != NULL){
            curr = curr->left;
        }
        return curr;
    }
    
	void deleteRange(int start,int end)
	{
        for(int i=start;i<=end;i++){
            root = deleteNode(root,i);
        }
    }
    
    Node* deleteNode(Node* root, int data)
	{
        if(root == NULL)
		{
            return root;
        }
		else
		{
            if(root->data < data){
                root->right =  deleteNode(root->right,data);
            }
			else if(root->data> data){
                root->left =  deleteNode(root->left,data);
            }
			else{
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    root = NULL;
                    return root;
                }
				else if(root->left == NULL && root->right != NULL){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
				else if(root->right == NULL && root->left != NULL){
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }
				else
				{
                    Node* temp = InorderSuccessor(root->right);
                    int tempd = root->data;
                    root->data = temp->data;
                    temp->data = tempd;
                    root->right = deleteNode(root->right,temp->data);
                }
            }
        }
        return root;
    }
    void callInOrder(){
        inOrderTraversal(root);
    }
    
    void inOrderTraversal(Node *root){
        if (root == NULL){
            return;
        }
        inOrderTraversal(root->left);
        cout << root->data << endl;
        inOrderTraversal(root->right);
    }
};

int main(){
    BinarySearchTree BST;
    BST.insertNode(15);
    BST.insertNode(10);
    BST.insertNode(20);
    BST.insertNode(8);
    BST.insertNode(12);
    BST.insertNode(18);
    BST.insertNode(25);
    

    BST.callInOrder();
    BST.deleteRange(8, 12);
    
    cout<< "after deletion: "<< endl;
    BST.callInOrder();
}

//	              15
//	            /   \
//	           10    20
//			  / \    / \
//			 8  12  18  25

