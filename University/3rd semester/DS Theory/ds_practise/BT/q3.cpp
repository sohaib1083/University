#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class soln {
public:
  void recoverTree(TreeNode* root) {
    // inorder traverse the BST and store the values of the nodes in an array
    int values[10000];
    int index = 0;
    inorderTraverse(root, values, index);

    // find the two elements in the array that are out of order
    int first = -1, second = -1;
    for (int i = 0; i < index - 1; i++) {
      if (values[i] > values[i + 1]) {
        if (first == -1) {
          first = i;
        } else {
          second = i + 1;
          break;
        }
      }
    }

    // find the nodes in the BST that correspond to the two elements that were swapped
    TreeNode* first_node = nullptr;
    TreeNode* second_node = nullptr;
    findNodes(root, values[first], values[second], first_node, second_node);

    // swap the values of the two nodes
    int temp = first_node->val;
    first_node->val = second_node->val;
    second_node->val = temp;
  }

private:
  // inorder traverse the BST and store the values of the nodes in an array
  void inorderTraverse(TreeNode* node, int* values, int& index) {
    if (!node) return;
    inorderTraverse(node->left, values, index);
    values[index++] = node->val;
    inorderTraverse(node->right, values, index);
  }

  // find the nodes in the BST that correspond to the given values
  void findNodes(TreeNode* node, int first_value, int second_value, TreeNode*& first_node, TreeNode*& second_node) {
    if (!node) return;
    if (node->val == first_value) {
      first_node = node;
    } else if (node->val == second_value) {
      second_node = node;
    }
    findNodes(node->left, first_value, second_value, first_node, second_node);
    findNodes(node->right, first_value, second_value, first_node, second_node);
  }
};

int main() {
  // test the solution
  TreeNode* root = NULL;// construct the BST here
  soln s;
  s.recoverTree(root);
  return 0;
}
