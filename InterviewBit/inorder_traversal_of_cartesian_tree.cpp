// Inorder Traversal of Cartesian Tree
/*

Given an inorder traversal of a cartesian tree, construct the tree.
Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1

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

int findMax(vector<int> &A, int start, int end){
    int max = A[start];
    int index = start;
    for(int i = start; i <= end; i++){
        if(max < A[i]){
            max = A[i];
            index = i;
        }
    }
    return index;
}  
 
TreeNode* makeCart(vector<int> &A, int start, int end){
    if(start > end){
        return NULL;
    }
    
    int maxIn = findMax(A, start, end);
    
    TreeNode* root = new TreeNode(A[maxIn]);
    
    root->left = makeCart(A, start, maxIn-1);
    root->right = makeCart(A, maxIn+1, end);
    
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    return makeCart(A, 0, A.size()-1);
}
