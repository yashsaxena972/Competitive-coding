// Sorted Array To Balanced BST

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* A function that constructs Balanced 
Binary Search Tree from a sorted array */
TreeNode* makeBST(vector<int> A, int start, int end)  
{  
    /* Base Case */
    if (start > end)  
        return NULL;  
  
    /* Get the middle element and make it root */
    int mid = start + (end - start)/2;  
    TreeNode *root = new TreeNode(A[mid]);  
  
    /* Recursively construct the left subtree  
    and make it left child of root */
    root->left = makeBST(A, start, mid - 1);  
  
    /* Recursively construct the right subtree  
    and make it right child of root */
    root->right = makeBST(A, mid + 1, end);  
  
    return root;  
} 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    return makeBST(A,0,n-1);
    
}
