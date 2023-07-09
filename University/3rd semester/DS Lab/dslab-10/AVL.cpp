#include<iostream>
using namespace std;

class Node
{
    public:
        int data, bf;
        Node *left, *right;

        Node(int d)
        {
            left = right = NULL;
            data = d;
            bf = 0;
        }
};

class BST
{
    public:
        Node *Rotate_right(Node *root)
        {
            Node *temp = root->left;
            Node *right_sub = temp->right;

            temp->right = root;
            root->left = right_sub;

            return temp;
        }


        Node *Rotate_left(Node *root)
        {
            Node *temp = root->right;
            Node *left_sub = temp->left;

            temp->left = root;
            root->right = left_sub;

            return temp;
        }

        Node *Create_Node(int d)
        {
            Node *newnode = new Node(d);
            return newnode;
        }
        
        int height (Node *root)
        {
	        if (root == NULL)
		        return 0;
		
	        int lst = height(root->left);
	        int rst = height(root->right);
	
	        return max (lst, rst)+1;
        }

        int balancefactor (Node *root)
        {
	        return (height(root->left)-(height(root->right)));
        }

        Node * getmin (Node * root)
        {
            while (root->left != NULL)
            {
                root = root->left;
            }

            return root;
        }

        Node *Insert_Node(Node *root, int data)
        {
            if(root == NULL)
            {
                return Create_Node(data);
            }
            else if(data < root->data)
            {
                root->left = Insert_Node(root->left, data);
            }
            else if(data > root->data)
            {
                root->right = Insert_Node(root->right, data);
            }

            root->bf = balancefactor(root);

            if(root->bf > 1)
            {
                if(data < root->left->data)
                {
                    return Rotate_right(root);
                }
                else
                {
                    root->left = Rotate_left(root->left);
                    return Rotate_right(root);
                }
            }
            else if(root->bf < -1)
            {
                if (data > root->right->data)
                {
                    return Rotate_left(root);
                }
                else
                {
                    root->right = Rotate_right(root->right);
                    return Rotate_left(root);
                }
            }

            return root; 
        } 
        
        Node *Delete_node(Node *root, int key)
        {
            if(root == NULL)
            {
                return root;
            }
            else if(key < root->data)
            {
                root->left = Delete_node(root->left, key);
            }
            else if(key > root->data)
            {
                root->right = Delete_node(root->right, key);
            }
            else
            {
                if(root->right == NULL)
                {
                    Node *temp = root;
                    root = root->left;
                    delete temp;
                }
                else if(root->left == NULL)
                {
                    Node *temp = root;
                    root = root->right;
                    delete temp;
                }
                else
                {
                    Node *temp = getmin(root->right);
                    int val = temp->data;
                    root->right = Delete_node(root->right, val);
                    root->data = val;
                }
            }

            if(root == NULL)
            {
                return root;
            }

            root->bf = balancefactor(root);

            if(root->bf < -1)
            {
                if(balancefactor(root->right) <= 0)
                {
                    return Rotate_left(root);
                }
                else
                {
                    root->right = Rotate_right(root->right);
                    return Rotate_left(root);
                }
            }
            else if(root->bf > 1)
            {
                if(balancefactor(root->left) >= 0)
                {
                    return Rotate_right(root);
                }
                else
                {
                    root->left = Rotate_left(root->left);
                    return Rotate_right(root);
                }
            }

            return root;
        }

        void preorder(Node *root)
        {   
            if(root == NULL)
            {
                return;
            }
            else
            {
                cout << root->data << " -> ";

                preorder(root->left);
                preorder(root->right);
            }
        }

        void inorder(Node *root)
        {
            if(root == NULL)
            {
                return;
            }
            else
            {
                inorder(root->left);

                cout << root->data << " -> ";

                inorder(root->right);
            }
        }

        void postorder(Node *root)
        {
            if(root == NULL)
            {
                return;
            }
            else
            {
                postorder(root->left);
                postorder(root->right);

                cout << root->data << " -> ";
            }
        }
};

int main()
{
    BST b1;
    Node * Root=NULL;
// Part a.
    Root = b1.Insert_Node(Root, 1); Root = b1.Insert_Node(Root, 2); Root = b1.Insert_Node(Root, 3);
    b1.preorder(Root);

    cout << endl << endl;

// Part b.
    Root = b1.Delete_node(Root, 2);
    b1.preorder(Root);

    cout << endl << endl;

// Part c.
    Root = b1.Insert_Node(Root, 4); Root = b1.Insert_Node(Root, 5); Root = b1.Insert_Node(Root, 6);
    Root = b1.Insert_Node(Root, 7); Root = b1.Insert_Node(Root, 8);
    b1.postorder(Root);

// Part d.
    Root = b1.Delete_node(Root, 8); Root = b1.Delete_node(Root, 5);

// Part e.
    cout << endl << endl << "In-order Traveral: " << endl;
    b1.inorder(Root);
    cout << endl << endl;

    cout << "Pre-order Traveral: " << endl;
    b1.preorder(Root);
    cout << endl << endl;

    cout << "Post-order Traveral: " << endl;
    b1.postorder(Root);

    return 0;
}