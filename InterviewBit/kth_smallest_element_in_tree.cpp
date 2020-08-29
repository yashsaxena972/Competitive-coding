// Kth Smallest Element In Tree
// Given a binary search tree, write a function to find the kth smallest element in the tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inorder(TreeNode* root, int& smallest, int k, int& it)
{
    if (!root){
        return;
    }
        
    inorder(root->left, smallest, k, it);
    ++it;
    if (it == k)
    {
        smallest = root->val;
        return;
    }
    inorder(root->right, smallest, k, it);
} 
 
int Solution::kthsmallest(TreeNode* A, int B) {
    int smallest = -1;
    int it = 0;
    inorder(A, smallest, B, it);
    return smallest;
}
