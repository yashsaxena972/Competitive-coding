// Root to Leaf Paths With Sum
/*

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
 
void putSum(TreeNode* root, vector<vector<int> >& sol, int sum, vector<int>& v){
    if(sum == 0 && root->left == NULL && root->right == NULL){
        sol.push_back(v);
    }
    
    if(root->left != NULL){
        v.push_back((root->left)->val);
        putSum(root->left, sol, sum - (root->left)->val, v);
        v.pop_back();
    }
    
    if(root->right != NULL){
        v.push_back((root->right)->val);
        putSum(root->right, sol, sum - (root->right)->val, v);
        v.pop_back();
    }
    
} 
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > sol;
    vector<int> v;
    
    if(A == NULL){
        return sol;
    }
    
    v.push_back(A->val);
    
    putSum(A, sol, B - A->val, v);
    
    return sol;
}
