// Path Sum
/*  
Given a tree and a sum, return true if there is a path from the root  
down to a leaf, such that adding up all the values along the path  
equals the given sum. 
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
 
/*  
Strategy: subtract the node value from the sum when recurring down,  
and check to see if the sum is 0 when you run out of tree.  
*/ 
 
int Solution::hasPathSum(TreeNode* A, int B) {
    /* return true if we run out of tree and sum==0 */
    if (A == NULL)  
    {  
        return (B == 0);  
    }  
      
    else
    {  
        bool ans = 0;  
      
        /* otherwise check both subtrees */
        int subSum = B - A->val;  
      
        /* If we reach a leaf node and sum becomes 0 then return true*/
        if ( subSum == 0 && A->left == NULL && A->right == NULL )  
            return 1;  
      
        if(A->left)  
            ans = ans || hasPathSum(A->left, subSum);  
        if(A->right)  
            ans = ans || hasPathSum(A->right, subSum);  
      
        return ans;  
    } 
}
