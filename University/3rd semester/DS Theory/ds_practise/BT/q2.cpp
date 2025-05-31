#include <iostream>
#include <vector>
using namespace std;

class node
{
    
public:
    int data;
    node *left = NULL, *right = NULL;
    node(int data) : data(data), left(NULL), right(NULL){};
};

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }
    else
    {
        if (data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

void storeinorder(node *root, vector<int> *temp)
{
    if (root != NULL)
    {
        storeinorder(root->left, temp);
        temp->push_back(root->data);
        storeinorder(root->right, temp);
    }
}

bool test(node *root)
{
    vector<int> temp;
    storeinorder(root, &temp);
    for (int i = 0; i < temp.size() - 1; i++)
    {
        if (temp[i] > temp[i + 1])
            return false;
    }
    return true;
}

int main()
{
    node *root = NULL;
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 65);
    root = insert(root, 70);
    root = insert(root, 55);
    root = insert(root, 80);

    cout << "Binary Search Tree created (Inorder traversal): ";
    inorder(root);
    cout << endl;

    if (test(root))
        cout
            << "The tree is BST";
    else
        cout << "The tree is not BST";

    node *tree = new node(10);
    tree->left = new node(5);
    tree->left->left = new node(3);
    tree->left->right = new node(11);
    tree->right = new node(13);
    tree->right->left = new node(8);
    tree->right->right = new node(15);

    cout << endl;
    cout << "\nSecond tree inorder:";
    inorder(tree);
    cout << endl;

    if (test(tree))
        cout
            << "The tree is BST";
    else
        cout << "The tree is not BST";

    return 0;
}