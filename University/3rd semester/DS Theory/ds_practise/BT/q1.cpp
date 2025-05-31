#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* constructMaximumBinaryTree(int* nums, int n) {
    // base case: if the input array is empty, return null
    if (n == 0) return nullptr;

    // find the index of the maximum value in the array
    int max_index = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[max_index]) max_index = i;
    }

    // create a new root node with the maximum value
    TreeNode* root = new TreeNode(nums[max_index]);

    // split the array into two subarrays: the prefix to the left of the maximum value,
    // and the suffix to the right of the maximum value
    int* left_subarray = nums;
    int left_size = max_index;
    int* right_subarray = nums + max_index + 1;
    int right_size = n - max_index - 1;

    // recursively build the left and right subtrees
    root->left = constructMaximumBinaryTree(left_subarray, left_size);
    root->right = constructMaximumBinaryTree(right_subarray, right_size);

    return root;
  }
};

int main() {
  // test the solution
  int nums[] = {3, 2, 1};
  int n = 3;
  Solution solution;
  TreeNode* root = solution.constructMaximumBinaryTree(nums, n);
  cout << root->val << endl; // should print 3
  cout << root->left->val << endl; // should print 2
  cout << root->right->val << endl; // should print 1
  return 0;
}
