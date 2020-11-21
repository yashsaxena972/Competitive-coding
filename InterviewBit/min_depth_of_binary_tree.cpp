// Min Depth of Binary Tree
/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    // Corner case. Should never be hit unless the code is  
    // called on root = NULL 
    if (A == NULL) 
        return 0; 
  
    // Base case : Leaf Node. This accounts for height = 1. 
    if (A->left == NULL && A->right == NULL) 
        return 1; 
  
    // If left subtree is NULL, recur for right subtree 
    if (!A->left) 
        return minDepth(A->right) + 1; 
  
    // If right subtree is NULL, recur for left subtree 
    if (!A->right) 
        return minDepth(A->left) + 1; 
  
    return min(minDepth(A->left), minDepth(A->right)) + 1; 
}
