// Construct Binary Tree From Inorder And Preorder
/*

Given preorder and inorder traversal of a tree, construct the binary tree.
Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3

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
 
int findIndex(vector<int> &inorder, int i, int j, int val)
{
    for (auto b = i; b<=j; ++b)
        if (inorder[b]==val)
            return b;
}

TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    TreeNode* node = new TreeNode(preorder[p++]);
    if (i==j)
        return node;
    int in = findIndex(inorder, i, j, node->val);
    node->left = makeTree(preorder, inorder, i, in-1, p);
    node->right = makeTree(preorder, inorder, in+1, j, p);
    return node;
} 
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if (A.empty() || B.empty()){
        return NULL;
    }
        
    int p = 0;
    return makeTree(A, B, 0, B.size()-1, p);
}
