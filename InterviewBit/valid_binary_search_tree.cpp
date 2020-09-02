// Valid Binary Search Tree
/*

Given a binary tree, determine if it is a valid binary search tree (BST).

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
 
/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(TreeNode* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->val < min || node->val > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->val-1) && // Allow only distinct values  
        isBSTUtil(node->right, node->val+1, max); // Allow only distinct values  
}  
 
int Solution::isValidBST(TreeNode* A) {
    return(isBSTUtil(A, INT_MIN, INT_MAX)); 
}
