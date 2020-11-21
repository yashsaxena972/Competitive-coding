// 2-Sum Binary Tree
/*

Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

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

map<int,int>m;
int f=0; 

void solve(TreeNode* root,int b){
    if(root==NULL){
        return;
    }
    
    solve(root->left,b);
    m[root->val]=1;
    if(m[b-(root->val)] && (root->val!=(b-(root->val)))){
        f=1;
    }
    solve(root->right,b);
}
 
int Solution::t2Sum(TreeNode* A, int B) {
    m.clear();
    f=0;
    solve(A,B);
    return f;
}
