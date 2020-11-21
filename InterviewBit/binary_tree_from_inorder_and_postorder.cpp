// Binary Tree From Inorder And Postorder
/*

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

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
 
int findIndex(vector<int>& inorder, int i, int j, int val)
{
    for (auto b = i; b<=j; ++b)
        if (inorder[b] == val)
            return b;
}

TreeNode* makeTree(vector<int> &inorder, vector<int> &postorder, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    TreeNode* node = new TreeNode(postorder[p--]);
    if (i==j)
        return node;
    int in = findIndex(inorder, i, j, node->val);
    node->right = makeTree(inorder, postorder, in+1, j, p);
    node->left = makeTree(inorder, postorder, i, in-1, p);
    return node;
} 
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int p = B.size()-1;
    return A.empty() ? NULL : makeTree(A, B, 0, A.size()-1, p);
}
