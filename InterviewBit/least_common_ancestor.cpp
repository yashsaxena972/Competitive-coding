// Least Common Ancestor
/*

Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

Please note that LCA for nodes 5 and 4 is 5.

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
 
// Finding common node using recursion
bool find(TreeNode* root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if ((root->left && find(root->left, val)) || 
        (root->right && find(root->right, val)))
        return true;
    return false;
}

TreeNode* LCA(TreeNode* root, int val1, int val2)
{
    if (!root || root->val == val1 || root->val == val2)
        return root;
    
    auto L = LCA(root->left, val1, val2);
    auto R = LCA(root->right, val1, val2);
    
    if (L && R)
        return root;
    return L ? L : R;
}
 
int Solution::lca(TreeNode* A, int B, int C) {
    if (!find(A, B) || !find(A, C))
        return -1;
    auto ancestor = LCA(A, B, C);
    if (ancestor)
        return ancestor->val;
    return -1;
    
}
