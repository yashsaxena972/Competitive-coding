// Path to Given Node
/*

Given a Binary Tree A containing N nodes.
You need to find the path from Root to a given node B.

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Output
 [1, 2, 5]

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
 
bool hasPath(TreeNode *root, vector<int>& arr, int x){ 
    if (!root) 
        return false; 
    arr.push_back(root->val);     

    if (root->val == x)     
        return true; 
      
    if (hasPath(root->left, arr, x) || 
        hasPath(root->right, arr, x)) 
        return true; 
        
    arr.pop_back(); 
    return false; 
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    hasPath(A,ans, B);
    return ans;
}
