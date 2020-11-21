// Remove Half Nodes
/*

Given a binary tree A with N nodes.
You have to remove all the half nodes and return the final binary tree.
NOTE:
Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.

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
TreeNode* Solution::solve(TreeNode* A) {
    if(A==NULL)
        return NULL;
    
    A->left = solve(A->left);
    A->right = solve(A->right);
    
    if(A->left==NULL&&A->right==NULL)
        return A;
    if(!A->left){
        TreeNode* node = A->right;
        free(A);
        return node;
    }
    if(!A->right){
        TreeNode* node = A->left;
        free(A);
        return node;
    }
    return A;
}
